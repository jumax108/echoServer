#include "headers/echoServer.h"

bool CEchoServer::onConnectRequest(unsigned int ip, unsigned short port){
	return true;
}

void CEchoServer::onClientJoin(unsigned int ip, unsigned short port, unsigned __int64 sessionID){

	//printf("client join: %d, %d, %I64x\n", ip, port, sessionID);

}

void CEchoServer::onClientLeave(unsigned __int64 sessionID){



}

void CEchoServer::onRecv(unsigned __int64 sessionID, CPacketPointer recvPacket){
	
	unsigned __int64 data;
	recvPacket >> data;

	CPacketPtr_Lan packet;
	packet << data;

	unsigned short index = InterlockedIncrement16((SHORT*)&logCnt) - 1;
	sendData[index] = data;

	sendPacket(sessionID, packet);

}

void CEchoServer::onSend(unsigned __int64 sessionID, int sendSize){
}

void CEchoServer::onError(int errorCode, const wchar_t* errorMsg){

	wprintf(L"code: %d\n", errorCode);
	wprintf(L"msg: %s\n\n", errorMsg);

}