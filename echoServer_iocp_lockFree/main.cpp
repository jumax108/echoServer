#include "headers/echoServer.h"

CDump dump;

int main(){

	CEchoServer server;
	server.start(L"0.0.0.0", 6000, 4, 4, 5000, false, 5000, 5000);

	printf("server start\n");

	for(;;){

		printf("accept tps: %d\n", server.getAcceptTPS());
		printf("recv tps: %d\n", server.getRecvTPS());
		printf("send tps: %d\n", server.getSendTPS());
		printf("packet pool: %I64d chunks\n\n", CPacketPtr_Lan::getPacketPoolUsage());

		Sleep(1000);
	}

	return 0;

}