// GameButton.h: interface for the GameButton class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GAMEBUTTON_H__D47FC5FF_6E31_40D2_B519_A72969880CBF__INCLUDED_)
#define AFX_GAMEBUTTON_H__D47FC5FF_6E31_40D2_B519_A72969880CBF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <hge.h>
#include <hgerect.h>

extern HGE* hge;

class GameButton  
{
public:
	bool mouseOver;
	GameButton();
	virtual ~GameButton();
	virtual MouseOver();
	virtual MouseOut();
	virtual MouseLButton(bool bDown);
	virtual Update(float delta);
	virtual Render();
protected:
	hgeRect rect;
};

#endif // !defined(AFX_GAMEBUTTON_H__D47FC5FF_6E31_40D2_B519_A72969880CBF__INCLUDED_)
