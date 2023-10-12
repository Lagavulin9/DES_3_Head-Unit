#ifndef CAN_RECEIVER_HPP
#define CAN_RECEIVER_HPP

#include <iostream>
#include <cstring>
#include <unistd.h>
#include <net/if.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <linux/can.h>
#include <linux/can/raw.h>
#include <cmath>



extern int soc;


int openPort(const char* iface);
void readData();
void processAndFilterData();
void checkTimeout();
void closePort();


#endif  //  CAN_RECEIVER_HPP
