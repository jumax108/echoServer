#pragma once

#define WIN32_LEAN_AND_MEAN
#include "objectFreeListTLS/headers/objectFreeListTLS.h"
#include "stack/headers/stack.h"
#include "queue/headers/queue.h"

#include "lanServer/headers/lanServer.h"
#pragma comment(lib, "lib/lanServer/lanServer_iocp")

class CEchoServer: public CLanServer{

	// Ŭ���̾�Ʈ�� ������ �õ��� ���¿��� ȣ��˴ϴ�.
	// ��ȯ�� ���� ���� ������ ����մϴ�.
	// return true = ���� ��, ���� �ʱ�ȭ
	// return false = ������ ����
	virtual bool onConnectRequest(unsigned int ip, unsigned short port);
	// Ŭ���̾�Ʈ�� ������ �Ϸ��� ���¿��� ȣ��˴ϴ�.
	virtual void onClientJoin(unsigned int ip, unsigned short port, unsigned __int64 sessionID);
	// Ŭ���̾�Ʈ�� ������ �����Ǹ� ȣ��˴ϴ�.
	virtual void onClientLeave(unsigned __int64 sessionID);

	// Ŭ���̾�Ʈ���� �����͸� �����ϸ� ȣ��˴ϴ�.
	virtual void onRecv(unsigned __int64 sessionID, CPacketPointer recvPacket);
	// Ŭ���̾�Ʈ���Լ� �����͸� ���޹����� ȣ��˴ϴ�.
	virtual void onSend(unsigned __int64 sessionID, int sendSize);

	// ���� ��Ȳ���� ȣ��˴ϴ�.
	virtual void onError(int errorCode, const wchar_t* errorMsg);

	unsigned __int64 sendData[65536]={0,};
	unsigned short logCnt=0;

};