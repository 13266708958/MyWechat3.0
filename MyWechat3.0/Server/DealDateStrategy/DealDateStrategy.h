#pragma once
#include"PackDef.h"
#include"Log.h"
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
		}
		return m_pDealDateFactory;
	}
	~DealDateStrategy(void){}

};

