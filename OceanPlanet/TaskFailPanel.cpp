// TaskFailPanel.cpp: implementation of the TaskFailPanel class.
//
//////////////////////////////////////////////////////////////////////

#include "TaskFailPanel.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

TaskFailPanel::TaskFailPanel(GameComponent* component):TaskResultPanel(component)
{
	HTEXTURE tex = ResourceFactory::GetTexture(TASKFAIL_TEXTURE_INDEX);
	fntSprite = new hgeSprite(tex, 0, 0, hge->Texture_GetWidth(tex), hge->Texture_GetHeight(tex));

	HTEXTURE buttonTexture = ResourceFactory::GetTexture(TASKFAIL_BUTTONS_TEXTURE_INDEX);
	float buttonWidth = (float)hge->Texture_GetWidth(buttonTexture, true) / 3;
	float buttonHeight = hge->Texture_GetHeight(buttonTexture, true) * 0.5f;
	
	float x = (SCREEN_WIDTH - buttonWidth) * 0.5f;
	float y = 400;
	buttons[0].Initialize(x, y, buttonTexture, 0, 0, buttonWidth, buttonHeight, RESTART_BARRIER_MSG, component);
	buttons[1].Initialize(x, y + buttonHeight, buttonTexture, 0, buttonHeight, buttonWidth, buttonHeight, RETURN_MAINMENU_MSG, component);
}

TaskFailPanel::~TaskFailPanel()
{
	delete fntSprite;
}

TaskFailPanel::Update(float delta)
{
	int i;
	for(i = 0; i < 2; i++)
	{
		buttons[i].Update(delta);
	}
}

TaskFailPanel::Draw()
{
	float x = (SCREEN_WIDTH - hge->Texture_GetWidth(fntSprite->GetTexture(), true)) * 0.5F;
	fntSprite->Render(x, 200);
	int i;
	for(i = 0; i < 2; i++)
	{
		buttons[i].Render();
	}
}