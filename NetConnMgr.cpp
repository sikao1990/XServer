#include "NetConnMgr.h"
#include "SvrCfgMgr.h"
#include "PluginMgr.h"

NetConnMgr::NetConnMgr(Manager* pManager):m_pManager(pManager)
{
	
}

NetConnMgr::~NetConnMgr()
{
	
}

int NetConnMgr::Init(SvrCfgMgr* pCfgMgr)
{
	return 0;
}

int NetConnMgr::UpdateInterface(PluginMgr* pPlugMgr)
{
	return 0;
}

int NetConnMgr::slot_SendMsgToRemote(const char* pSvrName,int msgID,void* pbuf,long nMsgLen)
{
	return 0;
}

//检查远程服务器列表连接情况
int NetConnMgr::CheckAllRemoteServerStatus()
{
	return 0;
}

//读取远程服务器数据并派发
void NetConnMgr::Update(unsigned long long t)
{
	
}

//更新连接
void NetConnMgr::UpdateConnect()//单独线程中处理
{
	
}
