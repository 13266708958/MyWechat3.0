#pragma once
#include"PackDef.h"
#include<list>
#include<map>
#include"Client.h"
using namespace std;
class DealDateFactory
{
public:
	DealDateFactory(void){}
	virtual ~DealDateFactory(void){}
public:
	virtual void DealDate(long lRecvIp,char *szbuf) = 0;
};

