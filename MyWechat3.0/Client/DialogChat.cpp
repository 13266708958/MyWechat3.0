// DialogChat.cpp : 实现文件
//

#include "stdafx.h"
#include "Client.h"
#include "DialogChat.h"
#include "afxdialogex.h"


// CDialogChat 对话框

IMPLEMENT_DYNAMIC(CDialogChat, CDialogEx)

CDialogChat::CDialogChat(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialogChat::IDD, pParent)
	, m_nEdit(_T(""))
{

}

CDialogChat::~CDialogChat()
{
}

void CDialogChat::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_lShowList);
	DDX_Text(pDX, IDC_EDIT1, m_nEdit);
}


BEGIN_MESSAGE_MAP(CDialogChat, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDialogChat::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON4, &CDialogChat::OnBnClickedButton4)
END_MESSAGE_MAP()


// CDialogChat 消息处理程序


void CDialogChat::OnBnClickedButton1()//发送
{
	// TODO: 在此添加控件通知处理程序代码
	//取数据
	UpdateData(TRUE);
	//获取ip
	CString strip;
	GetWindowText(strip);
	STRU_DATAINFO sd;
	sd.m_nType =_DEF_PROTOCOL_DATAINFO_RQ;
	strcpy_s(sd.m_szBuf,sizeof(sd.m_szBuf),m_nEdit);
	sd.m_nSeq=0;
	sd.m_lAddId =inet_addr(strip);//发送的ip
	//发送信息
	if(theApp.m_pUDPMediator->SendData(inet_addr(_DEF_SERVER_IP),(char *)&sd,sizeof(sd)))
	{
		m_lShowList.AddString("I Say:");
		m_lShowList.AddString(m_nEdit);
		m_nEdit ="";
		UpdateData(FALSE);
	}
}


void CDialogChat::OnBnClickedButton4()//震动
{
CString strip;
	GetWindowText(strip); 
	STRU_CHANGEPOS sc;
	sc.m_nType =_DEF_PROTOCOL_CHANGEPOS;
	sc.m_lAddId = inet_addr(strip);
	theApp.m_pUDPMediator->SendData(inet_addr(strip),(char *)&sc,sizeof(sc));
}
void CDialogChat::ChangePos()
{
	UINT_PTR UpTimer = SetTimer(1,20000,NULL);
	UINT_PTR DownTimer = SetTimer(1,20000,NULL);
	UINT_PTR LeftTimer = SetTimer(1,20000,NULL);
	UINT_PTR RightTimer = SetTimer(1,20000,NULL);
	for(int i =0;i<=300;i++)
	{
		if(UpTimer)
		{
			RECT rect;
			GetWindowRect(&rect);
			rect.top -=20;
			SetWindowPos( &wndTopMost ,rect.left,rect.top,0,0,SWP_NOSIZE);
		}
		if(DownTimer)
		{
			RECT rect;
			GetWindowRect(&rect);
			rect.top +=20;
			SetWindowPos( &wndTopMost ,rect.left,rect.top,0,0,SWP_NOSIZE);
		}
		if(LeftTimer)
		{
			RECT rect;
			GetWindowRect(&rect);
			rect.left -=20;
			SetWindowPos( &wndTopMost ,rect.left,rect.top,0,0,SWP_NOSIZE);
		}
		if(RightTimer)
		{
			RECT rect;
			GetWindowRect(&rect);
			rect.left +=20;
			SetWindowPos( &wndTopMost ,rect.left,rect.top,0,0,SWP_NOSIZE);
		}
	}
	KillTimer(UpTimer );
	KillTimer(DownTimer );
	KillTimer(LeftTimer );
	KillTimer(RightTimer);
}
