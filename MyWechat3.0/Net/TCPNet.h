#pragma once
#include "inet.h"
class TCPNet :public INet
{
public:
	TCPNet(void);
	~TCPNet(void);
public:
	bool InitNetWork();
	void UnInitNetWork();
	bool SendData(char* szbuf,int nlen);

};

