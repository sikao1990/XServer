#ifndef __LogicMgr_H__
#define __LogicMgr_H__

/*
	异步消息管理
	.../业务逻辑
*/

class LogicObj;
class SvrCfgMgr;
class PluginMgr;
class LogicMgr
{
public:
	virtual ~LogicMgr();
	virtual int Init(SvrCfgMgr* pCfgMgr);
	virtual int UpdateInterface(PluginMgr* pPlugMgr);
	virtual int InitFromDB(void* pBuf,long len);
	int Update(unsigned long long t);
};

#endif	// LogicMgr.h
