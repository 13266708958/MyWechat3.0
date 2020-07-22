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
	char str[500];
	sprintf_s(str,"insert into Account values('%s','%s');",psr->m_sUserId,psr->m_sUserPassword);
	theApp.m_Sql.UpdateMySql(str);
	ZeroMemory(str,sizeof(str));
	sprintf_s(str,"CREATE TABLE `chat_useraccount`.`%s` (`Friend_ID` VARCHAR(40) NOT NULL,PRIMARY KEY (`Friend_ID`));",psr->m_sUserId);
	theApp.m_Sql.UpdateMySql(str);
	CString Id;
	Id.Format("%s",psr->m_sUserId);
	theApp.m_mIdToAddr[Id] = lRecvIp;
	STRU_ONLINE *pso = new STRU_ONLINE ;
	strcpy_s(pso->m_sUserId,_DEF_IDSIZE,psr->m_sUserId);
	strcpy_s(pso->m_szName,_DEF_SIZE,psr->m_szName);
	theApp.m_pMainWnd->SendMessage(UM_ONLINEMSG,(WPARAM)pso,lRecvIp);
}
