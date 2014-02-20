// WelcomeComponent.cpp: implementation of the WelcomeComponent class.
//
//////////////////////////////////////////////////////////////////////

#include "WelcomeComponent.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

WelcomeComponent::WelcomeComponent()
{
	HTEXTURE backgroundTex = ResourceFactory::GetTexture(WELCOME_TEXTURE_INDEX);
	backgroundSprite = new hgeSprite(backgroundTex, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

	int buttonMsgId[] = {START_MENUBUTTON_MSG, ARCADE_MENUBUTTON_MSG, ABOUT_MENUBUTTON_MSG, EXIT_GAME_MSG};
	int i;

	
	HTEXTURE buttonTexture = ResourceFactory::GetTexture(MENUBUTTON_TEXTURE_INDEX);
	int width = hge->Texture_GetWidth(buttonTexture, true);
	int height = hge->Texture_GetHeight(buttonTexture, true);
	float buttonHeight = height * 0.25f;
	float buttonWidth = (float)width / 3; 
	float positionX = (SCREEN_WIDTH - buttonWidth) * 0.5f;
	float positionY = 300.0f;
	for (i = 0; i < 4; i++)
	{
		menuButtons[i].Initialize(positionX, positionY + i * buttonHeight, buttonTexture, 0,  buttonHeight * i, buttonWidth, buttonHeight, buttonMsgId[i], this);
	}

}

WelcomeComponent::~WelcomeComponent()
{
	delete backgroundSprite;
}

WelcomeComponent::Update(float delta)
{
	int i = 0;
	for (i = 0; i < 4; i++)
	{
		menuButtons[i].Update(delta);
	}
}

WelcomeComponent::Draw()
{
	backgroundSprite->Render(0, 0);
	int i = 0;
	for (i = 0; i < 4; i++)
	{
		menuButtons[i].Render();
	}
	//hge->Gfx_RenderQuad(&maskQuad);
}


WelcomeComponent::OnMessage(int msgId, void* lpinfo)
{
	switch(msgId)
	{
	case ARCADE_MENUBUTTON_MSG:
		RunningComponent::GetInstance()->SetGameModel(new RunningStateData(runningModels[0]));
		Game::GetInstance()->SetComponent(RunningComponent::GetInstance());
		break;
	case START_MENUBUTTON_MSG:
		CutsceneComponent::GetInstance()->Initialize(1);
		Game::GetInstance()->SetComponent(CutsceneComponent::GetInstance());
		break;
	case ABOUT_MENUBUTTON_MSG:
		Game::GetInstance()->SetComponent(AboutComponent::GetInstance());
		break;
	case EXIT_GAME_MSG:
		Game::GetInstance()->Exit();
		break;
	}
}

WelcomeComponent* WelcomeComponent::GetInstance()
{
	static WelcomeComponent cp;
	return &cp;
}