#pragma once

#include"PackDef.h"
#include "afxwin.h"
// CDialogChat 对话框

class CDialogChat : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogChat)

public:
	CDialogChat(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDialogChat();

// 对话框数据
	enum { IDD = IDD_DIALOG_CHAT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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
