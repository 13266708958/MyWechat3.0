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
	STRU_DATAINFO sd;
	sd.m_lAddId=lRecvIp;
	sd.m_nType =_DEF_PROTOCOL_DATAINFO_RQ;
	strcpy_s(sd.m_szBuf,_DEF_BUFFERSIZE,psd->m_szBuf);
	sd.m_nSeq = 0;
	theApp.m_pUDPMediator->SendData(psd->m_lAddId,(char *)&sd,sizeof(sd));
}
