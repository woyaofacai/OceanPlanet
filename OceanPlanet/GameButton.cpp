// GameButton.cpp: implementation of the GameButton class.
//
//////////////////////////////////////////////////////////////////////

#include "GameButton.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

GameButton::GameButton():mouseOver(false)
{

}

GameButton::~GameButton()
{

}

GameButton::MouseLButton(bool bDown)
{

}

GameButton::MouseOver()
{
	
}

GameButton::MouseOut()
{
	
}

GameButton::Update(float delta)
{
	float x, y;
	hge->Input_GetMousePos(&x, &y);
	if(rect.TestPoint(x, y)) {
		if(hge->Input_KeyDown(HGEK_LBUTTON)) {
			MouseLButton(true);
		}
		else if(hge->Input_KeyUp(HGEK_LBUTTON)) {
			MouseLButton(false);
		}
		if(!mouseOver) {
			mouseOver = true;
			MouseOver();
		}
	}
	else if(mouseOver) {
		mouseOver = false;
		MouseOut();
	}
//	static bool mousePressed = false;
}

GameButton::Render()
{
	
}