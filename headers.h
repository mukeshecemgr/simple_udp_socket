#ifndef _HEADERS_H
#define _HEADERS_H

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int server_init();
void client_init();

#endif
