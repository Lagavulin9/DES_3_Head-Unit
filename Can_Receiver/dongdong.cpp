#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <net/if.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <linux/can.h>
#include <linux/can/raw.h>

int soc;                   // Socket descriptor
int read_can_port;         // Flag for reading from the CAN port

int open_port(const char *port)
{
    struct ifreq ifr;      // Interface request structure for socket ioctls
    struct sockaddr_can addr;  // Address structure for the CAN socket

    /* open socket */
    soc = socket(PF_CAN, SOCK_RAW, CAN_RAW);  // Open a CAN socket

    if (soc < 0) 
    {
	    printf("error!");
        return (-1);
    }

    addr.can_family = AF_CAN;  // Set the family type for the address to CAN
    strcpy(ifr.ifr_name, port);  // Copy the port name to the ifreq structure

    // Fetch the index of the network interface into the ifreq structure using ioctl
    if (ioctl(soc, SIOCGIFINDEX, &ifr) < 0) 
    {
	    printf("error!");
        return (-1);
    }

    addr.can_ifindex = ifr.ifr_ifindex;  // Get the interface index from the ifreq structure
    fcntl(soc, F_SETFL, O_NONBLOCK);  // Set the socket to non-blocking mode

    // Bind the socket to the CAN interface
    if (bind(soc, (struct sockaddr *)&addr, sizeof(addr)) < 0) 
    {
	    printf("binding error!");
        return (-1);
    }

    return 0;
}

void read_port()
{
    struct can_frame frame;  // Structure to hold the CAN frame data
    frame.can_dlc = 2;      // Set the data length code (DLC) to 2
    int recvbytes = 0;      // Number of bytes received
    read_can_port = 1;      // Flag to continue reading from the CAN port

    while(read_can_port)  // Continue reading as long as the flag is set
    {
        usleep(100000);  // Sleep for 100ms

        struct timeval timeout = {1, 0};  // Set the timeout for the select function to 1 second
        fd_set readSet;  // File descriptor set for the select function
        FD_ZERO(&readSet);  // Clear the set
        FD_SET(soc, &readSet);  // Add the socket descriptor to the set

        // Use the select function to wait for data on the socket or for the timeout
        if (select((soc + 1), &readSet, NULL, NULL, &timeout) >= 0) 
        {
            if (!read_can_port) 
            {
		        printf("error!");
                break;
            }

            // Check if data is available on the socket
            if (FD_ISSET(soc, &readSet)) 
            {
                // Read the data from the socket
                recvbytes = read(soc, &frame, sizeof(struct can_frame));
                if(recvbytes) 
                { 
                   /* ==================== Receive Data ====================*/
                   // Convert the first two bytes of the CAN frame data to the disk rpm
                   int disk_rpm = (frame.data[0] << 8) + frame.data[1];

                   // Calculate the rpm from the disk rpm
                   int rpm = (int)((float)disk_rpm / 2.6);
                   printf("Car RPM: %d\t", rpm);

                   // Calculate the speed from the rpm
                   float speed = (float)rpm * 0.0034;
                   printf("Car Speed: %.3f m/s\n", speed);
                }
            }
        }
    }
}

int close_port()
{
    close(soc);  // Close the socket
    return 0;
}


int main(void)
{
    open_port("can0");  // Open the CAN port with the name "can0"
    read_port();  // Read data from the CAN port
   
    return 0;
}