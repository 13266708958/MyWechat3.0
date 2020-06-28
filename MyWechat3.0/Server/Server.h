
// Server.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号
#include"IMediator.h"
#include"CMySql.h"
#include<list>
#include<map>
// CServerApp:
// 有关此类的实现，请参阅 Server.cpp
//

class CServerApp : public CWinApp
{
public:
	CServerApp();

// 重写
public:
	virtual BOOL InitInstance();

// 实现
public:
	IMediator * m_pUDPMediator;
	IMediator * m_pTCPMediator;
	CMySql m_Sql;
public:
	static std::list<long > addrList;
	static std::map<CString ,long > m_mIdToAddr;
	
	DECLARE_MESSAGE_MAP()
};

extern CServerApp theApp;