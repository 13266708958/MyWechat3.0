#pragma once

#include"PackDef.h"
#include "afxwin.h"
// CDialogChat �Ի���

class CDialogChat : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogChat)

public:
	CDialogChat(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDialogChat();

// �Ի�������
	enum { IDD = IDD_DIALOG_CHAT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton4();
public:
	void ChangePos();
public:
	CListBox m_lShowList;
	CString m_nEdit;
};
