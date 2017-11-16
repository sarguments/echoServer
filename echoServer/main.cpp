#include "stdafx.h"
#include "hoxy_Header.h"

int main(void)
{
	CCmdStart MyCmd;
	CCmdStart::CmdDebugText(L"SERVER START", true);
	
	SocketUtil::WSAStart();

	TCPSocket* myTcpSocket = nullptr;
	myTcpSocket = SocketUtil::CreateTCPSocket(INET);
	
	SOCKADDR_IN myListenAddr;
	myListenAddr.sin_family = AF_INET;
	myListenAddr.sin_port = htons(9500);
	myListenAddr.sin_addr.S_un.S_addr = INADDR_ANY;

	myTcpSocket->Bind(&myListenAddr);
	myTcpSocket->Listen();

	TCPSocket* clientSocket = myTcpSocket->Accept(&myListenAddr);

	while (1)
	{
		char buf[1000] = { 0, };
		int RecvRet = clientSocket->Receive(buf, 1000);

		if (RecvRet <= 0)
		{
			wcout << L"<= 0 Recevied" << endl;
			break;
		}
		wcout << RecvRet << L"received" << endl;

		int SendRet = clientSocket->Send(buf, RecvRet);
		wcout << SendRet << L"send" << endl;
	}

	wcout << L"end" << endl;

	return 0;
}