#pragma once
#include"DealDateFactory.h"
class AddFriendRS :public DealDateFactory
{
public:
	AddFriendRS(void);
	~AddFriendRS(void);
public:
	void DealDate(long lRecvIp,char *szbuf);
};