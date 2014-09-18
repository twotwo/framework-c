/* printmsg.c: print a message on the console */

#include <stdio.h>
#include <stdlib.h>

int printMessage(char *msg);
void console();
int STATUS = 0;
int initService();

int main(int argc, char const *argv[])
{
		// char *message;

		// if (argc != 2) {
		// 	fprintf(stderr, "usage: %s <message>\n",
		// 		argv[0]);
		// 	return 1;
		// }
		// message = (char *)argv[1];
		// printMessage(message);
		// printf("Message Delivered!\n");
	console();
	return 0;
}

int printMessage(char *msg)
{
	printf("Console:%s\n", msg);
	return 0;
}

void console() {
	char     c;
	c = 1;
	
	while ( 1 )
	{
		switch ( c ) 
		{

			case 'h':
			printf("Help Info here.\n");
			break;

			case 'i':
			initService();
			break;

			case 'x':
			printf("Quit Console.\n");
			exit(0);
			break;

			default:
			if (c != (char)NULL && c >48)
				fprintf(stderr, "Can not recognize your action: [%c].\n", c);
			break;
			
		}

		c = getchar();
	}
}

int initService() {
	if(STATUS == 0) {
		printf("Init Service...\n");
		STATUS = 1;
		return 0;
	}else if(STATUS == 1) {
		fprintf(stderr, "Service already inited.\n");
		return 1;
	}else {
		fprintf(stderr, "Unknowned Status.\n");
		return 2;
	}
}