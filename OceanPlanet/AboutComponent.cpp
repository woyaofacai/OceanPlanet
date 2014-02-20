// AboutComponent.cpp: implementation of the AboutComponent class.
//
//////////////////////////////////////////////////////////////////////

#include "AboutComponent.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

AboutComponent::AboutComponent()
{
	HTEXTURE backgroundTexture = ResourceFactory::GetTexture(ABOUT_TEXTURE_INDEX);
	backgroundSprite = new hgeSprite(backgroundTexture,	0, 0, hge->Texture_GetWidth(backgroundTexture, true), hge->Texture_GetHeight(backgroundTexture, true));
}

AboutComponent::~AboutComponent()
{

}

AboutComponent* AboutComponent::GetInstance()
{
	static AboutComponent cp;
	return &cp;
}

AboutComponent::Update(float delta)
{
	if(hge->Input_KeyDown(HGEK_LBUTTON)) {
		OnMessage(RETURN_MAINMENU_MSG);
	}
}

AboutComponent::Draw()
{
	backgroundSprite->Render(0, 0);
}

AboutComponent::OnMessage(int msgid, void* lpinfo /* = 0 */)
{
	switch(msgid) {
	case RETURN_MAINMENU_MSG:
		Game::GetInstance()->SetComponent(WelcomeComponent::GetInstance());
		break;
	default:
		break;
	}
}

AboutComponent::Enter()
{
	backgroundMusicChannel = hge->Effect_Play(ResourceFactory::GetSound(CUTSCENE_SOUND));
}

AboutComponent::Leave()
{
	hge->Channel_Stop(backgroundMusicChannel);
}