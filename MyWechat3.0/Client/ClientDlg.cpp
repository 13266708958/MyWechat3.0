
// ClientDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Client.h"
#include "ClientDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()

};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)

END_MESSAGE_MAP()


// CClientDlg 对话框



CClientDlg::CClientDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CClientDlg::IDD, pParent)
	, m_sLogID(_T("123456"))
	, m_sLogPassword(_T("123456"))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_sLogID);
	DDV_MaxChars(pDX, m_sLogID, 10);
	DDX_Text(pDX, IDC_EDIT2, m_sLogPassword);
	DDV_MaxChars(pDX, m_sLogPassword, 15);
}

BEGIN_MESSAGE_MAP(CClientDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_MESSAGE(UM_ONLINEMSG,&CClientDlg::OnLineMsg)
	ON_BN_CLICKED(IDC_BUTTON1, &CClientDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CClientDlg::OnBnClickedButton2)

	ON_WM_CLOSE()
END_MESSAGE_MAP()
LRESULT CClientDlg::OnLineMsg(WPARAM W,LPARAM L)
{
	GetDlgMain();
	return 0;
}

// CClientDlg 消息处理程序

BOOL CClientDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	if(!theApp.m_pUDPMediator->Open())
	{
		MessageBox(_T("Client UDP can't open !"));
	}
	if(!theApp.m_pTCPMediator->Open())
	{
		MessageBox(_T("Client TCP can't open !"));
	}
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CClientDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CClientDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CClientDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


CDialogMain * CClientDlg::GetDlgMain()
{
	CDialogMain pDlg;
	theApp.m_pMainWnd = &pDlg;
	CClientDlg::EndDialog(IDOK);
	pDlg.DoModal();
	return &pDlg;
}
void CClientDlg::OnBnClickedButton1()//登录按键
{
	// TODO: 在此添加控件通知处理程序代码
	STRU_LOGIN sl;
	sl.m_nType = _DEF_PROTOCOL_LOGIN_RQ;//登录协议消息
	gethostname(sl.m_szName,sizeof(sl.m_szName));//获取主机名
	UpdateData(TRUE);
	strcpy_s(sl.m_sUserId,m_sLogID);
	strcpy_s(sl.m_sUserPassword,m_sLogPassword);
	UpdateData(FALSE);
	if(theApp.m_pUDPMediator->SendData(inet_addr(_DEF_SERVER_IP),(char *)&sl,sizeof(sl)))//INADDR_BROADCAST局域网广播
	{
		//GetDlgMain();
	}
}


void CClientDlg::OnBnClickedButton2()//注册按键
{
	// TODO: 在此添加控件通知处理程序代码
	STRU_REGISTER sr;
	sr.m_nType =_DEF_PROTOCOL_REGISTER_RQ;//注册请求
	gethostname(sr.m_szName,sizeof(sr.m_szName));
	UpdateData(TRUE);
	strcpy_s(sr.m_sUserId,m_sLogID);
	strcpy_s(sr.m_sUserPassword,m_sLogPassword);
	UpdateData(FALSE);
	if(theApp.m_pUDPMediator->SendData(inet_addr(_DEF_SERVER_IP),(char *)&sr,sizeof(sr)))//INADDR_BROADCAST局域网广播
	{
		//GetDlgMain();
	}
}


void CClientDlg::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	theApp.m_pUDPMediator->Close();
	theApp.m_pTCPMediator->Close();
	CDialogEx::OnClose();
}
