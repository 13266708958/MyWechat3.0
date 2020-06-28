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
	bool SendData(SOCKET sock,char* szbuf,int nlen);
	void DealData(SOCKET sock,char *szbuf);
private:
	INet *m_pNet;
};

