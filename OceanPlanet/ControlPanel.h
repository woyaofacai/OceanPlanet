// ControlPanel.h: interface for the ControlPanel class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONTROLPANEL_H__2AA87AAF_6B1C_41A2_BF7D_66E36F1E8C1B__INCLUDED_)
#define AFX_CONTROLPANEL_H__2AA87AAF_6B1C_41A2_BF7D_66E36F1E8C1B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <hge.h>
#include <hgefont.h>
#include <hgesprite.h>
#include <hgeguictrls.h>

#include "constants.h"
#include "ResourceFactory.h"
#include "TotalScoreAnimation.h"
#include "GameButton.h"
#include "RunningStateData.h"
#include "MenuButton.h"

extern HGE* hge;
class RunningComponent;

class ControlPanel  
{
	friend class ChangeWeaponButton;
public:
	ControlPanel(RunningComponent*);
	virtual ~ControlPanel();
	//static ControlPanel* GetInstance();
	AddScore(int score);
	Update(float);
	Draw();
private:
	hgeSprite* dollarSprite;
	hgeSprite* needleSprite;
	hgeSprite* bombSprite;
	TotalScoreAnimation* totalScoreAnimation;
	hgeFont* weaponCountFont;
	hgeSprite* lifeHeartSprite;
	float elapsedTime;
	hgeFont* leftTimeFnt;
	RunningComponent* component;
	hgeSprite* leftTimeSprite, *taskGoalSprite;
	MenuButton changeWeaponButton;
};

#endif // !defined(AFX_CONTROLPANEL_H__2AA87AAF_6B1C_41A2_BF7D_66E36F1E8C1B__INCLUDED_)
