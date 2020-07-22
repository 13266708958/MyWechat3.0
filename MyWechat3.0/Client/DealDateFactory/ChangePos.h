#pragma once
#include"DealDateFactory.h"
class ChangePos :public DealDateFactory
{
public:
	ChangePos(void);
	~ChangePos(void);
public:
	void DealDate(long lRecvIp,char *szbuf);
};