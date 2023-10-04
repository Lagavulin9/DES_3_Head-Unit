#include "Can_Receiver.hpp"

#include "CAN_Moving_Average_Filter.hpp"

const char* CAN_INTERFACE = "can0";
int soc;

Moving_Average_Filter rpmFilter(10);

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

        int raw_sensor_rpm;
        std::memcpy(&raw_sensor_rpm, frame.data, sizeof(int));

        double f_sensor_rpm = rpmFilter.filter(raw_sensor_rpm);
        double w_rpm = (f_sensor_rpm * 0.025) / 0.065;

        double w_speed = (w_rpm * M_PI * 0.065);

        std::cout << "RPM : " << w_rpm << ", Speed : " << w_speed << std::endl;

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
