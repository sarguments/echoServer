#include "stdafx.h"
#include "hoxy_NetLib.h"
#include "hoxy_CmdStart.h"

CNetLib::CNetLib(int serverPort)
	: _listenSock(INVALID_SOCKET)
{
	WSADATA wsa;
	int ret = WSAStartup(MAKEWORD(2, 2), &wsa);
	if (ret != 0)
	{
		CCmdStart::CmdDebugText(L"WinSock Init", false);
		return;
	}
	CCmdStart::CmdDebugText(L"WinSock Init", true);

	_listenSock = socket(AF_INET, SOCK_STREAM, 0);
	if (_listenSock == INVALID_SOCKET)
	{
		CCmdStart::CmdDebugText(L"listen socket Init", false);
		return;
	}
	CCmdStart::CmdDebugText(L"listen socket Init", true);

	ZeroMemory(&_serverAddr, sizeof(_serverAddr));
	_serverAddr.sin_family = AF_INET;
	_serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	_serverAddr.sin_port = htons(serverPort);
	
	ret = bind(_listenSock, (SOCKADDR*)&_serverAddr, sizeof(_serverAddr));
	if (ret == SOCKET_ERROR)
	{
		CCmdStart::CmdDebugText(L"bind", false);
	}
	CCmdStart::CmdDebugText(L"bind", true);

	ret = listen(_listenSock, SOMAXCONN);
	if (ret == SOCKET_ERROR)
	{
		CCmdStart::CmdDebugText(L"listen socket Listen", false);
		return;
	}
	CCmdStart::CmdDebugText(L"listen socket Listen", true);
}

CNetLib::~CNetLib()
{
	WSACleanup();
}