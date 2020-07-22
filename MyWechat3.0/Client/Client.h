
// Client.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������
#include"IMediator.h"
#include"DialogChat.h"
#include"CMySql.h"
#include<list>
#include<map>
// CClientApp:
// �йش����ʵ�֣������ Client.cpp
//

class CClientApp : public CWinApp
{
public:
	CClientApp();

	// ��д
public:
	virtual BOOL InitInstance();

	// ʵ��
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