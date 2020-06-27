#pragma once
#include"PackDef.h"
#include"Log.h"
#include"Reg.h"
class DealDateStrategy
{
public:
	DealDateFactory * m_pDealDateFactory;
public:
	DealDateStrategy(void){}
	DealDateFactory *CreateDealDateStrategy(char *szbuf){
		PackType *pType =  (PackType *)szbuf;
		switch (*pType)
		{
		case _DEF_PROTOCOL_LOGIN_RQ://��¼����
			m_pDealDateFactory = new Log();
			break;
		case _DEF_PROTOCOL_REGISTER_RQ://ע������
			m_pDealDateFactory = new Reg();
			break;

		}
		return m_pDealDateFactory;
	}
	~DealDateStrategy(void){}

};

