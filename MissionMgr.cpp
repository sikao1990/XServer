#include "MissionMgr.h"

MissionMgr::~MissionMgr()
{
	
}

int MissionMgr::Init(SvrCfgMgr* pCfgMgr)
{
	return 0;
}

int MissionMgr::InitFromDB(void* pBuf,long len)
{
	return 0;
}

int MissionMgr::Update(unsigned long long t)
{
	return 0;
}

int MissionMgr::UpdateInterface(PluginMgr* pPlugMgr)
{
	return 0;
}

int MissionMgr::ReqNewMission(Player* pPlayer)
{
	return 0;
}

void MissionMgr::ComplateMission(int nMission,Player* pPlayer)
{
	
}
