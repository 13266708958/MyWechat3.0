// DialogMain.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Client.h"
#include "DialogMain.h"
#include "afxdialogex.h"


// CDialogMain �Ի���

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


// CDialogMain ��Ϣ�������


BOOL CDialogMain::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_lFriendList.InsertColumn(0,_T("ID"),0,150);
	m_lFriendList.InsertColumn(1,_T("ONLINE"),0,100);
	m_lFriendList.InsertColumn(2,_T("IP"),0,150);
	m_lFriendList.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	return TRUE;
}


void CDialogMain::OnBnClickedButton1()//��Ӻ���
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	STRU_ADD sa;
	sa.m_nType =_DEF_PROTOCOL_ADDFRIEND_RQ;
	gethostname(sa.m_szName,sizeof(sa.m_szName));
	UpdateData(TRUE);
	strcpy_s(sa.m_sUserId,_DEF_IDSIZE ,m_sFriendId);
	UpdateData(FALSE);
	
	//���û�Ŀǰ�ĺ����б��в����Ƿ���ڸ��û�

	theApp.m_pUDPMediator->SendData(inet_addr(_DEF_SERVER_IP),(char *)&sa,sizeof(sa));
}
