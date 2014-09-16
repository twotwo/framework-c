/* printmsg.c: print a message on the console */

#include <stdio.h>

int printmessage(char *msg);

int main(int argc, char const *argv[])
{
	char *message;

	if (argc != 2) {
		fprintf(stderr, "usage: %s <message>\n",
			argv[0]);
		return 1;
	}
	message = (char *)argv[1];
	printmessage(message);
	printf("Message Delivered!\n");
	return 0;
}

int printmessage(char *msg)
{
	printf("Console:%s\n", msg);
	return 0;
}