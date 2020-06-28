#include"stdafx.h"
#include "UDPMediator.h"
#include"UDPNet.h"

UDPMediator::UDPMediator(void)
{
	m_pNet =new UDPNet;
	m_pdealDateStrategy = new DealDateStrategy();
}


UDPMediator::~UDPMediator(void)
{
	delete m_pNet;
	m_pNet = NULL;
}

bool UDPMediator::Open()
{
	if(!m_pNet->InitNetWork())
		return false;
	return true;
}

void UDPMediator::Close()
{
	STRU_OFFLINE so;
	so.m_nType = _DEF_PROTOCOL_OFFLINE_RQ;
	theApp.m_pUDPMediator->SendData(inet_addr(_DEF_SERVER_IP),(char*)&so,sizeof(so));

	m_pNet->UnInitNetWork();
}

bool UDPMediator::SendData(long lSendIp,char *szbuf,int nLen)
{
	if(!m_pNet->SendData(lSendIp,szbuf,nLen))
		return false;
	return true;
}

void UDPMediator::DealData(long lRecvIp,char *szbuf)
{
	m_pdealDateFactory = m_pdealDateStrategy->CreateDealDateStrategy(szbuf);
	m_pdealDateFactory->DealDate(lRecvIp,szbuf);
}