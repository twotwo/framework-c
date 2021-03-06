/*
 * msg_proc.c: implementation of the
 * remote procedure "printmessage"
 */
#include <stdio.h>
#include "msg.h" //msg.h generated by rpcgen
 
int * printmessage_1_svc(char **msg, struct svc_req *req) {
	// must be static! 
	static int result;			
	printf("Console:%s\n", *msg);
	result = 0;
	return (&result);
}

/* Stop Msg Server.
 *
 */
void * stop_1_svc(void *nothing, struct svc_req *req) {
	printf("Console: Stop Service.\n");
	exit(0);
}

char* SRV_ACTIONS = "\n========Emulator RPC Version======\n\
Help: list Support list_actions_1_svc\n\
Binding : send a mobile info\n\
Push : send message to mobiles\n\
Query : query by mobile id\n\
";

char ** list_actions_1_svc(void *nothing, struct svc_req *req) {
	return &SRV_ACTIONS;
}

// char ** call_process_1_svc(char **, struct svc_req *) {

// }