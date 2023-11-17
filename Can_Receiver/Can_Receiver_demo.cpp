#include <iostream>
#include <string>
#include <cstring>
#include <unistd.h>
#include <linux/can.h>
#include <linux/can/raw.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <fcntl.h>
#include <cmath>
#include <netinet/in.h>  // Header file for TCP socket programming
#include <arpa/inet.h>  // Header file for inet_pton
#include <nlohmann/json.hpp>

const std::string CAN_INTERFACE = "can0";
const int RPM_CAN_ID = 0x100;
const double WHEEL_DIAMETER_CM = 0.035;

const std::string VSOMEIP_SERVER_IP = "127.0.0.1";  // Replace with your VSOME/IP server IP
const int VSOMEIP_SERVER_PORT = 12345;  // Replace with your VSOME/IP server port

int openPort(const char *port);
void readPort(int can_soc, int vsomeip_soc);
void closePort(int soc);
int connectToVsomeIpServer();

// Function to open the CAN port
int openPort(const char *port) {
    int soc = socket(PF_CAN, SOCK_RAW, CAN_RAW);  // Create a new CAN socket
    if (soc < 0) {
        perror("Failed to create socket");
        return -1;
    }

    struct sockaddr_can addr;  // Socket address structure for CAN
    struct ifreq ifr;  // Interface request structure for CAN

    strcpy(ifr.ifr_name, port);  // Set the interface name

    // Get the interface index using ioctl
    if (ioctl(soc, SIOCGIFINDEX, &ifr) < 0) {
        perror("Failed to get interface index");
        close(soc);
        return -1;
    }

    addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;

    // Set socket to non-blocking mode
    fcntl(soc, F_SETFL, O_NONBLOCK);

    // Bind the socket to the CAN interface
    if (bind(soc, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("Failed to bind socket");
        close(soc);
        return -1;
    }

    return soc;
}

void readPort(int can_soc, int vsomeip_soc) {
    struct can_frame frame;  // Structure to hold the CAN frame data
    frame.can_dlc = 4;  // Set the Data Length Code (DLC) to 4

    while (true) {
        usleep(100000);  // Sleep for 100 milliseconds

        struct timeval timeout = {1, 0};  // Set timeout for select to 1 second
        fd_set readSet;  // File descriptor set for select
        FD_ZERO(&readSet);  // Clear the set
        FD_SET(can_soc, &readSet);  // Add the CAN socket descriptor to the set

        // Wait for data on the socket or timeout
        if (select((can_soc + 1), &readSet, NULL, NULL, &timeout) >= 0) {
            // Check if data is available on the socket
            if (FD_ISSET(can_soc, &readSet)) {
                int recvBytes = read(can_soc, &frame, sizeof(struct can_frame));  // Read data from socket
                if (recvBytes) {
                    int rpm;
                    std::memcpy(&rpm, frame.data, sizeof(int));  // Extract RPM data from CAN frame

                    double speedCmPerMin = (rpm * WHEEL_DIAMETER_CM * M_PI) / 60.0;  // Calculate speed in cm/min

                    std::cout << "RPM: " << rpm << ", Speed (cm/min): " << speedCmPerMin << std::endl;

                    // Create a JSON object
                    nlohmann::json json_data;
                    json_data["RPM"] = rpm;
                    json_data["Speed"] = speedCmPerMin;

                    // Convert the JSON object to a string
                    std::string data = json_data.dump() + "\n";

                    // Send the JSON string to the VSOME/IP server
                    send(vsomeip_soc, data.c_str(), data.length(), 0);
                }
            }
        }
    }
}
void closePort(int soc) {
    close(soc);  // Close the socket
}

int connectToVsomeIpServer() {
    int soc = socket(AF_INET, SOCK_STREAM, 0);  // Create a new TCP socket
    if (soc < 0) {
        perror("Failed to create socket");
        return -1;
    }

    struct sockaddr_in server_addr;  // Socket address structure for TCP
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(VSOMEIP_SERVER_PORT);
    inet_pton(AF_INET, VSOMEIP_SERVER_IP.c_str(), &server_addr.sin_addr);  // Convert IP address from text to binary form

    // Connect to the VSOME/IP server
    if (connect(soc, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to connect");
        close(soc);
        return -1;
    }

    return soc;
}

int main() {
    int can_soc = openPort(CAN_INTERFACE.c_str());  // Open the CAN port
    if (can_soc < 0) {
        return -1;
    }

    int vsomeip_soc = connectToVsomeIpServer();  // Connect to the VSOME/IP server
    if (vsomeip_soc < 0) {
        closePort(can_soc);  // Close the CAN port if the VSOME/IP server connection fails
        return -1;
    }

    readPort(can_soc, vsomeip_soc);  // Read data from the CAN port and send to the VSOME/IP server
    closePort(can_soc);  // Close the CAN port
    close(vsomeip_soc);  // Close the VSOME/IP server connection

    return 0;
}
