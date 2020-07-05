#include"stdafx.h"
#include"Reg.h"
Reg::Reg()
{
}
Reg::~Reg()
{
}
void Reg::DealDate(long lRecvIp,char *szbuf)
{
	STRU_REGISTER *psr =(STRU_REGISTER*) szbuf;
	//Ð´ÈëÊý¾Ý¿â
	char str[100];
	sprintf_s(str,"insert into Account values('%s','%s');",psr->m_sUserId,psr->m_sUserPassword);
	theApp.m_Sql.UpdateMySql(str);
	CString Id;
	Id.Format("%s",psr->m_sUserId);
	theApp.m_mIdToAddr[Id] = lRecvIp;
	theApp.m_pMainWnd->SendMessage(UM_ONLINEMSG,(WPARAM)psr->m_szName,lRecvIp);
}
