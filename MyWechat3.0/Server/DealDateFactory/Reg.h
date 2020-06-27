#pragma once
#include"DealDateFactory.h"
class Reg :public DealDateFactory
{
public:
	Reg(void);
	~Reg(void);
public:
	void DealDate(long lRecvIp,char *szbuf);
};