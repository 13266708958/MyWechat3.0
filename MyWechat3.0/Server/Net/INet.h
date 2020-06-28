#pragma once

#include <process.h>
#include"PackDef.h"
#include"Server.h"

#include <winsock2.h>  
#include <mstcpip.h> 
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