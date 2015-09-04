#include "utils.h"      //has our queue
#include "result.h"
#include <pthread.h>
#include "taskmgr.h"
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#ifndef COMMS_H
#define COMMS_H
#define SEND_CHUNKS 0x2000
char server_ip[10];
char client_ip[10];
int  client_port;
int  server_port;
void setIPAddr(char *ip, char *m_ip);
void setPort( int port, int m_port);
void initServer();
void recieveTask(void* c_sock);
enum HRet sendTaskToClient(char* message);
//int resetComms();

#endif
