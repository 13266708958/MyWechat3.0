#include"stdafx.h"
#include"AddFriend.h"
AddFriend::AddFriend()
{
}
AddFriend::~AddFriend()
{
}
void AddFriend::DealDate(long lRecvIp,char *szbuf)
{
	STRU_ADD *psa =(STRU_ADD *)szbuf;
	CString str;
	str.Format("%s",psa->m_sUserId);
	long ip = theApp.m_mIdToAddr[str];
	if(!ip)
		return ;

	STRU_ADD sa;
	sa.m_nType = _DEF_PROTOCOL_ADDFRIEND_RQ;
	sa.m_lAddIp = lRecvIp;      //ÇëÇó¶Ëip
	strcpy_s(sa.m_sUserId,_DEF_IDSIZE,str);

	theApp.m_pUDPMediator->SendData(ip,(char*)&sa,sizeof(sa));

}
