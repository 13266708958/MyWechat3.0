#include"stdafx.h"
#include"ChangePos.h"
ChangePos::ChangePos()
{
}
ChangePos::~ChangePos()
{
}
void ChangePos::DealDate(long lRecvIp,char *szbuf)
{
	STRU_CHANGEPOS *psc = (STRU_CHANGEPOS *) szbuf;
	theApp.m_pMainWnd->SendMessage(UM_CHANGEPOS,0,psc->m_lAddId);
}
