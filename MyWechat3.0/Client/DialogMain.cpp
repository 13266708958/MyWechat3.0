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
{

}

CDialogMain::~CDialogMain()
{
}

void CDialogMain::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_lFriendList);
}


BEGIN_MESSAGE_MAP(CDialogMain, CDialogEx)
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
