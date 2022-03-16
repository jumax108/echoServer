#include "headers/echoServer.h"

int main(){

	CEchoServer server;
	server.start(L"0.0.0.0", 6000, 4, 4, 100, false, 5000, 5000);

	printf("server start\n");

	for(;;){

	}

	return 0;

}