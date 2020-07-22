#include"stdafx.h"
#include"DateInfo.h"
DateInfo::DateInfo()
{
}
DateInfo::~DateInfo()
{
}
void DateInfo::DealDate(long lRecvIp,char *szbuf)
{
	STRU_DATAINFO *psd = (STRU_DATAINFO *)szbuf;
	theApp.m_pMainWnd->SendMessage(UM_DATAINFOMSG,(WPARAM)psd->m_szBuf,psd->m_lAddId);
}
