// TaskPassPanel.cpp: implementation of the TaskPassPanel class.
//
//////////////////////////////////////////////////////////////////////

#include "TaskPassPanel.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

TaskPassPanel::TaskPassPanel(GameComponent* component):TaskResultPanel(component), timeSinceShowPanel(0.0f)
{
	HTEXTURE fntTexture = ResourceFactory::GetTexture(TASKPASS_TEXTURE_INDEX);
	fntSprite = new hgeSprite(fntTexture, 0, 0, hge->Texture_GetWidth(fntTexture), hge->Texture_GetHeight(fntTexture));
}

TaskPassPanel::~TaskPassPanel()
{
	delete fntSprite;
}

TaskPassPanel::Update(float delta)
{
	timeSinceShowPanel += delta;
	if(timeSinceShowPanel > 3.0f) {
		component->OnMessage(NEXT_BARRIER_MSG);
	}
}

TaskPassPanel::Draw()
{
	float x = (SCREEN_WIDTH - hge->Texture_GetWidth(fntSprite->GetTexture(), true)) * 0.5F;
	fntSprite->Render(x, 200);
}