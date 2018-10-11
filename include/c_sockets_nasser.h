#ifndef C_SOCKETS_NASSER
#define C_SOCKETS_NASSER

#include "stdlib.h"
#include "stdio.h"
#include "sys/types.h"
#include "sys/socket.h"
#include "netdb.h"
#include "netinet/in.h"
#include "string.h"
#include "errno.h"

#define BACKLOG 10
#define PORT "1996"
#define MAXDATASIZE 100

char ipstr[INET6_ADDRSTRLEN];
char s[INET6_ADDRSTRLEN];
char msg[MAXDATASIZE];

//File properties
struct addrinfo hints;
struct addrinfo *servinfo;
int statue;
int *socket_desc, *new_fd;
int desc, new_desc;
void searchList(char*);
void bindSocket();
void startServer();
void sendMsg(char *, int);
void sendFile(unsigned int, const char *, int);      
void recvMsg(int);
void recvFile();
void connectToServer();

#endif

