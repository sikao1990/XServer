#ifndef __Manager_H__
#define __Manager_H__

class RemoteConn;
class SvrCfgMgr;
class LogicMgr;
class NetConnMgr;
class NetServer;
class MissionMgr;
class PluginMgr;
class Manager
{
public:
	Manager();
	virtual ~Manager();
	virtual int Init();
public:	
	void SignalComplateStatus(int s);//
	void WaitStausComplate();
	
	virtual void HandleRemoteData(RemoteConn* pRemote,void* pMsg,long nMsgLen);
protected:
	void MainLoop();
	virtual int UpdateInterface(PluginMgr* pPlugMgr);
	virtual void Update(unsigned long long t);
	virtual bool ReadCfgFromFile(SvrCfgMgr* pCfgMgr);
protected:
	SvrCfgMgr*	m_pSvrCfg;
	LogicMgr*	m_pLogicMgr;
	NetConnMgr*	m_pRemoteMgr;
	NetServer*	m_pNetServer;
	MissionMgr*	m_pMissionMgr;
	PluginMgr* 	m_pPluginMgr;
	//定时器管理器
	//TimerMgr* m_pTimerMgr;
private:
	bool		m_bNeedUpdate;
	bool 		m_bLoopCtrl;
	char		m_szPlugFilepath[128];
};

#endif // Manager.h
