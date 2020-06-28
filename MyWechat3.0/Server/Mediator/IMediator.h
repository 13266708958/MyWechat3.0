#pragma once

class IMediator
{
public:
	IMediator(void){}
	virtual ~IMediator(void){}
public:
	virtual bool Open() =0;
	virtual void Close() =0;
	virtual bool SendData(long lSendIp,char *szbuf,int nLen){return true;};
	virtual void DealData(long lRecvIp,char *szbuf){};

};

