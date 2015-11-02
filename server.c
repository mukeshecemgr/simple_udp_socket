#include "headers.h"

int server_init()
{
	struct sockaddr_in serv,clnt;
	int sid, len ;
	int sz = 0;
	char buff[1024] = {0};
	
	//init socket 
	if ( 0 > (sid = socket(AF_INET,SOCK_DGRAM,0)) )
	{
		perror("socket()");
		return -1;
	}
	
	serv.sin_family = AF_INET;
	serv.sin_port = 5010;
	serv.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	//binding address and port
	if ( 0 > bind(sid,(struct sockaddr *)&serv,sizeof(serv)) )
	{
		perror("bind()");
		return -1;
	}
	len = sizeof(clnt);
	//Start receiving message from client
	while(1)
	{
		sz = recvfrom(sid,buff,sizeof(buff),0,
					  (struct sockaddr*)&clnt,&len);
		if ( sz < 0)
			continue;
		if (sz > 0)
		{
			printf("Client [%s] sent message : %s\n",
								inet_ntoa(clnt.sin_addr),buff);
		}
	}
	
		
	
}