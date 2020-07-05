// DialogChoice.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Client.h"
#include "DialogChoice.h"
#include "afxdialogex.h"


// CDialogChoice �Ի���

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


// CDialogChoice ��Ϣ�������


void CDialogChoice::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	char *choice = "YES";
	theApp.m_pMainWnd->SendMessage(UM_ADDFRIEND_CHOICE,(WPARAM)choice);
	EndDialog(IDOK);
}


void CDialogChoice::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	char *choice = "NO";
	theApp.m_pMainWnd->SendMessage(UM_ADDFRIEND_CHOICE,(WPARAM)choice);
	EndDialog(IDOK);
}
