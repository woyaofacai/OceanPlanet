// ResourceFactory.cpp: implementation of the ResourceFactory class.
//
//////////////////////////////////////////////////////////////////////

#include "ResourceFactory.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ResourceFactory::ResourceFactory()
{
	
}

ResourceFactory::~ResourceFactory()
{

}


HTEXTURE ResourceFactory::textures[150] = {0};
HEFFECT ResourceFactory::sounds[30] = {0};

ResourceFactory::LoadResources()
{	
	textures[NEEDLE_TEXTURE_INDEX] = hge->Texture_Load("images/needle.png");
	textures[PARTICLE_TEXTURE_INDEX] = hge->Texture_Load("images/particles.png");
	textures[DOLLAR_TEXTURE_INDEX] = hge->Texture_Load("images/dollar.png");
	textures[CONTROLPANEL_TEXTURE_INDEX] = hge->Texture_Load("images/background/controlpanel.png");
	textures[NEEDLE2_TEXTURE_INDEX] = hge->Texture_Load("images/needle2.png");
	textures[BOMB_TEXTURE_INDEX] = hge->Texture_Load("images/bomb.png");
	textures[UNPLACED_BOMB_TEXTURE_INDEX] = hge->Texture_Load("images/bomb.png");
	textures[POW_TEXTURE_INDEX] = hge->Texture_Load("images/pow.png");
	
	textures[LEFTFISH_TEXTURE_INDEX] = hge->Texture_Load("images/fish/fish0.png");
	textures[LEFTFISH_TEXTURE_INDEX + 1] = hge->Texture_Load("images/fish/fish1.png");
	textures[LEFTFISH_TEXTURE_INDEX + 2] = hge->Texture_Load("images/fish/fish2.png");
	textures[LEFTFISH_TEXTURE_INDEX + 3] = hge->Texture_Load("images/fish/fish3.png");
	textures[LEFTFISH_TEXTURE_INDEX + 4] = hge->Texture_Load("images/fish/fish4.png");
	textures[LEFTFISH_TEXTURE_INDEX + 5] = hge->Texture_Load("images/fish/fish5.png");

	textures[RIGHTFISH_TEXTURE_INDEX] = hge->Texture_Load("images/fish/fish0_r.png");
	textures[RIGHTFISH_TEXTURE_INDEX + 1] = hge->Texture_Load("images/fish/fish1_r.png");
	textures[RIGHTFISH_TEXTURE_INDEX + 2] = hge->Texture_Load("images/fish/fish2_r.png");
	textures[RIGHTFISH_TEXTURE_INDEX + 3] = hge->Texture_Load("images/fish/fish3_r.png");
	textures[RIGHTFISH_TEXTURE_INDEX + 4] = hge->Texture_Load("images/fish/fish4_r.png");
	textures[RIGHTFISH_TEXTURE_INDEX + 5] = hge->Texture_Load("images/fish/fish5_r.png");

	textures[CHANGE_WEAPON_BUTTON_TEXTURE_INDEX] = hge->Texture_Load("images/change_weapon.png");
	textures[SMALL_NEEDLE_TEXTURE_INDEX] = hge->Texture_Load("images/small_needle.png");
	textures[SMALL_BOMB_TEXTURE_INDEX] = hge->Texture_Load("images/small_bomb.png");

	textures[BUBBLE_TEXTURE_INDEX] = hge->Texture_Load("images/bubble2.png");
	textures[SKELETON_TEXTURE_INDEX] = hge->Texture_Load("images/small_bomb.png");
	textures[HARVEST_TEXTURE_INDEX] = hge->Texture_Load("images/harvest2.png");
	textures[TREATURE_TEXTURE_INDEX] = hge->Texture_Load("images/treasure2.png");
	textures[DECELERATE_TEXTURE_INDEX] = hge->Texture_Load("images/decelerate2.png");
	textures[ACCELERATE_TEXTURE_INDEX] = hge->Texture_Load("images/accelerate2.png");
	
	textures[LIFE_TEXTURE_INDEX] = hge->Texture_Load("images/life.png");

	textures[WELCOME_TEXTURE_INDEX] = hge->Texture_Load("images/background/welcome.png");
	textures[MENUBUTTON_TEXTURE_INDEX] = hge->Texture_Load("images/menu_button.png");

	textures[TASKFAIL_TEXTURE_INDEX] = hge->Texture_Load("images/task_fail.png");
	textures[LEFTTIME_TEXTRUE_INDEX] = hge->Texture_Load("images/left_time.png");
	textures[TASKGOAL_TEXTURE_INDEX] = hge->Texture_Load("images/task_goal.png");
	textures[CONTINUEBUTTON_TEXTURE_INDEX] = hge->Texture_Load("images/continue_button.png");
	textures[TASKFAIL_BUTTONS_TEXTURE_INDEX] = hge->Texture_Load("images/taskfail_buttons.png");
	textures[TASKPASS_TEXTURE_INDEX] = hge->Texture_Load("images/task_pass.png");

	textures[CUTSCENES_BASE_TEXTURE_INDEX] = hge->Texture_Load("images/background/barrier1.png");
	textures[CUTSCENES_BASE_TEXTURE_INDEX + 1] = hge->Texture_Load("images/background/barrier2.png");
	textures[CUTSCENES_BASE_TEXTURE_INDEX + 2] = hge->Texture_Load("images/background/barrier3.png");
	textures[CUTSCENES_BASE_TEXTURE_INDEX + 3] = hge->Texture_Load("images/background/barrier4.png");
	textures[CUTSCENES_BASE_TEXTURE_INDEX + 4] = hge->Texture_Load("images/background/barrier5.png");
	textures[CUTSCENES_BASE_TEXTURE_INDEX + 5] = hge->Texture_Load("images/background/barrier6.png");

	textures[CUTSCENESTIP_BASE_TEXTURE_INDEX + 1] = hge->Texture_Load("images/background/barriertip2.png");
	textures[CUTSCENESTIP_BASE_TEXTURE_INDEX + 2] = hge->Texture_Load("images/background/barriertip3.png");
	textures[CUTSCENESTIP_BASE_TEXTURE_INDEX + 3] = hge->Texture_Load("images/background/barriertip4.png");
	textures[CUTSCENESTIP_BASE_TEXTURE_INDEX + 4] = hge->Texture_Load("images/background/barriertip5.png");
	textures[CUTSCENESTIP_BASE_TEXTURE_INDEX + 5] = hge->Texture_Load("images/background/barriertip6.png");

	textures[BLACK_TEXTURE_INDEX] = hge->Texture_Load("images/background/black.png");
	textures[PASS_ALL_TEXTURE_INDEX] = hge->Texture_Load("images/background/pass_all_tasks.png");
	textures[ARCADE_TIMEOUT_TEXTURE_INDEX] = hge->Texture_Load("images/game_over.png");
	textures[ARCADEOVER_BUTTONS_TEXTURE_INDEX] = hge->Texture_Load("images/arcadeover_buttons.png");
	textures[FINAL_SCORE_TEXTURE_INDEX] = hge->Texture_Load("images/final_score.png");
	textures[OPENING_TITLE_TEXTURE_INDEX] = hge->Texture_Load("images/opening_title.png");
	textures[ABOUT_TEXTURE_INDEX] = hge->Texture_Load("images/background/about.png");


	sounds[MENU_BUTTON_SOUND] = hge->Effect_Load("sound/menu.wav");
	sounds[RUNNING_GAME_SOUND] = hge->Effect_Load("sound/run.mp3");
	sounds[CUTSCENE_SOUND] = hge->Effect_Load("sound/cutscene.mp3");
	sounds[PUT_BOMB_SOUND] = hge->Effect_Load("sound/put_bomb.wav");
	sounds[PUT_NEEDLE_SOUND] = hge->Effect_Load("sound/put_needle.wav");
	sounds[BOMB_EXPLODE_SOUND] = hge->Effect_Load("sound/bomb_explode.wav");
	sounds[HIT_FISH_SOUND] = hge->Effect_Load("sound/hit_fish.wav");
	loadBlackFishTextures();
}

