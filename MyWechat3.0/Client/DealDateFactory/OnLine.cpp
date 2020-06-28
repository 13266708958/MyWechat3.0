#include"stdafx.h"
#include"OnLine.h"
OnLine::OnLine()
{
}
OnLine::~OnLine()
{
}
void OnLine::DealDate(long lRecvIp,char *szbuf)
{
	//获取当前账户的好友目录
	theApp.m_pMainWnd->SendMessage(UM_ONLINEMSG,NULL,NULL);
}
