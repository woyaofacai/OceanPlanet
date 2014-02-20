// FinalWinComponent.h: interface for the FinalWinComponent class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FINALWINCOMPONENT_H__25E44C5E_95B8_4774_BD00_159F10FDF20D__INCLUDED_)
#define AFX_FINALWINCOMPONENT_H__25E44C5E_95B8_4774_BD00_159F10FDF20D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "GameComponent.h"
#include <hgesprite.h>
#include "MenuButton.h"
#include "Game.h"
#include "WelcomeComponent.h"

class FinalWinComponent : public GameComponent
{
public:
	static FinalWinComponent* GetInstance();
	virtual ~FinalWinComponent();
	virtual Update(float delta);
	virtual Draw();
	virtual OnMessage(int, void* lpinfo = NULL);
	virtual Enter();
	virtual Leave();
private:
	FinalWinComponent();
	hgeSprite* backgroundSprite;
	MenuButton button;
};

#endif // !defined(AFX_FINALWINCOMPONENT_H__25E44C5E_95B8_4774_BD00_159F10FDF20D__INCLUDED_)
