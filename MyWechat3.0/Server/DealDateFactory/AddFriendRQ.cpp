#include"stdafx.h"
#include"AddFriendRQ.h"
AddFriendRQ::AddFriendRQ()
{
}
AddFriendRQ::~AddFriendRQ()
{
}
void AddFriendRQ::DealDate(long lRecvIp,char *szbuf)
{
	STRU_ADD *psa =(STRU_ADD *)szbuf;
	CString str;
	str.Format("%s",psa->m_sUserId);
	long ip = theApp.m_mIdToAddr[str];
	if(!ip)
		return ;
	STRU_ADD sa;
	sa.m_nType = _DEF_PROTOCOL_ADDFRIEND_RQ;
	sa.m_lAddIp = lRecvIp;		 //ÇëÇó¶Ëip
	/*CString strl;
	auto ite = theApp.m_mIdToAddr.begin();
	while(ite != theApp.m_mIdToAddr.end())
	{
		if((*ite).second != lRecvIp)
			strl = (*ite).first;
		ite++;
	}*/
	strcpy_s(sa.m_sUserId,_DEF_IDSIZE,str);

	theApp.m_pUDPMediator->SendData(ip,(char*)&sa,sizeof(sa));
}
