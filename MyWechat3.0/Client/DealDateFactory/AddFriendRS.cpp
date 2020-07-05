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
	char *choice = "YES";
	theApp.m_pMainWnd->SendMessage(UM_ADDFRIEND_CHOICE,(WPARAM)choice);
	theApp.m_pMainWnd->SendMessage(UM_ADDFRIEND,(WPARAM)psa,lRecvIp);
}
