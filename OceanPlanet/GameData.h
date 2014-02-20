// GameData.h: interface for the GameData class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GAMEDATA_H__EB024E46_DF6F_4A26_BDAE_F0DE52C78CA4__INCLUDED_)
#define AFX_GAMEDATA_H__EB024E46_DF6F_4A26_BDAE_F0DE52C78CA4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class GameData  
{
public:
	GameData();
	virtual ~GameData();
	void DecreaseNeedle();
	void DecreaseBomb();
private:
	int needleLeft;
	int bombleft;
	int score;
	int task;
	int timeleft;
};

#endif // !defined(AFX_GAMEDATA_H__EB024E46_DF6F_4A26_BDAE_F0DE52C78CA4__INCLUDED_)
