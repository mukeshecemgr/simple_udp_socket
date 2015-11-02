#include "headers.h"

int main(int argc,char *argv[])
{
	int choice = 0;
	
	do {
		printf("1.Server\n2.Client\nEnter Choice or press 0(ZERO) to exit:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				if ( 0 != server_init())
					printf("Failed to init Server\n");
				
				break;
			case 2:
				client_init();
				break;
			default:
				printf("Byeeee \n");
				exit(0);
		}
	}while(1);
}