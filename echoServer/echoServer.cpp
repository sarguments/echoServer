#include "stdafx.h"
#include "hoxy_CmdStart.h"
#include "hoxy_NetLib.h"

int main()
{
	CCmdStart MyCmdStart;
	CNetLib MyNetLib(9500);

	MyNetLib._listenSock;
	MyNetLib._serverAddr;

    return 0;
}

