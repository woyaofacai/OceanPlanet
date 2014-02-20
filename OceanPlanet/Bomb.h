// Bomb.h: interface for the Bomb class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BOMB_H__50AFB5FC_877E_433F_B2B9_F8418B6FC842__INCLUDED_)
#define AFX_BOMB_H__50AFB5FC_877E_433F_B2B9_F8418B6FC842__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <hge.h>
#include <hgesprite.h>

#include "constants.h"
#include "ResourceFactory.h"
#include "BombState.h"
#include "UnplacedBombState.h"
#include "RunningComponent.h"

extern HGE* hge;

class Bomb  
{
friend class UnplacedBombState;
friend class PlacedBombState;
friend class ExplodeBombState;

public:
	Bomb(float, float, RunningComponent* lpComponent = NULL);
	virtual ~Bomb();
	ChangeState(BombState *);
	static HTEXTURE GetUnplacedTexture();
	Update(float);
	Draw();
	float GetCenterX();
	float GetCenterY();
	bool OnMessage(int messageType);
	RunningComponent *lpComponent;
	bool IsValid();
private:
	BombState* currentState;
	hgeSprite* bombSprite;
	int width;
	int height;
	float positionX, positionY;
	static HTEXTURE unplacedTexture;
	bool valid;
};

#endif // !defined(AFX_BOMB_H__50AFB5FC_877E_433F_B2B9_F8418B6FC842__INCLUDED_)
