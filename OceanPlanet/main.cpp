#include <hge.h>
#include <hgesprite.h>
#include <hgedistort.h>
#include <hgefont.h>
#include <list>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include "constants.h"
#include "Game.h"
#include "Fish.h"
#include "FishFactory.h"
#include "SeaBackGround.h"
#include "GameComponent.h"
#include "RunningComponent.h"
#include "WelcomeComponent.h"
#include "OpeningComponent.h"
#include "ResourceFactory.h"

#include "ScriptEngine.h"

using namespace std;
void ChangeTextureAlpha(HTEXTURE tex, int alpha);

HGE *hge = 0;
Game* game;
RunningStateData runningModels[TOTAL_BARRIER_COUNT + 1];

void Game_Init()
{
	srand(time(NULL));
	ResourceFactory::LoadResources();
	InitializeGameModels(runningModels, TOTAL_BARRIER_COUNT);
	game = Game::GetInstance();
	game->SetComponent(OpeningComponent::GetInstance());
}

void Game_Exit()
{

}

bool FrameFunc()
{
	//if (hge->Input_GetKeyState(HGEK_ESCAPE)) return true;
	float delta = hge->Timer_GetDelta();
	if(game->Update(delta)) return true;
	return false;
}

bool RenderFunc()
{
	hge->Gfx_BeginScene();
	hge->Gfx_Clear(ARGB(0, 0, 0, 0));

	game->Draw();
	
	hge->Gfx_EndScene();
	return false;
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	hge = hgeCreate(HGE_VERSION);
	
	// Set our frame function
	hge->System_SetState(HGE_FRAMEFUNC, FrameFunc);
	hge->System_SetState(HGE_RENDERFUNC, RenderFunc);
	// Set the window title
	hge->System_SetState(HGE_TITLE, "º£ÑóÎÄÃ÷II");
	
	// Run in windowed mode
	// Default window size is 800x600
	hge->System_SetState(HGE_WINDOWED, false);
	hge->System_SetState(HGE_SCREENWIDTH, SCREEN_WIDTH);
	hge->System_SetState(HGE_SCREENHEIGHT, SCREEN_HEIGHT);
	hge->System_SetState(HGE_HIDEMOUSE, false);
	hge->System_SetState(HGE_LOGFILE, "log.txt");
	hge->System_SetState(HGE_ZBUFFER, true);
	hge->System_SetState(HGE_SHOWSPLASH, false);

//	hge->System_SetState(HGE_FPS, 60);

	// Don't use BASS for sound
	hge->System_SetState(HGE_USESOUND, true);
	
	if(hge->System_Initiate())
	{
		Game_Init();
		hge->System_Start();
		Game_Exit();
	}
	else
	{	
		// If HGE initialization failed show error message
		MessageBox(NULL, hge->System_GetErrorMessage(), "Error", MB_OK | MB_ICONERROR | MB_APPLMODAL);
	}

	hge->System_Shutdown();
	hge->Release();
	
	return 0;
}

void ChangeTextureAlpha(HTEXTURE tex, int alpha)
{
	if(alpha > 255) alpha = 255;
	if(alpha < 0) alpha = 0;
	DWORD* texBuffer = hge->Texture_Lock(tex, false);
	int width = hge->Texture_GetWidth(tex);
	int height = hge->Texture_GetHeight(tex);
	
	int i;
	for (i = 0; i < width * height; i++)
	{
		texBuffer[i] = texBuffer[i] & 0x00FFFFFF | (alpha << 24);
	}
	hge->Texture_Unlock(tex);
}