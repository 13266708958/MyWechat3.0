
// Client.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������
#include"IMediator.h"
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
public:
	
	DECLARE_MESSAGE_MAP()
	virtual int ExitInstance();
};

extern CClientApp theApp;