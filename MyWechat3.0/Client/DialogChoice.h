#pragma once


// CDialogChoice �Ի���
#include"PackDef.h"
class CDialogChoice : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogChoice)

public:
	CDialogChoice(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDialogChoice();

// �Ի�������
	enum { IDD = IDD_DIALOG_CHOICE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
