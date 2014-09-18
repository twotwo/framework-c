/*
*  msg.x: Remote msg printing protocol
*
*  author liyan(twotwo.li@163.com)
*/
enum actions {Help, Binding, Push, Query};

program MsgRPC {
	version MsgRPC_Ver_1 {
		/* a test function */
		int PRINTMESSAGE(string) = 1;
		/* stop service */
		void stop() = 2;
		string list_actions() = 3;
	} = 1;
} = 0x20002201;


