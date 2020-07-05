#include"stdafx.h"
#include"AddFriendRQ.h"
#include"DialogChoice.h"
AddFriendRQ::AddFriendRQ()
{
}
AddFriendRQ::~AddFriendRQ()
{
}
void AddFriendRQ::DealDate(long lRecvIp,char *szbuf)
{
	STRU_ADD *psa =(STRU_ADD *)szbuf;

	CDialogChoice pDlg;
	pDlg.DoModal();

	theApp.m_pMainWnd->SendMessage(UM_ADDFRIEND,(WPARAM)psa,lRecvIp);//psa->m_lAddIp是请求添加好友的用户的地址

	STRU_ADD sa;
	sa.m_nType = _DEF_PROTOCOL_ADDFRIEND_RS;
	sa.m_lAddIp = psa->m_lAddIp;//psa->m_lAddId是请求添加好友的用户的地址
	strcpy_s(sa.m_sUserId,_DEF_IDSIZE,psa->m_sUserId);
	theApp.m_pUDPMediator->SendData(inet_addr(_DEF_SERVER_IP),(char*)&sa,sizeof(sa));

}
