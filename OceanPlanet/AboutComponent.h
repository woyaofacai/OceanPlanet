// AboutComponent.h: interface for the AboutComponent class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ABOUTCOMPONENT_H__D81C0932_0CF9_4051_8EA2_23BC73F2C17D__INCLUDED_)
#define AFX_ABOUTCOMPONENT_H__D81C0932_0CF9_4051_8EA2_23BC73F2C17D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "GameComponent.h"
#include "ResourceFactory.h"
#include "Game.h"
#include "WelcomeComponent.h"
#include <hgesprite.h>

class AboutComponent : public GameComponent  
{
public:
	static AboutComponent* GetInstance(); 
	virtual ~AboutComponent();
	virtual Update(float delta);
	virtual Draw();
	virtual OnMessage(int, void* lpinfo = 0);
	virtual Enter();
	virtual Leave();
private:
	AboutComponent();
	hgeSprite* backgroundSprite;
	HCHANNEL backgroundMusicChannel;
};

#endif // !defined(AFX_ABOUTCOMPONENT_H__D81C0932_0CF9_4051_8EA2_23BC73F2C17D__INCLUDED_)
