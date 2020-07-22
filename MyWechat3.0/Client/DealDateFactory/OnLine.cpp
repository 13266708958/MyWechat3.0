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
	STRU_ONLINE *pso = (STRU_ONLINE *)szbuf;
	theApp.m_pMainWnd->SendMessage(UM_ONLINEMSG,(WPARAM)pso,NULL);
}
