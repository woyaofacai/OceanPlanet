// WelcomeComponent.h: interface for the WelcomeComponent class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_WELCOMECOMPONENT_H__5A138B95_C8EF_4433_9693_6919CAC60F86__INCLUDED_)
#define AFX_WELCOMECOMPONENT_H__5A138B95_C8EF_4433_9693_6919CAC60F86__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <hge.h>
#include <hgesprite.h>

#include "GameComponent.h"
#include "MenuButton.h"
#include "ResourceFactory.h"
#include "Game.h"
#include "RunningComponent.h"
#include "CutsceneComponent.h"
#include "AboutComponent.h"

extern HGE* hge;
extern RunningStateData runningModels[];

class WelcomeComponent : public GameComponent  
{
public:
	static WelcomeComponent* GetInstance();
	virtual ~WelcomeComponent();
	virtual Update(float delta);
	virtual Draw();
	virtual OnMessage(int, void* lpinfo = NULL);
private:
	WelcomeComponent();
	hgeSprite* backgroundSprite;
	MenuButton menuButtons[4];
	hgeQuad maskQuad;
};

#endif // !defined(AFX_WELCOMECOMPONENT_H__5A138B95_C8EF_4433_9693_6919CAC60F86__INCLUDED_)
