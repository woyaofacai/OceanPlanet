// OpeningComponent.cpp: implementation of the OpeningComponent class.
//
//////////////////////////////////////////////////////////////////////

#include "OpeningComponent.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

OpeningComponent::OpeningComponent()
:timeSinceShowComponent(0.0f),timeSinceLastChangeAlpha(0.0f),startToDisappear(false),blackAlpha(255)
{
	HTEXTURE blackTexture = ResourceFactory::GetTexture(BLACK_TEXTURE_INDEX);
	blackSprite = new hgeSprite(blackTexture, 0, 0, hge->Texture_GetWidth(blackTexture, true), hge->Texture_GetHeight(blackTexture, true));

	HTEXTURE titleTexture = ResourceFactory::GetTexture(OPENING_TITLE_TEXTURE_INDEX);
	int titleWidth = hge->Texture_GetWidth(titleTexture, true);
	int titleHeight = hge->Texture_GetHeight(titleTexture, true);
	titleSprite = new hgeSprite(titleTexture, 0, 0, titleWidth, titleHeight);

	titlePositionX = (SCREEN_WIDTH - titleWidth) * 0.5f;
	titlePositionY = (SCREEN_HEIGHT - titleHeight) * 0.5f;
}

OpeningComponent::~OpeningComponent()
{

}

OpeningComponent::Draw()
{
	titleSprite->Render(titlePositionX, titlePositionY);
	blackSprite->Render(0, 0);
}

OpeningComponent::Update(float delta)
{
	timeSinceShowComponent+=delta;
	timeSinceLastChangeAlpha += delta;
	if(timeSinceLastChangeAlpha > 0.02) {
		timeSinceLastChangeAlpha = 0;
		if(!startToDisappear) {
			blackAlpha -= 10;
			if(blackAlpha < 0) {
				blackAlpha = 0;
				startToDisappear = true;
			}
			ChangeTextureAlpha(blackSprite->GetTexture(), blackAlpha);
		}
		else if(timeSinceShowComponent > 2.0f) {
			blackAlpha += 10;
			if(blackAlpha > 255) blackAlpha = 255;
			ChangeTextureAlpha(blackSprite->GetTexture(), blackAlpha);
			if(blackAlpha == 255) this->OnMessage(RETURN_MAINMENU_MSG);
		}
	}
}

OpeningComponent::OnMessage(int msg, void* lpinfo /* = NULL */)
{
	switch(msg) {
	case RETURN_MAINMENU_MSG:
		Game::GetInstance()->SetComponent(WelcomeComponent::GetInstance());
		break;
	}
}

OpeningComponent* OpeningComponent::GetInstance()
{
	static OpeningComponent cp;
	return &cp;
}