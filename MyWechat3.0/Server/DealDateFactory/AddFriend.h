#pragma once
#include"DealDateFactory.h"
class AddFriend :public DealDateFactory
{
public:
	AddFriend(void);
	~AddFriend(void);
public:
	void DealDate(long lRecvIp,char *szbuf);
};