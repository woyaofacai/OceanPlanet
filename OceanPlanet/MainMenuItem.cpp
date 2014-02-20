// MainMenuItem.cpp: implementation of the MainMenuItem class.
//
//////////////////////////////////////////////////////////////////////

#include "MainMenuItem.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MainMenuItem::MainMenuItem()
{
	
}

MainMenuItem::~MainMenuItem()
{
	
}

MainMenuItem::MainMenuItem(int _id, hgeFont *_fnt, HEFFECT _snd, float _x, float _y, float _delay, char *_title)
{
	float w;
	
	id=_id;
	fnt=_fnt;
	snd=_snd;
	delay=_delay;
	title=_title;
	
	color.SetHWColor(0xFFFFE060);
	shadow.SetHWColor(0x30000000);
	offset=0.0f;
	timer=-1.0f;
	timer2=-1.0f;
	
	bStatic=false;
	bVisible=true;
	bEnabled=true;
	
	w=fnt->GetStringWidth(title);
	rect.Set(_x-w/2, _y, _x+w/2, _y+fnt->GetHeight());
}

void MainMenuItem::Render()
{	
	fnt->SetColor(shadow.GetHWColor());
	fnt->Render(rect.x1+offset+3, rect.y1+3, HGETEXT_LEFT, title);
	fnt->SetColor(color.GetHWColor());
	fnt->Render(rect.x1-offset, rect.y1-offset, HGETEXT_LEFT, title);
}

void MainMenuItem::Update(float dt)
{
	if(timer2 != -1.0f)
	{
		timer2+=dt;
		if(timer2 >= delay+0.1f)
		{
			color=scolor2+dcolor2;
			shadow=sshadow+dshadow;
			offset=0.0f;
			timer2=-1.0f;
		}
		else
		{
			if(timer2 < delay) { color=scolor2; shadow=sshadow; }
			else { color=scolor2+dcolor2*(timer2-delay)*10; shadow=sshadow+dshadow*(timer2-delay)*10; }
		}
	}
	else if(timer != -1.0f)
	{
		timer+=dt;
		if(timer >= 0.2f)
		{
			color=scolor+dcolor;
			offset=soffset+doffset;
			timer=-1.0f;
		}
		else
		{
			color=scolor+dcolor*timer*5;
			offset=soffset+doffset*timer*5;
		}
	}
}

void MainMenuItem::Enter()
{
	hgeColor tcolor2;
	
	scolor2.SetHWColor(0x00FFE060);
	tcolor2.SetHWColor(0xFFFFE060);
	dcolor2=tcolor2-scolor2;
	
	sshadow.SetHWColor(0x00000000);
	tcolor2.SetHWColor(0x30000000);
	dshadow=tcolor2-sshadow;
	
	timer2=0.0f;
}

void MainMenuItem::Leave()
{
	hgeColor tcolor2;
	
	scolor2.SetHWColor(0xFFFFE060);
	tcolor2.SetHWColor(0x00FFE060);
	dcolor2=tcolor2-scolor2;
	
	sshadow.SetHWColor(0x30000000);
	tcolor2.SetHWColor(0x00000000);
	dshadow=tcolor2-sshadow;
	
	timer2=0.0f;
}

bool MainMenuItem::IsDone()
{
	if(timer2==-1.0f) return true;
	else return false;
}

void MainMenuItem::Focus(bool bFocused)
{
	hgeColor tcolor;
	
	if(bFocused)
	{
		hge->Effect_Play(snd);
		scolor.SetHWColor(0xFFFFE060);
		tcolor.SetHWColor(0xFFFFFFFF);
		soffset=0;
		doffset=4;
	}
	else
	{
		scolor.SetHWColor(0xFFFFFFFF);
		tcolor.SetHWColor(0xFFFFE060);
		soffset=4;
		doffset=-4;
	}
	
	dcolor=tcolor-scolor;
	timer=0.0f;
}

void MainMenuItem::MouseOver(bool bOver)
{
	if(bOver) gui->SetFocus(id);
}

bool MainMenuItem::MouseLButton(bool bDown)
{
	if(!bDown)
	{
		offset=4;
		return true;
	}
	else 
	{
		hge->Effect_Play(snd);
		offset=0;
		return false;
	}
}

bool MainMenuItem::KeyClick(int key, int chr)
{
	if(key==HGEK_ENTER || key==HGEK_SPACE)
	{
		MouseLButton(true);
		return MouseLButton(false);
	}
	
	return false;
}