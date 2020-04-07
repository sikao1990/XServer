#include "Manager.h"
#include "SvrCfgMgr.h"
#include "LogicMgr.h"
#include "NetConnMgr.h"
#include "PluginMgr.h"
#include "MissionMgr.h"
#include "NetServer.h"

Manager::Manager()
{
	
}

Manager::~Manager()
{
	
}

int Manager::Init()
{
	//初始化
	ReadCfgFromFile(m_pSvrCfg);
	//插件初始化
	m_pPluginMgr->Init(m_pSvrCfg);
	//DB连接,日志服等服务器链接初始化
	m_pRemoteMgr->Init(m_pSvrCfg);
	m_pLogicMgr->Init(m_pSvrCfg);
	m_pMissionMgr->Init(m_pSvrCfg);
	m_pNetServer->Init(m_pSvrCfg,m_pLogicMgr,m_pMissionMgr);
	
	this->UpdateInterface(m_pPluginMgr);
	m_pNetServer->UpdateInterface(m_pPluginMgr);
	m_pRemoteMgr->UpdateInterface(m_pPluginMgr);
	m_pLogicMgr->UpdateInterface(m_pPluginMgr);
	m_pMissionMgr->UpdateInterface(m_pPluginMgr);
	
	//ReqConnectRemote
	//WaitStausComplate();
	
	//ReqConnectRemote
	//WaitStausComplate();
	//XConnect(m_pNetServer,SINAL,m_pRemoteMgr,SLOT);
	return 0;
}

void Manager::MainLoop()
{
	unsigned long long ullTime = 0;//当前时间(毫米级)
	WaitStausComplate();
	while(this->m_bLoopCtrl){//加锁与否
		//插件系统更新
		if(this->m_bNeedUpdate){//加锁与否
			//检查插件路径是否合法
			m_pPluginMgr->Update(ullTime,m_szPlugFilepath);
			this->UpdateInterface(m_pPluginMgr);
			m_pNetServer->UpdateInterface(m_pPluginMgr);
			m_pRemoteMgr->UpdateInterface(m_pPluginMgr);
			m_pLogicMgr->UpdateInterface(m_pPluginMgr);
			m_pMissionMgr->UpdateInterface(m_pPluginMgr);
			this->m_bNeedUpdate = false;
		}
		//检查其他服务器连接状态
		m_pRemoteMgr->CheckAllRemoteServerStatus();
		//接收并派发客户端数据
		m_pNetServer->Update(ullTime);
		//接收并派发各服务器数据
		m_pRemoteMgr->Update(ullTime);	
		//地图重新加载(凌晨指定时间),战斗更新
		m_pMissionMgr->Update(ullTime);			
		//更新管理对象集合->游戏事件管理、日志管理
		m_pLogicMgr->Update(ullTime);
		
		this->Update(ullTime);
	}
}

void Manager::SignalComplateStatus(int s)
{
	//释放信号量
}

void Manager::WaitStausComplate()
{
	//获取信号量
}

void Manager::HandleRemoteData(RemoteConn* pRemote,void* pMsg,long nMsgLen)
{
	//管理对象集合初始化
	//m_pLogicMgr->InitFromDB(pMsg,nMsgLen);
	//m_pSceneMgr->InitFromDB(pMsg,nMsgLen);
	//m_pNetServer->InitFromDB(pMsg,nMsgLen);
	//玩家、远程连接、任务、逻辑对象
}

void Manager::Update(unsigned long long t)
{
	
}

bool Manager::ReadCfgFromFile(SvrCfgMgr* pCfgMgr)
{
	return true;
}

int Manager::UpdateInterface(PluginMgr* pPlugMgr)
{
	return 0;
}
