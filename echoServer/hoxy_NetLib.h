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

	// TODO : private 여부는 나중에
	SOCKET _listenSock;
	SOCKADDR_IN _serverAddr;

private:
	
};