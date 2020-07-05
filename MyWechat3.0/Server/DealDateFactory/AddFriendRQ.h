#pragma once
#include"DealDateFactory.h"
class AddFriendRQ :public DealDateFactory
{
public:
	AddFriendRQ(void);
	~AddFriendRQ(void);
public:
	void DealDate(long lRecvIp,char *szbuf);
};