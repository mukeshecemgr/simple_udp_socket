#include "headers.h"

void client_init()
{
	
	struct sockaddr_in clnt;
	char buff[100]="request";
	int status,sd = 0;
	
	sd = socket(AF_INET,SOCK_DGRAM,0);
	if ( sd < 0)
	{
		perror("socket()");
		return;
	}
	clnt.sin_family = AF_INET;
	clnt.sin_port = 5010;
	clnt.sin_addr.s_addr = inet_addr("127.0.0.1");//configure Any IP in case of 
													//network
	
	if ( status = ( sendto(sd,buff,100,0,(struct sockaddr *)&clnt,
				sizeof(struct sockaddr)) ) < 0)
	{
		perror("sendto()");
	}
}
	
	
	
	
	