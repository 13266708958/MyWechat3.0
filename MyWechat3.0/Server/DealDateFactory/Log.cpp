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
	while( !strlist.empty())
	{
		passWord =strlist.front();
		strlist.pop_front();
		if(strcmp(passWord.c_str(),psl->m_sUserPassword) == 0)
		{
			CString Id;
			Id.Format("%s",psl->m_sUserId);
			theApp.m_mIdToAddr[Id] = lRecvIp;
			STRU_ONLINE *pso = new STRU_ONLINE();
			strcpy_s(pso->m_sUserId,_DEF_IDSIZE,psl->m_sUserId);
			strcpy_s(pso->m_szName,_DEF_SIZE,psl->m_szName);
			theApp.m_pMainWnd->SendMessage(UM_ONLINEMSG,(WPARAM)pso,lRecvIp);
			break;
		}

	}
}
