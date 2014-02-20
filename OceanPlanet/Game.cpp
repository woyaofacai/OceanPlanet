// Game.cpp: implementation of the Game class.
//
//////////////////////////////////////////////////////////////////////

#include "Game.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Game::Game():component(0),exit(false)
{

}

Game::Game(Game&)
{

}

Game::~Game()
{
	//delete component;
}

bool Game::Update(float delta)
{
	if(exit) return true;
	component->Update(delta);
	if (hge->Input_GetKeyState(HGEK_ESCAPE)) {
		Game::GetInstance()->SetComponent(WelcomeComponent::GetInstance());
	}
	return false;
}

Game::Draw()
{
	component->Draw();
}

Game::SetComponent(GameComponent* component)
{
	if(this->component != 0) this->component->Leave();
	this->component = component;
	component->Enter();
}

Game* Game::GetInstance()
{
	static Game game;
	return &game;
}

GameComponent* Game::GetComponent()
{
	return this->component;
}

Game::Exit()
{
	exit = true;
}
