#ifndef __NetConnMgr_H__
#define __NetConnMgr_H__

#include "RemoteConn.h"

/*
	热更管理(本机TCP/UDP)
	DB服连接管理
	Logon连接管理
	...
*/
class RemoteConn;
class SvrCfgMgr;
class PluginMgr;
class Manager;
class NetConnMgr
{
public:
	NetConnMgr(Manager* pManager);
	virtual ~NetConnMgr();
	virtual int Init(SvrCfgMgr* pCfgMgr);
	virtual int UpdateInterface(PluginMgr* pPlugMgr);
	int slot_SendMsgToRemote(const char* pSvrName,int msgID,void* pbuf,long nMsgLen);
	//检查远程服务器列表连接情况
	int CheckAllRemoteServerStatus();
	//读取远程服务器数据并派发
	void Update(unsigned long long t);
	//更新连接
	void UpdateConnect();//单独线程中处理
protected:
	Manager* m_pManager
};

#endif	// NetConnMgr.h
