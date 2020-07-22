#pragma once
#include"DealDateFactory.h"
class DateInfo :public DealDateFactory
{
public:
	DateInfo(void);
	~DateInfo(void);
public:
	void DealDate(long lRecvIp,char *szbuf);
};