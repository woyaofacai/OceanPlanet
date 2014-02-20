// MenuComponent.h: interface for the MenuComponent class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MENUCOMPONENT_H__41B915C0_494A_4EC3_A413_DCA7E2F62173__INCLUDED_)
#define AFX_MENUCOMPONENT_H__41B915C0_494A_4EC3_A413_DCA7E2F62173__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <hge.h>
#include <hgegui.h>
#include <hgefont.h>
#include <hgesprite.h>

#include "GameComponent.h"
#include "constants.h"

extern HGE *hge;

class MenuComponent : public GameComponent  
{
public:
	virtual ~MenuComponent();
	virtual Update(float delta);
	virtual Draw();
	static GameComponent* GetInstance();
private:
	MenuComponent();
	hgeGUI *gui;
	hgeFont *fnt;
	HEFFECT snd;
	hgeSprite *cursorSprite;
	static GameComponent* lpInstance;
	hgeSprite* backgroundSprite;

};

#endif // !defined(AFX_MENUCOMPONENT_H__41B915C0_494A_4EC3_A413_DCA7E2F62173__INCLUDED_)
