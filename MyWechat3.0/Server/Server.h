
// Server.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������
#include"IMediator.h"
#include"CMySql.h"
// CServerApp:
// �йش����ʵ�֣������ Server.cpp
//

class CServerApp : public CWinApp
{
public:
	CServerApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
public:
	IMediator * m_pMediator;
	CMySql m_Sql;
	DECLARE_MESSAGE_MAP()
};

extern CServerApp theApp;