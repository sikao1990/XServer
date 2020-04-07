#ifndef __Mission_H__
#define __Mission_H__

class Player;
class Mission
{
public:
	virtual ~Mission(){}
	virtual int JoinMission(Player* pPlayer) = 0;
	virtual int QuitMission(Player* pPlayer) = 0;
	virtual int Update(unsigned long long t) = 0;
	virtual int GetMissionNo() = 0;
};

#endif	// Mission.h
