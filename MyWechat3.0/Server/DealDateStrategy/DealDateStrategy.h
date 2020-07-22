#pragma once
#include"PackDef.h"
#include"Log.h"
#include"Reg.h"
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
		case _DEF_PROTOCOL_LOGIN_RQ://登录请求
			m_pDealDateFactory = new Log();
			break;
		case _DEF_PROTOCOL_REGISTER_RQ://注册请求
			m_pDealDateFactory = new Reg();
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

