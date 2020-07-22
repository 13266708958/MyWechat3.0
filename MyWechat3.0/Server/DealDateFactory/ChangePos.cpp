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
	STRU_CHANGEPOS *psc = (STRU_CHANGEPOS *)szbuf;
	STRU_CHANGEPOS sc;
	sc.m_nType =_DEF_PROTOCOL_CHANGEPOS;
	sc.m_lAddId =lRecvIp;
	theApp.m_pUDPMediator->SendData(psc->m_lAddId,(char *)&sc,sizeof(sc));
}
