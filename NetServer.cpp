#include "NetServer.h"
#include <stdio.h>

NetServer::NetServer():m_pLogicMgr(NULL),m_pMission(NULL)
{
	
}

NetServer::~NetServer()
{
	
}

int NetServer::Init(SvrCfgMgr* pCfgMgr,LogicMgr* pLogicMgr,MissionMgr* pMission)
{
	m_pMission = pMission;
	m_pLogicMgr = pLogicMgr;
	return 0;
}

int NetServer::Update(unsigned long long t)
{
	//线程池处理数据获取
	//同步消息处理
	//异步消息队列
	return 0;
}

int NetServer::signal_SendMsgToRemote(const char* pSvrName,int msgID,void* pbuf,long nMsgLen)
{
	return 0;
}

int NetServer::InitFromDB(void* pBuf,long len)
{
	return 0;
}

int NetServer::UpdateInterface(PluginMgr* pPlugMgr)
{
	return 0;
}
