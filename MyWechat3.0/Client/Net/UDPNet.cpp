#include "stdafx.h"
#include "UDPNet.h"


UDPNet::UDPNet(void)
{
	m_sSock = NULL;
	m_hThread =NULL;
	m_bQuit = true;
}



UDPNet::~UDPNet(void)
{
}

bool UDPNet::InitNetWork()
{
	//1.���ؿ�
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;

	/* Use the MAKEWORD(lowbyte, highbyte) macro declared in Windef.h */
	wVersionRequested = MAKEWORD(2, 2);

	err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0) {
		/* Tell the user that we could not find a usable */
		/* Winsock DLL.                                  */
		printf("WSAStartup failed with error: %d\n", err);
		return 1;
	}

	/* Confirm that the WinSock DLL supports 2.2.*/
	/* Note that if the DLL supports versions greater    */
	/* than 2.2 in addition to 2.2, it will still return */
	/* 2.2 in wVersion since that is the version we      */
	/* requested.                                        */

	if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2) {
		/* Tell the user that we could not find a usable */
		/* WinSock DLL.                                  */
		printf("Could not find a usable version of Winsock.dll\n");
		UnInitNetWork();
		return 1;
	}
	else
		printf("The Winsock 2.2 dll was found okay\n");

	//2.�����׽���
	m_sSock = socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);
	u_long uval =1;
	ioctlsocket(m_sSock,FIONBIO,&uval);//����socketΪ������

	FD_SET(m_sSock,&m_fd);//��socket���뼯��
	timeval tv;
	tv.tv_sec = 0;
	tv.tv_usec =100;
	select(0,&m_fd,0,0,&tv);
	if(INVALID_SOCKET == m_sSock)
	{
		UnInitNetWork();
		return false;
	}

	//���ù㲥Ȩ��
	BOOL val = TRUE;
	setsockopt(m_sSock,SOL_SOCKET,SO_BROADCAST,(const char*)&val,sizeof(val));

	//3.�󶨵�ַ
	sockaddr_in addr;
	addr.sin_family=AF_INET;
	addr.sin_port =htons(_DEF_PORT_CLIENT);
	addr.sin_addr.S_un.S_addr =INADDR_ANY;//���ñ��������ַ
	if(SOCKET_ERROR == bind(m_sSock,(const sockaddr*)&addr,sizeof(addr)))
	{
		UnInitNetWork();
		return false;
	}

	//4.�����߳�
	m_hThread =(HANDLE)_beginthreadex(NULL,0,&ThreadProc,this,0,0);

	return true;
}

unsigned  __stdcall UDPNet::ThreadProc( void * lpvoid)
{
	UDPNet *pthis = (UDPNet*)lpvoid;
	char szbuf[_DEF_PACKSIZE]={0};
	sockaddr_in addrClient;
	int nsize= sizeof(addrClient);
	int nRelReadNum = 0;
	fd_set fTemp;
	while(pthis->m_bQuit)
	{
		fTemp= pthis->m_fd;
		if(FD_ISSET(pthis->m_sSock,&fTemp))
		{
			ZeroMemory(szbuf,_DEF_PACKSIZE);
			nRelReadNum = recvfrom(pthis->m_sSock,szbuf,sizeof(szbuf),0,(sockaddr *)&addrClient,&nsize);
			if( nRelReadNum>0 )
			{
				//������յ�����
				theApp.m_pMediator->DealData(addrClient.sin_addr.s_addr,szbuf);
			}
		}
	}
	return 0;
}

void UDPNet::UnInitNetWork()
{
	m_bQuit = false;
	if(m_hThread)
	{
		if(WAIT_TIMEOUT == WaitForSingleObject(m_hThread,100))
			TerminateThread(m_hThread,-1);

		CloseHandle(m_hThread);
		m_hThread = NULL;
	}
	if(m_sSock)
	{
		closesocket(m_sSock);
		m_sSock = NULL;
	}
	
	WSACleanup();//ж�ؿ�
}

bool UDPNet::SendData(long lSendIp,char *szbuf,int nLen)
{
	return true;
}
