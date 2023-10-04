#include "Can_Receiver.hpp"

const char* CAN_INTERFACE = "can0";
int soc;

int open_port(const char* iface){
    struct sockaddr_can addr;
    struct ifreq ifr;

    //create socket
    if((soc = socket(PF_CAN, SOCK_RAW, CAN_RAW)) < 0 ) {
        perror("Socket creation error");
        return -1;
    }

    //Set CAN Interface Name

    std::strcpy(ifr.ifr_name , iface);
    ioctl(soc, SIOCGIFINDEX, &ifr);

    //Set Socket Address

    addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;

    //Bind Socket with CAN Interface
    
    if(bind(soc, (struct sockaddr *)&addr, sizeof(addr)) < 0 ) {
        perror("Bind error");
        return -1;
    }

    return 0;
}

void read_port(){
    struct can_frame frame;
    while(true){
        ssize_t nbytes = recvfrom(soc, &frame, sizeof(struct can_frame), 0, NULL, NULL);
        if(nbytes < 0){
            perror("Read error");
            break;
        }

        if(nbytes < sizeof(struct can_frame)){
            perror("Incomplete CAN frame");
            continue;
        }

        int rpm;
        std::memcpy(&rpm, frame.data, sizeof(int));

        rpm = (rpm * 0.025) / 0.065;

        double speed = (rpm * M_PI * 0.065);

        std::cout << "RPM : " << rpm << ", Speed : " << speed << std::endl;

        usleep(100000);

    }
}


void close_port(){
    close(soc);
}


int main() {
    if (open_port(CAN_INTERFACE) < 0) {
        return -1;
    }

    read_port();

    close_port();
    
    return 0;
}
