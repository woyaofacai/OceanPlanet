// RunningStateData.h: interface for the RunningStateData class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RUNNINGSTATEDATA_H__9602EBDD_F45F_4656_AB39_CD09F57F0D87__INCLUDED_)
#define AFX_RUNNINGSTATEDATA_H__9602EBDD_F45F_4656_AB39_CD09F57F0D87__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "constants.h"

class RunningStateData  
{
public:
	int ChangeWeaponType();
	RunningStateData();
//	RunningStateData(RunningStateData& model);
	virtual ~RunningStateData();
	int BombCount;
	int NeedleCount;
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
	bool ArcadeMode;
};

#endif // !defined(AFX_RUNNINGSTATEDATA_H__9602EBDD_F45F_4656_AB39_CD09F57F0D87__INCLUDED_)
