#pragma once
#include "afxcmn.h"
#include"PackDef.h"
#include"Client.h"
#include"DialogChat.h"
// CDialogMain 对话框

class CDialogMain : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogMain)

public:
	CDialogMain(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDialogMain();
	virtual BOOL OnInitDialog();
	// 对话框数据
	enum { IDD = IDD_DIALOG_MAIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_lFriendList;
	CString m_sFriendId;
	bool m_bAddFalge;
	std::map<CString,CDialogChat *> m_mIdtoChat;//窗口和id的映射
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton3();
public:
	LRESULT OnAddFriend(WPARAM W,LPARAM L);
	LRESULT OnAddFriendChoice(WPARAM W,LPARAM L);
	LRESULT OnChangePos(WPARAM W,LPARAM L);
	LRESULT DataInfoLine(WPARAM W,LPARAM L);
	LRESULT OnLineMsg(WPARAM W,LPARAM L);//上线
public:
	afx_msg void OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult);
	CDialogChat *GetDlgChat(CString ChatIp);
	
};
