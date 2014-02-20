// MainMenuItem.h: interface for the MainMenuItem class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINMENUITEM_H__39CB0630_3C07_45D3_AA15_E81600450450__INCLUDED_)
#define AFX_MAINMENUITEM_H__39CB0630_3C07_45D3_AA15_E81600450450__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <hgegui.h>
#include <hgefont.h>
#include <hgecolor.h>

class MainMenuItem : public hgeGUIObject  
{
public:
	MainMenuItem();
	MainMenuItem(int id, hgeFont *fnt, HEFFECT snd, float x, float y, float delay, char *title);
	virtual void	Render();
	virtual void	Update(float dt);
	
	virtual void	Enter();
	virtual void	Leave();
	virtual bool	IsDone();
	virtual void	Focus(bool bFocused);
	virtual void	MouseOver(bool bOver);
	
	virtual bool	MouseLButton(bool bDown);
	virtual bool	KeyClick(int key, int chr);
	virtual ~MainMenuItem();
private:
	hgeFont		*fnt;
	HEFFECT		snd;
	float		delay;
	char		*title;
	
	hgeColor	scolor, dcolor, scolor2, dcolor2, sshadow, dshadow;
	hgeColor	color, shadow;
	float		soffset, doffset, offset;
	float		timer, timer2;
};

#endif // !defined(AFX_MAINMENUITEM_H__39CB0630_3C07_45D3_AA15_E81600450450__INCLUDED_)
