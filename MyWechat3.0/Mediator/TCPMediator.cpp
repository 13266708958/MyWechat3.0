#include"stdafx.h"
#include "TCPMediator.h"
#include"TCPNet.h"

TCPMediator::TCPMediator(void)
{
	m_pNet =new TCPNet;
}


TCPMediator::~TCPMediator(void)
{
	delete m_pNet;
	m_pNet = NULL;
}

bool TCPMediator::Open()
{
	if(!m_pNet->InitNetWork())
		return false;
	return true;
}

void TCPMediator::Close()
{
	
	m_pNet->UnInitNetWork();
}

bool TCPMediator::SendData(long lSendIp,char *szbuf,int nLen)
{
	
	return true;
}

void TCPMediator::DealData(long lRecvIp,char *szbuf)
{

}
