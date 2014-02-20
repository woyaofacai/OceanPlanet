// CutsceneComponent.cpp: implementation of the CutsceneComponent class.
//
//////////////////////////////////////////////////////////////////////

#include "CutsceneComponent.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CutsceneComponent::CutsceneComponent()
:timeSinceAddBackgroundAlpha(0.0f), blackAlpha(255),tipSprite(NULL),startToDisappear(false)
{
	
}

CutsceneComponent::Initialize(int barrier)
{
	this->barrier = barrier;
	timeSinceAddBackgroundAlpha = 0;
	blackAlpha = 255;
	tipSprite = NULL;
	startToDisappear = false;
	HTEXTURE continueButtonTexture = ResourceFactory::GetTexture(CONTINUEBUTTON_TEXTURE_INDEX);
	float buttonWidth = (float)hge->Texture_GetWidth(continueButtonTexture, true) / 3;
	float buttonHeight = (float)hge->Texture_GetHeight(continueButtonTexture, true);
	continueButton.Initialize(SCREEN_WIDTH - 200, SCREEN_HEIGHT - 70, continueButtonTexture,0, 0, buttonWidth, buttonHeight, CONTINUE_MENUBUTTON_MSG, this);
	HTEXTURE tex = ResourceFactory::GetTexture(CUTSCENES_BASE_TEXTURE_INDEX + barrier - 1);
	backgroundSprite = new hgeSprite(tex, 0, 0,	SCREEN_WIDTH, SCREEN_HEIGHT);
	
	HTEXTURE tipTexture = ResourceFactory::GetTexture(CUTSCENESTIP_BASE_TEXTURE_INDEX + barrier - 1);
	if(tipTexture != 0) {
		int tipTextureWidth = hge->Texture_GetWidth(tipTexture, true);
		int tipTextureHeight = hge->Texture_GetHeight(tipTexture, true);
		tipPositionX = (SCREEN_WIDTH - tipTextureWidth) * 0.5f;
		tipSprite = new hgeSprite(tipTexture, 0, 0, tipTextureWidth, tipTextureHeight);
		
	}
	
	HTEXTURE blackTexture = ResourceFactory::GetTexture(BLACK_TEXTURE_INDEX);
	blackSprite = new hgeSprite(blackTexture, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	
	
}

CutsceneComponent::Enter()
{
	backgroundMusicChannel = hge->Effect_Play(ResourceFactory::GetSound(CUTSCENE_SOUND));
}

CutsceneComponent::Leave()
{
	hge->Channel_Stop(backgroundMusicChannel);
}

CutsceneComponent::~CutsceneComponent()
{
	/*
	delete backgroundSprite;
	delete tipSprite;
	delete blackSprite;
	*/
}

CutsceneComponent::Update(float delta)
{
	continueButton.Update(delta);
	
	timeSinceAddBackgroundAlpha += delta;
	if(timeSinceAddBackgroundAlpha > 0.05f) {
		timeSinceAddBackgroundAlpha = 0;
		if(!startToDisappear && blackAlpha > 0) {
			blackAlpha -= 10;
			if(blackAlpha < 0) blackAlpha = 0;
			ChangeTextureAlpha(blackSprite->GetTexture(), blackAlpha);
		}
		else if(startToDisappear)
		{
			blackAlpha += 10;
			if(blackAlpha <= 255) {
				ChangeTextureAlpha(blackSprite->GetTexture(), blackAlpha);
			}
			else {
				RunningComponent::GetInstance()->SetGameModel(new RunningStateData(runningModels[barrier]));
				Game::GetInstance()->SetComponent(RunningComponent::GetInstance());
			}
		}
	}
}

CutsceneComponent::Draw()
{
	backgroundSprite->Render(0, 0);
	continueButton.Render();
	
	if(tipSprite != NULL) {
		tipSprite->Render(tipPositionX, 30);
	}
	blackSprite->Render(0, 0);
}


CutsceneComponent::OnMessage(int msgId, void* lpinfo)
{
	switch(msgId)
	{
	case CONTINUE_MENUBUTTON_MSG:
		startToDisappear = true;
		break;
	}
}

CutsceneComponent* CutsceneComponent::GetInstance()
{
	static CutsceneComponent cp;
	return &cp;
}

//DEL float CutsceneComponent::tipPositionY()
//DEL {
//DEL 
//DEL }
