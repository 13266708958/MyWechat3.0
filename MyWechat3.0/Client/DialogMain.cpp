// DialogMain.cpp : 实现文件
//

#include "stdafx.h"
#include "Client.h"
#include "DialogMain.h"
#include "afxdialogex.h"


// CDialogMain 对话框

IMPLEMENT_DYNAMIC(CDialogMain, CDialogEx)

CDialogMain::CDialogMain(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialogMain::IDD, pParent)
	, m_sFriendId(_T("123456"))
{

}

CDialogMain::~CDialogMain()
{
}

void CDialogMain::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_lFriendList);
	DDX_Text(pDX, IDC_EDIT1, m_sFriendId);
}


BEGIN_MESSAGE_MAP(CDialogMain, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDialogMain::OnBnClickedButton1)
	ON_MESSAGE(UM_ADDFRIEND,&CDialogMain::OnAddFriend)
	ON_MESSAGE(UM_ADDFRIEND_CHOICE,&CDialogMain::OnAddFriendChoice)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, &CDialogMain::OnNMDblclkList1)
END_MESSAGE_MAP()


// CDialogMain 消息处理程序
LRESULT CDialogMain::OnAddFriendChoice(WPARAM W,LPARAM L)
{
	char *strtemp =(char *)W;
	char *yes ="YES";
	if(strcmp(strtemp,yes) == 0)
	{
		m_bAddFalge = true;
	}
	return 0;
}
LRESULT CDialogMain::OnAddFriend(WPARAM W,LPARAM L)
{
	STRU_ADD *psa =(STRU_ADD *)W;
	if(m_bAddFalge == true)
	{
		auto ite = theApp.m_lFriendList.begin();
		while(ite != theApp.m_lFriendList.end())
		{
			if(*ite == psa->m_sUserId)
				return 0;
			ite++;
		}
		theApp.m_lFriendList.push_front(psa->m_sUserId);
		theApp.m_mIdToAddr[psa->m_sUserId] = psa->m_lAddIp;
		in_addr  addr;
		addr.S_un.S_addr = psa->m_lAddIp;
		char *IP = inet_ntoa(addr);
		char *ID =(char *)psa->m_sUserId;
		char *ONLINE = "在线";
		m_lFriendList.InsertItem(0,ID);//在列表头插入
		m_lFriendList.SetItemText(0,1,IP);
		m_lFriendList.SetItemText(0,2,ONLINE);
	}
	m_bAddFalge = false;
	return 0;
}
BOOL CDialogMain::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_lFriendList.InsertColumn(0,_T("ID"),0,150);
	m_lFriendList.InsertColumn(1,_T("ONLINE"),0,100);
	m_lFriendList.InsertColumn(2,_T("IP"),0,150);
	m_lFriendList.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	return TRUE;
}


void CDialogMain::OnBnClickedButton1()//添加好友
{
	// TODO: 在此添加控件通知处理程序代码
	STRU_ADD sa;
	sa.m_nType =_DEF_PROTOCOL_ADDFRIEND_RQ;
	gethostname(sa.m_szName,sizeof(sa.m_szName));
	UpdateData(TRUE);
	strcpy_s(sa.m_sUserId,_DEF_IDSIZE ,m_sFriendId);
	UpdateData(FALSE);
	
	//在用户目前的好友列表中查找是否存在该用户
	theApp.m_pUDPMediator->SendData(inet_addr(_DEF_SERVER_IP),(char *)&sa,sizeof(sa));
}

CDialogChat *CDialogMain::GetDlgChat(CString ChatIp)
{
	CDialogChat *pDlg;
	pDlg = m_mIdtoChat[ChatIp];
	if(!pDlg)
	{
		pDlg = new CDialogChat;
		pDlg->Create(IDD_DIALOG_CHAT);
		m_mIdtoChat[ChatIp] = pDlg;
		pDlg->SetWindowText(ChatIp);
	}
	pDlg->ShowWindow(SW_SHOW);
	return pDlg;
}

void CDialogMain::OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	CString ChatIp =m_lFriendList.GetItemText(pNMItemActivate->iItem,1);
	//查看是否有窗口
	theApp.m_dlgChat = GetDlgChat(ChatIp);
	*pResult = 0;
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}
