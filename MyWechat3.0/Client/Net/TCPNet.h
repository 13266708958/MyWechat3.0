#pragma once
#include "inet.h"
class TCPNet :public INet
{
public:
	TCPNet(void);
	~TCPNet(void);
public:
	bool InitNetWork();
	void UnInitNetWork();
	bool SendData(SOCKET sock,char* szbuf,int nlen);
public:
	static  unsigned _stdcall ThreadAccept( void * );
	static  unsigned _stdcall ThreadRecv( void * );

private:
	SOCKET m_sSockClient;
	HANDLE m_hThreadRecv;
	static bool  m_bFlagQuit;
};

