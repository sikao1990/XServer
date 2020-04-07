#ifndef __PluginMgr_H__
#define __PluginMgr_H__

class SvrCfgMgr;
class PluginMgr
{
public:
	virtual ~PluginMgr();
	virtual int Init(SvrCfgMgr* pCfgMgr);
	virtual int Update(unsigned long long ullTime,const char* pFilePath);
protected:	
};

#endif	//PluginMgr.h
