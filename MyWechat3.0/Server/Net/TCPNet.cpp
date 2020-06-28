#include "stdafx.h"
#include "TCPNet.h"
#include"Server.h"
bool  TCPNet::m_bFlagQuit = true;

TCPNet::TCPNet(void)
{
	m_sSockServer = NULL;

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
	m_sSockServer = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP );
	if(m_sSockServer == INVALID_SOCKET )
	{
		UnInitNetWork();
		return false;
	}
	//3.选址 --- 
	sockaddr_in  addrServer;
	addrServer.sin_family = AF_INET;
	addrServer.sin_addr.S_un.S_addr = INADDR_ANY/*inet_addr("192.168.3.1")*/;
	addrServer.sin_port = htons(_DEF_PORT);
	if(SOCKET_ERROR ==bind(m_sSockServer,(const sockaddr*)&addrServer,sizeof(addrServer)))
	{
		UnInitNetWork();
		return false;
	}
	//4.店长发宣传 -- 
	if(SOCKET_ERROR  == listen(m_sSockServer,20))
	{
		UnInitNetWork();
		return false;

	}

	//5.创建线程
	m_hThreadAccept = (HANDLE)_beginthreadex(NULL,0,&ThreadAccept,this,0,0);


	return true;
}
unsigned _stdcall TCPNet::ThreadAccept( void * lpvoid)
{
	TCPNet *pthis = (TCPNet*)lpvoid;

	while(pthis->m_bFlagQuit)
	{
		SOCKET sockWaiter =  accept(pthis->m_sSockServer,NULL,NULL);
		if(sockWaiter == INVALID_SOCKET)
			continue;
		struct tcp_keepalive kavars[1] = {  
			1,  
			10 * 1000,        /* 10 seconds */  
			5 * 1000          /* 5 seconds */  
		};
		int alive = 1;  
		if (setsockopt(sockWaiter, SOL_SOCKET, SO_KEEPALIVE, (const char *) &alive,sizeof( alive)) != 0)  
		{  
			//log_warn ("Set keep alive error: %s.\n", strerror (errno));  
			return -1;  
		}  
		unsigned long ret = 0;
		if (WSAIoctl  (sockWaiter, SIO_KEEPALIVE_VALS, kavars, sizeof kavars, NULL, sizeof (int), &ret, NULL, NULL) != 0)  
		{  
			//log_warn ("Set keep alive error: %s.\n", strerror (WSAGetLastError ()));  
			return -1;  
		} 

		HANDLE m_hThreadRecv = (HANDLE)_beginthreadex(NULL,0,&ThreadRecv,(void * )sockWaiter,0,0);
		if(m_hThreadRecv)
		{
			pthis->m_lsthThreadRecv.push_back(m_hThreadRecv);
		}
		//接收数据 
	}
	return 0;
}
unsigned _stdcall TCPNet::ThreadRecv( void * lpvoid)
{
	SOCKET sockWaiter = (SOCKET)lpvoid;
	//char szbuf[_DEF_SIZE] = {0};
	char szbuf[_DEF_PACKSIZE]={0};
	int nRelReadNum =0;

	//int packsize;
	//char *Recvszbuf;
	//STRU_FILEHEADER szbuf = {0};
	while(TCPNet::m_bFlagQuit)
	{
		//   ---数据包的长度  packbuff-----int
		int nRelReadNum = recv(sockWaiter,(char *)&szbuf,_DEF_PACKSIZE,0);
		if(nRelReadNum <=0)
		{
			//是不是客户端下载
			if(WSAECONNRESET  == GetLastError())
			{
				closesocket(sockWaiter);
				sockWaiter  =NULL;
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
	if(m_hThreadAccept )
	{
		if(WAIT_TIMEOUT == WaitForSingleObject(m_hThreadAccept,100))
			TerminateThread(m_hThreadAccept,-1);

		CloseHandle(m_hThreadAccept);
		m_hThreadAccept = NULL;
	}
	auto ite = m_lsthThreadRecv.begin();
	while(ite != m_lsthThreadRecv.end())
	{
		if(WAIT_TIMEOUT == WaitForSingleObject(*ite,100))
			TerminateThread(*ite,-1);

		CloseHandle(*ite);
		*ite = NULL;
		ite++;
	}
	m_lsthThreadRecv.clear();
	WSACleanup();
	if(m_sSockServer)
	{
		closesocket(m_sSockServer);
		m_sSockServer = NULL;
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