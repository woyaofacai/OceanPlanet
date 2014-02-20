// MenuComponent.cpp: implementation of the MenuComponent class.
//
//////////////////////////////////////////////////////////////////////

#include "MenuComponent.h"
#include "MainMenuItem.h"


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MenuComponent::MenuComponent()
{
	fnt = new hgeFont("font/font1.fnt");
	snd=hge->Effect_Load("sound/menu.wav");

	HTEXTURE tex = hge->Texture_Load("images/cursor.png");

	cursorSprite = new hgeSprite(tex, 0, 0, 32, 32);
	gui = new hgeGUI;
	gui->AddCtrl(new MainMenuItem(1,fnt,snd,400,200,0.0f,"Play"));
	gui->AddCtrl(new MainMenuItem(2,fnt,snd,400,240,0.1f,"Options"));
	gui->AddCtrl(new MainMenuItem(3,fnt,snd,400,280,0.2f,"Instructions"));
	gui->AddCtrl(new MainMenuItem(4,fnt,snd,400,320,0.3f,"Credits"));
	gui->AddCtrl(new MainMenuItem(5,fnt,snd,400,360,0.4f,"Exit"));

	gui->SetNavMode(HGEGUI_UPDOWN | HGEGUI_CYCLED);
	gui->SetCursor(cursorSprite);
	gui->SetFocus(1);
	gui->Enter();
}

MenuComponent::~MenuComponent()
{
	delete gui;
}

MenuComponent::Update(float delta)
{
	gui->Update(delta);
}

MenuComponent::Draw()
{
	gui->Render();
}

GameComponent* MenuComponent::lpInstance = NULL;

GameComponent* MenuComponent::GetInstance()
{
	if(lpInstance == NULL){
		lpInstance = new MenuComponent;
	}
	return lpInstance;
}