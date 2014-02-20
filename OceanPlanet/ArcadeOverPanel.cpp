// ArcadeOverPanel.cpp: implementation of the ArcadeOverPanel class.
//
//////////////////////////////////////////////////////////////////////

#include "ArcadeOverPanel.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ArcadeOverPanel::ArcadeOverPanel(GameComponent* component, int score)
:TaskResultPanel(component),score(score)
{
	HTEXTURE tex = ResourceFactory::GetTexture(ARCADE_TIMEOUT_TEXTURE_INDEX);
	fntSprite = new hgeSprite(tex, 0, 0, hge->Texture_GetWidth(tex), hge->Texture_GetHeight(tex));
	
	HTEXTURE buttonTexture = ResourceFactory::GetTexture(ARCADEOVER_BUTTONS_TEXTURE_INDEX);
	float buttonWidth = (float)hge->Texture_GetWidth(buttonTexture, true) / 3;
	float buttonHeight = hge->Texture_GetHeight(buttonTexture, true) * 0.5f;
	
	float x = (SCREEN_WIDTH - buttonWidth) * 0.5f;
	float y = 400;
	buttons[0].Initialize(x, y, buttonTexture, 0, 0, buttonWidth, buttonHeight, RESTART_ARCADE_MSG, component);
	buttons[1].Initialize(x, y + buttonHeight, buttonTexture, 0, buttonHeight, buttonWidth, buttonHeight, RETURN_MAINMENU_MSG, component);

	HTEXTURE scoreTipTex = ResourceFactory::GetTexture(FINAL_SCORE_TEXTURE_INDEX);
	scoreTipWidth = hge->Texture_GetWidth(scoreTipTex, true);

	scoreTipSprite = new hgeSprite(scoreTipTex, 0, 0, scoreTipWidth, hge->Texture_GetHeight(scoreTipTex, true));
	scoreFnt = new hgeFont("font/final_score.fnt");
	scoreFnt->SetColor(ARGB(255, 255,241,0));

	char scoreString[10];
	memset(scoreString, 0, sizeof(scoreString));
	sprintf(scoreString, "%d", score);
	scoreWidth = scoreFnt->GetStringWidth(scoreString);
}

ArcadeOverPanel::~ArcadeOverPanel()
{
	delete fntSprite;
	delete scoreFnt;
	delete scoreTipSprite;
}

ArcadeOverPanel::Update(float delta)
{
//	buttons[0].Update(delta);
	buttons[1].Update(delta);
}

ArcadeOverPanel::Draw()
{
	float x = (SCREEN_WIDTH - hge->Texture_GetWidth(fntSprite->GetTexture(), true)) * 0.5F;
	fntSprite->Render(x, 200);
//	buttons[0].Render();
	buttons[1].Render();
	x = (SCREEN_WIDTH - scoreTipWidth - scoreWidth) * 0.5;
	scoreTipSprite->Render(x, 360);
	x += scoreTipWidth;
	scoreFnt->printf(x, 370, HGETEXT_LEFT, "%d", score);
}