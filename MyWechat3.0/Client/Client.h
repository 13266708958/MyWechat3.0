
// Client.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号
#include"IMediator.h"
#include"DialogChat.h"
#include"CMySql.h"
#include<list>
#include<map>
// CClientApp:
// 有关此类的实现，请参阅 Client.cpp
//

class CClientApp : public CWinApp
{
public:
	CClientApp();

	// 重写
public:
	virtual BOOL InitInstance();

	// 实现
public:
	IMediator * m_pUDPMediator;
	IMediator * m_pTCPMediator;
	CDialogChat *m_dlgChat;
	CMySql m_Sql;
	CString m_sID;
public:

	DECLARE_MESSAGE_MAP()
	virtual int ExitInstance();
public:
	static std::list<CString > m_lFriendList;
	static std::map<CString ,long > m_mIdToAddr;

};

extern CClientApp theApp;