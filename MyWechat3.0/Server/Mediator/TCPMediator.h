#pragma once
#include "imediator.h"
#include "INet.h"
class TCPMediator :public IMediator
{
public:
	TCPMediator(void);
	~TCPMediator(void);
public:
	bool Open();
	void Close();
	bool SendData(char *szbuf,int nLen);
	void DealData(long lRecvIp,char *szbuf);
private:
	INet *m_pNet;
};

