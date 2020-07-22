#pragma once
#include"PackDef.h"
#include"OnLine.h"
#include"AddFriendRQ.h"
#include"AddFriendRS.h"
#include"ChangePos.h"
#include"DateInfo.h"
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
		case _DEF_PROTOCOL_ONLINE_RS://登录请求
			m_pDealDateFactory = new OnLine();
			break;
		case _DEF_PROTOCOL_ADDFRIEND_RQ://添加好友请求
			m_pDealDateFactory = new AddFriendRQ();
			break;
		case _DEF_PROTOCOL_ADDFRIEND_RS://添加好友回复
			m_pDealDateFactory = new AddFriendRS();
			break;
		case _DEF_PROTOCOL_CHANGEPOS://窗口震动
			m_pDealDateFactory = new ChangePos();
			break;
		case _DEF_PROTOCOL_DATAINFO_RQ://发送数据
			m_pDealDateFactory = new DateInfo();
			break;
		}
		return m_pDealDateFactory;
	}
	~DealDateStrategy(void){}

};

