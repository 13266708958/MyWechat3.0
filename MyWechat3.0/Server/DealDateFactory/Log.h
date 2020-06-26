#pragma once
#include"DealDateFactory.h"
class Log :public DealDateFactory
{
public:
	Log(void);
	~Log(void);
public:
	void DealDate(long lRecvIp,char *szbuf);
};