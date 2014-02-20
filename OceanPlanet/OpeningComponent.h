// OpeningComponent.h: interface for the OpeningComponent class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OPENINGCOMPONENT_H__66D4BCA9_1C65_4AB2_B2CD_2041845DEA39__INCLUDED_)
#define AFX_OPENINGCOMPONENT_H__66D4BCA9_1C65_4AB2_B2CD_2041845DEA39__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "GameComponent.h"
#include <hgesprite.h>
#include "ResourceFactory.h"
#include "Game.h"
#include "WelcomeComponent.h"

extern HGE* hge;
extern void ChangeTextureAlpha(HTEXTURE tex, int alpha);

class OpeningComponent : public GameComponent  
{
public:
	static OpeningComponent* GetInstance();
	virtual ~OpeningComponent();
	virtual Update(float delta);
	virtual Draw();
	virtual OnMessage(int, void* lpinfo = NULL);
private:
	OpeningComponent();
	hgeSprite* titleSprite, *blackSprite;
	bool startToDisappear;
	float timeSinceShowComponent;
	float timeSinceLastChangeAlpha;
	float titlePositionX, titlePositionY;
	int blackAlpha;
};

#endif // !defined(AFX_OPENINGCOMPONENT_H__66D4BCA9_1C65_4AB2_B2CD_2041845DEA39__INCLUDED_)
