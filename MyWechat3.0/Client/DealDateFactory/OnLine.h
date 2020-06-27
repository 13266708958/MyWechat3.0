#pragma once
#include"DealDateFactory.h"
class OnLine :public DealDateFactory
{
public:
	OnLine(void);
	~OnLine(void);
public:
	void DealDate(long lRecvIp,char *szbuf);
};