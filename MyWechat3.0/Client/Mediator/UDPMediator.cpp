#include"stdafx.h"
#include "UDPMediator.h"
#include"UDPNet.h"

UDPMediator::UDPMediator(void)
{
	m_pNet =new UDPNet;
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

}
