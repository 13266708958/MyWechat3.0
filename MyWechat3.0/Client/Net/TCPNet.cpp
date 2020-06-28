#include "stdafx.h"
#include "TCPNet.h"
#include"Client.h"
bool TCPNet::m_bFlagQuit = true;
TCPNet::TCPNet(void)
{
	m_sSockClient = NULL;
	m_hThreadRecv = NULL;
}


TCPNet::~TCPNet(void)
{
}

bool TCPNet::InitNetWork()
{
	//1.选择种类 -- 
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;

	/* Use the MAKEWORD(lowbyte, highbyte) macro declared in Windef.h */
	wVersionRequested = MAKEWORD(2, 2);

	err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0) {
		/* Tell the user that we could not find a usable */
		/* Winsock DLL.                                  */
		// printf("WSAStartup failed with error: %d\n", err);
		return false;
	}


	if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2) {
		/* Tell the user that we could not find a usable */
		/* WinSock DLL.                                  */
		// printf("Could not find a usable version of Winsock.dll\n");
		UnInitNetWork();
		return false;
	}



	//2.雇佣店长 -- socket 
	m_sSockClient = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP );
	if(m_sSockClient == INVALID_SOCKET )
	{
		UnInitNetWork();
		return false;
	}
	//3.选址 --- 
	sockaddr_in  addrServer;
	addrServer.sin_family = AF_INET;
	addrServer.sin_addr.S_un.S_addr = inet_addr(_DEF_SERVER_IP);
	addrServer.sin_port = htons(_DEF_PORT);

	if(SOCKET_ERROR ==connect(m_sSockClient,(const sockaddr*)&addrServer,sizeof(addrServer)))
	{
		UnInitNetWork();
		return false;
	}
	struct tcp_keepalive kavars[1] = {  
		1,  
		10 * 1000,        /* 10 seconds */  
		5 * 1000          /* 5 seconds */  
	};
	int alive = 1;  
	if (setsockopt(m_sSockClient, SOL_SOCKET, SO_KEEPALIVE, (const char *) &alive,sizeof( alive)) != 0)  
	{  
		//log_warn ("Set keep alive error: %s.\n", strerror (errno));  
		return -1;  
	}  
	unsigned long ret = 0;
	if (WSAIoctl  (m_sSockClient, SIO_KEEPALIVE_VALS, kavars, sizeof kavars, NULL, sizeof (int), &ret, NULL, NULL) != 0)  
	{  
		//log_warn ("Set keep alive error: %s.\n", strerror (WSAGetLastError ()));  
		return -1;  
	} 
	//创建线程 -- recv
	m_hThreadRecv = (HANDLE) _beginthreadex(NULL,0,&TCPNet::ThreadRecv,this,0,0);
	return true;
}


unsigned _stdcall TCPNet::ThreadRecv( void * lpvoid)
{
	TCPNet* pthis = (TCPNet*)lpvoid;
	char szbuf[_DEF_PACKSIZE]={0};
	int nRelReadNum =0;

	while(TCPNet::m_bFlagQuit)
	{
		int nRelReadNum = recv(pthis->m_sSockClient,(char *)&szbuf,_DEF_PACKSIZE,0);
		if(nRelReadNum <=0)
		{
			//是不是客户端下载
			if(WSAECONNRESET  == GetLastError())
			{
				closesocket(pthis->m_sSockClient);
				pthis->m_sSockClient  =NULL;
				break;
			}
			continue;
		}

	}
	return 0;
}

void TCPNet::UnInitNetWork()
{
	m_bFlagQuit = false;
	if(m_hThreadRecv )
	{
		if(WAIT_TIMEOUT == WaitForSingleObject(m_hThreadRecv,100))
			TerminateThread(m_hThreadRecv,-1);

		CloseHandle(m_hThreadRecv);
		m_hThreadRecv = NULL;
	}

	WSACleanup();
	if(m_sSockClient)
	{
		closesocket(m_sSockClient);
		m_sSockClient = NULL;
	}
}


bool TCPNet::SendData(SOCKET sock,char* szbuf,int nlen)
{
	if(nlen <= 0|| szbuf ==0)
		return false;

	if(send(sock,(const char *)&nlen,sizeof(int ),0)<0)
		return false;

	if(send(sock,szbuf,nlen,0)<0)
		return false;

	return true;
}