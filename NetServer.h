#ifndef __NetServer_H__
#define __NetServer_H__

class SvrCfgMgr;
class LogicMgr;
class PluginMgr;
class MissionMgr;
class NetServer
{
public:
	NetServer();
	virtual ~NetServer();
	virtual int Init(SvrCfgMgr* pCfgMgr,LogicMgr* pLogicMgr,MissionMgr* pMission);
	virtual int InitFromDB(void* pBuf,long len);
	virtual int UpdateInterface(PluginMgr* pPlugMgr);
	int Update(unsigned long long t);
	int signal_SendMsgToRemote(const char* pSvrName,int msgID,void* pbuf,long nMsgLen);
protected:
	LogicMgr*	m_pLogicMgr;
	MissionMgr* m_pMission;
};

#endif	// NetServer.h
