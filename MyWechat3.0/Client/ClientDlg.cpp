
// ClientDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Client.h"
#include "ClientDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CClientDlg �Ի���



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

// CClientDlg ��Ϣ�������

BOOL CClientDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	if(!theApp.m_pUDPMediator->Open())
	{
		MessageBox(_T("Client UDP can't open !"));
	}
	if(!theApp.m_pTCPMediator->Open())
	{
		MessageBox(_T("Client TCP can't open !"));
	}
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CClientDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
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
void CClientDlg::OnBnClickedButton1()//��¼����
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	STRU_LOGIN sl;
	sl.m_nType = _DEF_PROTOCOL_LOGIN_RQ;//��¼Э����Ϣ
	gethostname(sl.m_szName,sizeof(sl.m_szName));//��ȡ������
	UpdateData(TRUE);
	strcpy_s(sl.m_sUserId,m_sLogID);
	strcpy_s(sl.m_sUserPassword,m_sLogPassword);
	UpdateData(FALSE);
	if(theApp.m_pUDPMediator->SendData(inet_addr(_DEF_SERVER_IP),(char *)&sl,sizeof(sl)))//INADDR_BROADCAST�������㲥
	{
		//GetDlgMain();
	}
}


void CClientDlg::OnBnClickedButton2()//ע�ᰴ��
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	STRU_REGISTER sr;
	sr.m_nType =_DEF_PROTOCOL_REGISTER_RQ;//ע������
	gethostname(sr.m_szName,sizeof(sr.m_szName));
	UpdateData(TRUE);
	strcpy_s(sr.m_sUserId,m_sLogID);
	strcpy_s(sr.m_sUserPassword,m_sLogPassword);
	UpdateData(FALSE);
	if(theApp.m_pUDPMediator->SendData(inet_addr(_DEF_SERVER_IP),(char *)&sr,sizeof(sr)))//INADDR_BROADCAST�������㲥
	{
		//GetDlgMain();
	}
}


void CClientDlg::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	theApp.m_pUDPMediator->Close();
	theApp.m_pTCPMediator->Close();
	CDialogEx::OnClose();
}
