#pragma once
#include <winsock2.h>
#include <ws2ipdef.h>
#include <process.h>
#include"PackDef.h"
#include"Client.h"
class INet
{
public:
	INet(){}
	virtual ~INet(){}
public:
	virtual bool InitNetWork() =0;
	virtual void UnInitNetWork() =0;
	virtual bool SendData(long lSendIp,char *szbuf,int nLen){ return true;};
	
};