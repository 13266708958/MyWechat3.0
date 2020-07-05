// DialogChoice.cpp : 实现文件
//

#include "stdafx.h"
#include "Client.h"
#include "DialogChoice.h"
#include "afxdialogex.h"


// CDialogChoice 对话框

IMPLEMENT_DYNAMIC(CDialogChoice, CDialogEx)

CDialogChoice::CDialogChoice(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialogChoice::IDD, pParent)
{

}

CDialogChoice::~CDialogChoice()
{
}

void CDialogChoice::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDialogChoice, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDialogChoice::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDialogChoice::OnBnClickedButton2)
END_MESSAGE_MAP()


// CDialogChoice 消息处理程序


void CDialogChoice::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	char *choice = "YES";
	theApp.m_pMainWnd->SendMessage(UM_ADDFRIEND_CHOICE,(WPARAM)choice);
	EndDialog(IDOK);
}


void CDialogChoice::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	char *choice = "NO";
	theApp.m_pMainWnd->SendMessage(UM_ADDFRIEND_CHOICE,(WPARAM)choice);
	EndDialog(IDOK);
}
