#pragma once


// CDialogChoice 对话框
#include"PackDef.h"
class CDialogChoice : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogChoice)

public:
	CDialogChoice(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDialogChoice();

// 对话框数据
	enum { IDD = IDD_DIALOG_CHOICE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
