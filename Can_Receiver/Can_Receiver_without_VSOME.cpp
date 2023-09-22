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
#include <nlohmann/json.hpp>  // Include for JSON handling

const std::string CAN_INTERFACE = "can0";
const int RPM_CAN_ID = 0x100;
const double WHEEL_DIAMETER_CM = 0.035;

int openPort(const char *port);
void readPort(int can_soc);
void closePort(int soc);

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

void readPort(int can_soc) {
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

                    std::cout << "JSON data: " << data << std::endl;  // Output the JSON data
                }
            }
        }
    }
}

void closePort(int soc) {
    close(soc);  // Close the socket
}

int main() {
    int can_soc = openPort(CAN_INTERFACE.c_str());  // Open the CAN port
    if (can_soc < 0) {
        return -1;
    }

    readPort(can_soc);  // Read data from the CAN port and output to console
    closePort(can_soc);  // Close the CAN port

    return 0;
}
