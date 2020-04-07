#ifndef __MissionMgr_H__
#define __MissionMgr_H__

class Player;
class Mission;
class SvrCfgMgr;
class PluginMgr;
class MissionMgr
{
public:
	virtual ~MissionMgr();
	virtual int Init(SvrCfgMgr* pCfgMgr);
	virtual int UpdateInterface(PluginMgr* pPlugMgr);
	virtual int InitFromDB(void* pBuf,long len);
	int Update(unsigned long long t);
	
	virtual int ReqNewMission(Player* pPlayer);
	virtual void ComplateMission(int nMission,Player* pPlayer);
protected:
	//分布式lib
};

#endif	// MissionMgr.h
