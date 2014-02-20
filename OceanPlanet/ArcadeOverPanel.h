// ArcadeOverPanel.h: interface for the ArcadeOverPanel class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ARCADEOVERPANEL_H__D318CF76_53BC_434D_8B44_031182669309__INCLUDED_)
#define AFX_ARCADEOVERPANEL_H__D318CF76_53BC_434D_8B44_031182669309__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TaskResultPanel.h"
#include <hgesprite.h>
#include <hgefont.h>
#include <cstdio>
#include "MenuButton.h"

class ArcadeOverPanel : public TaskResultPanel  
{
public:
	ArcadeOverPanel(GameComponent*,int score);
	virtual ~ArcadeOverPanel();
	virtual Update(float);
	virtual Draw();
private:
	int scoreWidth;
	int score;
	int scoreTipWidth;
	hgeFont* scoreFnt;
	hgeSprite* fntSprite, *scoreTipSprite;
	MenuButton buttons[2];
};

#endif // !defined(AFX_ARCADEOVERPANEL_H__D318CF76_53BC_434D_8B44_031182669309__INCLUDED_)
