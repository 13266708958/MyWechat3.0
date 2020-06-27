#pragma once
#include"PackDef.h"
#include"OnLine.h"
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
		case _DEF_PROTOCOL_ONLINE_RS://��¼����
			m_pDealDateFactory = new OnLine();
			break;
		case _DEF_PROTOCOL_REGISTER_RQ://ע������
			
			break;

		}
		return m_pDealDateFactory;
	}
	~DealDateStrategy(void){}

};

