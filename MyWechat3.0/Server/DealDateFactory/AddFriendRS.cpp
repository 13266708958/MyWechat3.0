#include"stdafx.h"
#include"AddFriendRS.h"
AddFriendRS::AddFriendRS()
{
}
AddFriendRS::~AddFriendRS()
{
}
void AddFriendRS::DealDate(long lRecvIp,char *szbuf)
{
	STRU_ADD *psa =(STRU_ADD *)szbuf;
	STRU_ADD sa;
	sa.m_nType = _DEF_PROTOCOL_ADDFRIEND_RS;
	sa.m_lAddIp = lRecvIp;//要添加的用户的地址
	strcpy_s(sa.m_sUserId,_DEF_IDSIZE,psa->m_sUserId);
	theApp.m_pUDPMediator->SendData(psa->m_lAddIp,(char*)&sa,sizeof(sa));
}
