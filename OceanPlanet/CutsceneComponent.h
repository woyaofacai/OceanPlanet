// CutsceneComponent.h: interface for the CutsceneComponent class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CUTSCENECOMPONENT_H__A1A1DC64_10BF_4903_BC11_A7906AE0572C__INCLUDED_)
#define AFX_CUTSCENECOMPONENT_H__A1A1DC64_10BF_4903_BC11_A7906AE0572C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Game.h"
#include "GameComponent.h"
#include <hgesprite.h>
#include "ResourceFactory.h"
#include "MenuButton.h"
#include "RunningComponent.h"
extern RunningStateData runningModels[];

extern void ChangeTextureAlpha(HTEXTURE tex, int alpha);

class CutsceneComponent : public GameComponent  
{
public:
	static CutsceneComponent* GetInstance();
	virtual ~CutsceneComponent();
	virtual Update(float delta);
	virtual Draw();
	virtual OnMessage(int, void* lpinfo = NULL);
	virtual Initialize(int);
	virtual Enter();
	virtual Leave();
private:
	CutsceneComponent();
	float tipPositionY;
	float tipPositionX;
	int barrier;
	hgeSprite *backgroundSprite, *tipSprite, *blackSprite;
	float timeSinceAddBackgroundAlpha;
	int blackAlpha;
	MenuButton continueButton;
	bool startToDisappear;
	HCHANNEL backgroundMusicChannel;
};

#endif // !defined(AFX_CUTSCENECOMPONENT_H__A1A1DC64_10BF_4903_BC11_A7906AE0572C__INCLUDED_)
