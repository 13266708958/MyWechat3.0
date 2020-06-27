#include"stdafx.h"
#include"Log.h"
Log::Log()
{
}
Log::~Log()
{
}
void Log::DealDate(long lRecvIp,char *szbuf)
{
	STRU_LOGIN *psl =(STRU_LOGIN*) szbuf;

	//对比数据库
	char str[100];

	list<string> strlist;
	string passWord;
	sprintf_s(str,"select PassWord from Account where ID = '%s';",psl->m_sUserId);
	theApp.m_Sql.SelectMySql(str,1,strlist);
	auto ite = strlist.begin();
	while(ite !=strlist.end())
	{
		passWord =strlist.front();
		strlist.pop_front();
		if(strcmp(passWord.c_str(),psl->m_sUserPassword) == 0)
		{
			/*CString str;
			str.Format("%s",psl->m_sUserId);*/
			//m_pUdpNet->m_mIdToAddr[str] = lRecvIp;
			//m_pUdpNet->SendDataToServer(inet_addr(_DEF_SERVER_IP),(char *)&sl,sizeof(sl));//发送登录回复
			theApp.m_pMainWnd->SendMessage(UM_ONLINEMSG,(WPARAM)psl->m_szName,lRecvIp);
			break;
		}

	}
}
