// GameModel.h: interface for the GameModel class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GAMEMODEL_H__900A2EC9_07A4_4CFC_B7E0_4555A71859E0__INCLUDED_)
#define AFX_GAMEMODEL_H__900A2EC9_07A4_4CFC_B7E0_4555A71859E0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class GameModel  
{
public:
	GameModel();
	~GameModel();
	int BombCount;
	int NeedleCount;
	int CurrentScore;
	int GoalScore;
	float LeftTime;
	float TotalTime;
};

#endif // !defined(AFX_GAMEMODEL_H__900A2EC9_07A4_4CFC_B7E0_4555A71859E0__INCLUDED_)
