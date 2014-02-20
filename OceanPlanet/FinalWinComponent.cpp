// FinalWinComponent.cpp: implementation of the FinalWinComponent class.
//
//////////////////////////////////////////////////////////////////////

#include "FinalWinComponent.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

FinalWinComponent::FinalWinComponent()
{
	HTEXTURE backgroundTex = ResourceFactory::GetTexture(PASS_ALL_TEXTURE_INDEX);
	backgroundSprite = new hgeSprite(backgroundTex, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

	HTEXTURE buttonTexture = ResourceFactory::GetTexture(TASKFAIL_BUTTONS_TEXTURE_INDEX);
	float buttonWidth = (float)hge->Texture_GetWidth(buttonTexture, true) / 3;
	float buttonHeight = hge->Texture_GetHeight(buttonTexture, true) * 0.5f;
	
	float x = (SCREEN_WIDTH - buttonWidth) * 0.5f;
	float y = 400;

	button.Initialize(x, y + buttonHeight, buttonTexture, 0, buttonHeight, buttonWidth, buttonHeight, RETURN_MAINMENU_MSG, this);
}

FinalWinComponent::~FinalWinComponent()
{
	delete backgroundSprite;
}

FinalWinComponent::Update(float delta)
{
	button.Update(delta);
}

FinalWinComponent::Draw()
{
	backgroundSprite->Render(0, 0);
	button.Render();
}

FinalWinComponent::OnMessage(int msgId, void* lpinfo)
{
	switch(msgId) {
	case RETURN_MAINMENU_MSG:
		Game::GetInstance()->SetComponent(WelcomeComponent::GetInstance());
		break;
	default:
		break;
	}
}

FinalWinComponent::Enter()
{

}

FinalWinComponent::Leave()
{

}

FinalWinComponent* FinalWinComponent::GetInstance()
{
	static FinalWinComponent cp;
	return &cp;
}