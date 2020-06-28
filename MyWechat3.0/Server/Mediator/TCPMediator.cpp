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

bool TCPMediator::SendData(SOCKET sock,char *szbuf,int nLen)
{
	dynamic_cast<TCPNet *>(m_pNet)->SendData(sock,szbuf,nLen);//使用父类的指针调用子类的函数
	return true;
}

void TCPMediator::DealData(SOCKET sock,char *szbuf)
{

}
