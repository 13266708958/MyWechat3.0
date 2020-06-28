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
	, m_sFriendId(_T(""))
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
END_MESSAGE_MAP()


// CDialogMain 消息处理程序


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
