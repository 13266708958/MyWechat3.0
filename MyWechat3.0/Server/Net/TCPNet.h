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
public:
	SOCKET m_sSockServer;
	std::list<HANDLE> m_lsthThreadRecv;
	HANDLE m_hThreadAccept;
	static bool m_bFlagQuit;
};

