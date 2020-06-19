#pragma once
#include "inet.h"

class UDPNet :
	public INet
{
public:
	UDPNet(void);
	~UDPNet(void);
public:
	bool InitNetWork();
	void UnInitNetWork();
	bool SendData(long lSendIp,char *szbuf,int nLen);
public:
	static  unsigned  __stdcall ThreadProc( void * );
public:
	fd_set m_fd;
	bool m_bQuit;
	SOCKET m_sSock;
	HANDLE m_hThread;
};

