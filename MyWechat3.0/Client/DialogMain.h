#pragma once
#include "afxcmn.h"
#include"PackDef.h"
#include"Client.h"
#include"DialogChat.h"
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
	afx_msg void OnBnClickedButton1();
	CString m_sFriendId;
	bool m_bAddFalge;
	std::map<CString,CDialogChat *> m_mIdtoChat;//���ں�id��ӳ��
public:
	LRESULT OnAddFriend(WPARAM W,LPARAM L);
	LRESULT OnAddFriendChoice(WPARAM W,LPARAM L);
	afx_msg void OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult);
	CDialogChat *GetDlgChat(CString ChatIp);
};
