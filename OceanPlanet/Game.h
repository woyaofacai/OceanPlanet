// Game.h: interface for the Game class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GAME_H__6127CD08_12B4_4E97_A07D_FF1BB44DF1F4__INCLUDED_)
#define AFX_GAME_H__6127CD08_12B4_4E97_A07D_FF1BB44DF1F4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <hge.h>
#include "GameComponent.h"
#include "WelcomeComponent.h"

class Game  
{
public:
	Exit();
	~Game();
	bool Update(float);
	SetComponent(GameComponent* component);
	Draw();
	GameComponent* GetComponent();
	static Game* GetInstance();
private:
	Game();
	Game(Game&);
	GameComponent* component;
	bool exit;
};

#endif // !defined(AFX_GAME_H__6127CD08_12B4_4E97_A07D_FF1BB44DF1F4__INCLUDED_)
