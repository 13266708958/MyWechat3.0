#pragma once
#include "imediator.h"
#include "INet.h"
#include"DealDateStrategy.h"
#include"DealDateFactory.h"
class UDPMediator :public IMediator
{
public:
	UDPMediator(void);
	~UDPMediator(void);
public:
	bool Open();
	void Close();
	bool SendData(long lSendIp,char *szbuf,int nLen);
	void DealData(long lRecvIp,char *szbuf);
private:
	INet *m_pNet;
	DealDateStrategy *m_pdealDateStrategy;
	DealDateFactory  *m_pdealDateFactory;
};

