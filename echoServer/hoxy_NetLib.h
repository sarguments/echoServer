#pragma once

#pragma comment(lib, "ws2_32")
#include <WinSock2.h>
#include <Ws2tcpip.h>
#include <atlsocket.h>

class CNetLib
{
public:
	CNetLib(int serverPort);
	~CNetLib();

	// TODO : private ���δ� ���߿�
	SOCKET _listenSock;
	SOCKADDR_IN _serverAddr;

private:
	
};