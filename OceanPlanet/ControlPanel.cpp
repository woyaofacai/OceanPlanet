// ControlPanel.cpp: implementation of the ControlPanel class.
//
//////////////////////////////////////////////////////////////////////

#include "ControlPanel.h"
#include "RunningComponent.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ControlPanel::ControlPanel(RunningComponent* component)
:elapsedTime(0.0f),component(component)
{	
	HTEXTURE dollarTexture = ResourceFactory::GetTexture(DOLLAR_TEXTURE_INDEX);
	dollarSprite = new hgeSprite(dollarTexture, 0, 0, hge->Texture_GetWidth(dollarTexture, true), hge->Texture_GetHeight(dollarTexture, true));

	HTEXTURE needleTexture = ResourceFactory::GetTexture(SMALL_NEEDLE_TEXTURE_INDEX);
	needleSprite = new hgeSprite(needleTexture, 0, 0, hge->Texture_GetWidth(needleTexture, true), hge->Texture_GetHeight(needleTexture, true));

	HTEXTURE bombTexture = ResourceFactory::GetTexture(SMALL_BOMB_TEXTURE_INDEX);
	bombSprite = new hgeSprite(bombTexture, 0, 0, hge->Texture_GetWidth(bombTexture, true), hge->Texture_GetHeight(bombTexture, true));

	HTEXTURE lifeHeartTexture = ResourceFactory::GetTexture(LIFE_TEXTURE_INDEX);
	lifeHeartSprite = new hgeSprite(lifeHeartTexture, 0, 0, hge->Texture_GetWidth(lifeHeartTexture, true), hge->Texture_GetHeight(lifeHeartTexture, true));

	totalScoreAnimation = new TotalScoreAnimation(TOTAL_SCORE_POS_X, TOTAL_SCORE_POS_Y);

	weaponCountFont = new hgeFont("font/weapon_count.fnt");
	leftTimeFnt = new hgeFont("font/elapsedTime.fnt");
	leftTimeFnt->SetColor(ARGB(255, 255, 255, 0));
	HTEXTURE leftTimeTexture = ResourceFactory::GetTexture(LEFTTIME_TEXTRUE_INDEX);
	leftTimeSprite = new hgeSprite(leftTimeTexture, 0, 0, hge->Texture_GetWidth(leftTimeTexture, true), hge->Texture_GetHeight(leftTimeTexture, true) * 0.5f);

	HTEXTURE taskGoalTexture = ResourceFactory::GetTexture(TASKGOAL_TEXTURE_INDEX);
	taskGoalSprite = new hgeSprite(taskGoalTexture, 0, 0, hge->Texture_GetWidth(taskGoalTexture, true), hge->Texture_GetHeight(taskGoalTexture, true));

	HTEXTURE changeWeaponTexture = ResourceFactory::GetTexture(CHANGE_WEAPON_BUTTON_TEXTURE_INDEX);
	float textureWidth = (float)hge->Texture_GetWidth(changeWeaponTexture, true) / 3;
	float textureHeight = hge->Texture_GetHeight(changeWeaponTexture, true);
	changeWeaponButton.Initialize(500, TOTAL_SCORE_POS_Y, changeWeaponTexture, 
		0, 0, textureWidth, textureHeight, CHANGE_WEAPON_MSG, component, MOUSEOVER_CHANGEWEAPON_MSG, MOUSEOUT_CHANGEWEAPON_MSG);
	
	if(!( (component->GetModel()->AllowWeaponType & BOMB_WEAPON_TYPE)
		&& (component->GetModel()->AllowWeaponType & NEEDLE_WEAPON_TYPE))) {
		changeWeaponButton.SetVisible(false);
	}
}

ControlPanel::~ControlPanel()
{
	delete dollarSprite;
	delete needleSprite;
	delete bombSprite;
	delete weaponCountFont;
	delete lifeHeartSprite;
	delete leftTimeFnt;
	delete leftTimeSprite;
	delete taskGoalSprite;
}

ControlPanel::Update(float delta)
{
	if(component->GetModel()->CurrentState == FIGHT_STATE || component->GetModel()->CurrentState == OPERATION_STATE) {
		elapsedTime += delta;
		if(elapsedTime > component->GetModel()->TimeLimit)
		{
			if(component->GetModel()->ArcadeMode) {
				component->OnMessage(ARCADE_OVER_MSG);
			}
			else {
				component->OnMessage(TASKFAIL_MSG, NULL);
			}
		}
		/*
		if(elapsedTime - delta <= component->GetModel()->GoalScore - 10.0f 
			&& elapsedTime >= component->GetModel()->GoalScore - 10.0f) {
			leftTimeFnt->SetColor(ARGB(255, 255, 0, 0));
			HTEXTURE leftTimeTexture = leftTimeSprite->GetTexture();
			leftTimeSprite->SetTextureRect(0, hge->Texture_GetHeight(leftTimeTexture, true) * 0.5f, hge->Texture_GetWidth(leftTimeTexture, true), hge->Texture_GetHeight(leftTimeTexture, true) * 0.5f);
		}*/

		changeWeaponButton.Update(delta);
	}

	totalScoreAnimation->Update(delta);
}

ControlPanel::Draw()
{
	totalScoreAnimation->Draw();
	dollarSprite->Render(0, TOTAL_SCORE_POS_Y);


	if(component->GetModel()->AllowWeaponType & NEEDLE_WEAPON_TYPE) {
		needleSprite->Render(200, TOTAL_SCORE_POS_Y);
		weaponCountFont->printf(260, TOTAL_SCORE_POS_Y, HGETEXT_LEFT, "%d", component->GetModel()->NeedleCount);
	}
	if (component->GetModel()->AllowWeaponType & BOMB_WEAPON_TYPE)
	{
		bombSprite->Render(350, TOTAL_SCORE_POS_Y);
		weaponCountFont->printf(410, TOTAL_SCORE_POS_Y, HGETEXT_LEFT, "%d", component->GetModel()->BombCount);
	}
	if((component->GetModel()->AllowWeaponType & BOMB_WEAPON_TYPE) && (component->GetModel()->AllowWeaponType & NEEDLE_WEAPON_TYPE)) 
	{
		if(component->GetModel()->CurrentWeaponType == NEEDLE_WEAPON_TYPE) {
			needleSprite->Render(620, TOTAL_SCORE_POS_Y);
		}
		else {
			bombSprite->Render(620, TOTAL_SCORE_POS_Y);
		}
	}

	changeWeaponButton.Render();

	int i;
	for (i = 0; i < component->GetModel()->Life; i++)
	{
		lifeHeartSprite->Render(i * lifeHeartSprite->GetWidth(), 0);
	}
	if(!component->GetModel()->ArcadeMode) {
		taskGoalSprite->Render(SCREEN_WIDTH - 340, 2);
		leftTimeFnt->printf(SCREEN_WIDTH - 230, 5, HGETEXT_LEFT, "%d", component->GetModel()->GoalScore);
	}
	leftTimeSprite->Render(SCREEN_WIDTH - 160, 2);
	leftTimeFnt->printf(SCREEN_WIDTH - 50, 5, HGETEXT_LEFT, "%d", component->GetModel()->TimeLimit - (int)elapsedTime);



}

ControlPanel::AddScore(int score)
{
	totalScoreAnimation->AddScore(score);
	component->GetModel()->CurrentScore += score;
	
	if(component->MeetWinCondition() && (component->GetModel()->CurrentState == FIGHT_STATE || 
		component->GetModel()->CurrentState == OPERATION_STATE)) {
		component->OnMessage(TASKPASS_MSG);
	}
}

