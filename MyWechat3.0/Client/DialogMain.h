#pragma once
#include "afxcmn.h"


// CDialogMain �Ի���

class CDialogMain : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogMain)

public:
	CDialogMain(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDialogMain();
	virtual BOOL OnInitDialog();
// �Ի�������
	enum { IDD = IDD_DIALOG_MAIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_lFriendList;
};
