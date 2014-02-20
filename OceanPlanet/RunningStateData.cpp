// RunningStateData.cpp: implementation of the RunningStateData class.
//
//////////////////////////////////////////////////////////////////////

#include "RunningStateData.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

RunningStateData::RunningStateData()
{
	CurrentScore = 0;
	CurrentWeaponType = 0;
	BombCountDown = 10;
	int i;
	for(i = 0; i < 6; i++) {
		propProbabilities[i] = 0;
	}
	CurrentState = FIGHT_STATE;
	BombCountDown = 10;
	ArcadeMode = false;
}

RunningStateData::~RunningStateData()
{

}

/*
RunningStateData::RunningStateData(RunningStateData& model)
{
	BombCount = model.BombCount;
	NeedleCount = model.NeedleCount;
	int CurrentScore;
	int GoalScore;
	int Life;
	int TimeLimit;
	int AllowWeaponType;
	int CurrentWeaponType;
	int CurrentState;
	int FishProbability;
	int propProbabilities[6];
	int MaxTreasureScore;
	float MinFishVelocity;
	float MaxFishVelocity;
	float NeedleVelocity;
	int BombCountDown; // bomb倒计时的时间
	int Barrier;
}
*/

int RunningStateData::ChangeWeaponType()
{
	return 0;
}
