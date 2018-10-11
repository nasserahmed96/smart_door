#ifndef SOCKET_SERVER
#define SOCKET_SERVER
#ifdef __cplusplus
extern "C"{
#endif
#include "stdlib.h"
#include "stdio.h"
#include "sys/types.h"
#include "sys/socket.h"
#include "netdb.h"
#include "arpa/inet.h"
#include "netinet/in.h"
#include "string.h"
#include "errno.h"
#include "c_sockets_nasser.h"
#include "wiringPi.h"
void start();

#ifdef __cplusplus
}
#endif
#endif