HTEXTURE ResourceFactory::GetTexture(int index)
{
	return textures[index];
}

HEFFECT ResourceFactory::GetSound(int index)
{
	return sounds[index];
}

ResourceFactory::loadBlackFishTextures()
{
	int i;
	int j;
	for (i = 0 ;i < FISH_KIND_NUM; i++)
	{
		HTEXTURE htex = textures[LEFTFISH_TEXTURE_INDEX + i];
		int width = hge->Texture_GetWidth(htex, false);
		int height = hge->Texture_GetHeight(htex, false);

		HTEXTURE blackTex = hge->Texture_Create(width, height);
		DWORD* blackTexBuffer = hge->Texture_Lock(blackTex);
		DWORD* hTexBuffer = hge->Texture_Lock(htex, true);

		for (j = 0; j < width * height; j++)
		{
			blackTexBuffer[j] = hTexBuffer[j] & 0xFF000000;
		}
		
		hge->Texture_Unlock(blackTex);
		hge->Texture_Unlock(htex);
		textures[BLACK_LEFTFISH_TEXTURE_INDEX + i] = blackTex; 
	}

	for (i = 0 ;i < FISH_KIND_NUM; i++)
	{
		HTEXTURE htex = textures[RIGHTFISH_TEXTURE_INDEX + i];
		int width = hge->Texture_GetWidth(htex, false);
		int height = hge->Texture_GetHeight(htex, false);
		
		HTEXTURE blackTex = hge->Texture_Create(width, height);
		DWORD* blackTexBuffer = hge->Texture_Lock(blackTex);
		DWORD* hTexBuffer = hge->Texture_Lock(htex, true);
		
		for (j = 0; j < width * height; j++)
		{
			blackTexBuffer[j] = hTexBuffer[j] & 0xFF000000;
		}
		
		hge->Texture_Unlock(blackTex);
		hge->Texture_Unlock(htex);
		textures[BLACK_RIGHTFISH_TEXTURE_INDEX + i] = blackTex; 
	}
}

HTEXTURE ResourceFactory::GetWeaponTexture(int weaponType, bool smallTexture=false)
{
	HTEXTURE htex;
	if(smallTexture) {
		switch(weaponType) {
		case BOMB_WEAPON_TYPE:
			htex = textures[SMALL_BOMB_TEXTURE_INDEX];
			break;
		case NEEDLE_WEAPON_TYPE:
			htex = textures[SMALL_NEEDLE_TEXTURE_INDEX];
			break;
		default:
			break;
		}
	}
	else {
		switch(weaponType)
		{
		case BOMB_WEAPON_TYPE:
			htex = textures[BOMB_TEXTURE_INDEX];
			break;
		case NEEDLE_WEAPON_TYPE:
			htex = textures[NEEDLE_TEXTURE_INDEX];
			break;
		default:
			break;
		}
	}
	return htex;
}
