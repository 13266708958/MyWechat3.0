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
	//д�����ݿ�
	char str[100];
	sprintf_s(str,"insert into Account values('%s','%s');",psr->m_sUserId,psr->m_sUserPassword);
	theApp.m_Sql.UpdateMySql(str);
	/*CString str;
	str.Format("%s",psr->m_sUserId);*/
	//m_pUdpNet->m_mIdToAddr[str] = lRecvIp;
	theApp.m_pMainWnd->SendMessage(UM_ONLINEMSG,(WPARAM)psr->m_szName,lRecvIp);
	//m_pUdpNet->SendDataToServer(inet_addr(_DEF_SERVER_IP),(char *)&sr,sizeof(sr));
}
