#ifndef CAN_RECEIVER_HPP
#define CAN_RECEIVER_HPP

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <net/if.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <linux/can.h>
#include <linux/can/raw.h>
#include <cmath>



extern int soc;


int open_port(const char* iface);
void read_port();
void close_port();

#endif