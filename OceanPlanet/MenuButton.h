// MenuButton.h: interface for the MenuButton class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MENUBUTTON_H__2FFA7084_E6D1_4E27_A367_ECAB23E2525E__INCLUDED_)
#define AFX_MENUBUTTON_H__2FFA7084_E6D1_4E27_A367_ECAB23E2525E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "GameButton.h"

#include <hgesprite.h>
#include "ResourceFactory.h"
#include "GameComponent.h"

class MenuButton : public GameButton  
{
public:
	SetVisible(bool);
	bool GetVisible();
	Initialize(float positionX, float positionY, HTEXTURE, float x, float y, float w, float h, int msgId, GameComponent*, int mouseOverMsg = 0, int mouseOutMsg = 0);
//	Initialize(int, float, float,GameComponent*);
	MenuButton();
	virtual ~MenuButton();
	virtual MouseOver();
	virtual MouseOut();
	virtual MouseLButton(bool bDown);
	virtual Render();

private:
	HTEXTURE texture;
	hgeSprite* sprite;
	int id;
	int msgId;
	int mouseOverMsg;
	int mouseOutMsg;
	float positionX, positionY;
	GameComponent* component;
	float x, y, width, height;
	bool visible;
};

#endif // !defined(AFX_MENUBUTTON_H__2FFA7084_E6D1_4E27_A367_ECAB23E2525E__INCLUDED_)
