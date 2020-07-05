#ifndef _PACKDEF_H_
#define _PACKDEF_H_

#define _DEF_PORT 1234
#define _DEF_PORT_CLIENT 1235
#define _DEF_PORT_SERVER 1236
#define _DEF_PACKSIZE 4096
#define _DEF_SIZE 45
#define _DEF_BUFFERSIZE 1024
#define _DEF_IDSIZE      20
#define _DEF_PASSWORDSIZE 40
#define _DEF_SERVER_IP  "192.168.75.1"
#define MAXPATH   260
#define _DEF_FILECONTENTSIZE  2048
enum {CLIENT ,SERVER};
typedef char PackType;

//消息
#define UM_ONLINEMSG     WM_USER +1		//上线
#define UM_OFFLINEMSG    WM_USER +2		//下线
#define UM_DATAINFOMSG   WM_USER +3		//聊天信息
#define UM_CHANGEPOS     WM_USER +4		//窗口抖动
#define UM_REGISTERMSG   WM_USER +5		//注册
#define UM_LOGINMSG      WM_USER +6		//登录
#define UM_ADDFRIEND     WM_USER +7		//添加好友
#define UM_DELFRIEND     WM_USER +8		//删除好友
#define UM_ADDFRIEND_CHOICE WM_USER +9   //确认是否同意添加好友
//#define UM_ADDFRIEND_TRUE WM_USER +10   //确认对方以及同意添加好友  
#define UM_RECVFILEMSG	 WM_USER +10      //确认是否同意接收文件
//协议
#define _DEF_PROTOCOL_BASE   10
#define _DEF_PROTOCOL_ONLINE_RQ   _DEF_PROTOCOL_BASE + 1	//上线请求
#define _DEF_PROTOCOL_ONLINE_RS   _DEF_PROTOCOL_BASE + 2	//上线请求回复

#define _DEF_PROTOCOL_OFFLINE_RQ   _DEF_PROTOCOL_BASE +3	//下线请求

#define _DEF_PROTOCOL_DATAINFO_RQ   _DEF_PROTOCOL_BASE +4	//数据发送请求
#define _DEF_PROTOCOL_DATAINFO_RS   _DEF_PROTOCOL_BASE +5	//数据发送请求回复

#define _DEF_PROTOCOL_REGISTER_RQ  _DEF_PROTOCOL_BASE +6	//注册请求
#define _DEF_PROTOCOL_REGISTER_RS  _DEF_PROTOCOL_BASE +7	//注册回复

#define _DEF_PROTOCOL_LOGIN_RQ  _DEF_PROTOCOL_BASE +8	//登录请求
#define _DEF_PROTOCOL_LOGIN_RS  _DEF_PROTOCOL_BASE +9	//登录回复

#define _DEF_PROTOCOL_CHANGEPOS	 _DEF_PROTOCOL_BASE +10   //窗口抖动

#define _DEF_PROTOCOL_ADDFRIEND_RQ  _DEF_PROTOCOL_BASE +11  //添加好友
#define _DEF_PROTOCOL_ADDFRIEND_RS  _DEF_PROTOCOL_BASE +12  //添加好友

#define _DEF_PROTOCOL_DELFRIEND_RQ  _DEF_PROTOCOL_BASE +13   //删除好友
#define _DEF_PROTOCOL_DELFRIEND_RS  _DEF_PROTOCOL_BASE +14   //删除好友

#define _DEF_PROTOCOL_FILEINFO_RQ   _DEF_PROTOCOL_BASE +15	//文件信息请求

#define _DEF_PROTOCOL_FILECONTENT_RQ   _DEF_PROTOCOL_BASE +16	//文件内容请求
#define _DEF_PROTOCOL_FILECONTENT_RS   _DEF_PROTOCOL_BASE +17	//文件内容请求回复
//协议包
struct STRU_DEL
{
	PackType m_nType;
	char     m_szName[_DEF_SIZE];
	char m_sUserId[_DEF_IDSIZE];
	long     m_lDeldIp;
};
struct STRU_ADD
{
	PackType m_nType;
	char     m_szName[_DEF_SIZE];
	char     m_sUserId[_DEF_IDSIZE];
	long     m_lAddIp;
};
struct STRU_LOGIN
{
	PackType m_nType;
	char     m_szName[_DEF_SIZE];
	char m_sUserId[_DEF_IDSIZE];
	char m_sUserPassword[_DEF_PASSWORDSIZE];

};
struct STRU_REGISTER
{
	PackType m_nType;
	char     m_szName[_DEF_SIZE];
	char m_sUserId[_DEF_IDSIZE];
	char m_sUserPassword[_DEF_PASSWORDSIZE];
};
struct STRU_ONLINE
{
	PackType m_nType;
	char     m_szName[_DEF_SIZE];
};

struct STRU_OFFLINE
{
	PackType m_nType;
};


struct STRU_DATAINFO
{
	PackType m_nType;
	char     m_szBuf[_DEF_BUFFERSIZE];
	long      m_nSeq;
	long     m_lAddId;
};

struct STRU_CHANGEPOS
{
	PackType m_nType;
	long     m_lAddId;
};
struct STRU_FILEHEADER
{
	char m_strFileName[MAXPATH];
	long m_nFileSize;
};
struct STRU_FILECONTENT
{
	char m_szFileContent[_DEF_FILECONTENTSIZE]; //包内容
};
struct STRU_FILETOFIREND
{
	PackType m_nType;
	long     m_lAddId;
	STRU_FILEHEADER m_FileHeader;
};
struct STRU_RECVFILEFROMSEVER
{
	PackType m_nType;
	STRU_FILEHEADER m_FileHeader;
};
struct STRU_RULST
{
	char m_szRulst[MAXPATH];
	int m_nRulst;
};
#endif