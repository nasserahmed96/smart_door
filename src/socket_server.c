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
#include "socket_server.h"
void start(char *person_name){
	//Initialize
	wiringPiSetup();
	pinMode(0, OUTPUT);
	digitalWrite(0, LOW);
	searchList(NULL);
	bindSocket();
	startServer();
	recvMsg(*new_fd);
	printf("strcmp %d\n", strcmp(msg, "Open"));
	//Open the door when recieving signal
	digitalWrite(0, HIGH);
	delay(10000);
	digitalWrite(0, LOW);
	printf("Done");
	printf("%s\n", msg);
	printf("Bism Allah test\n");
}
