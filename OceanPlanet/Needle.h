// Needle.h: interface for the Needle class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NEEDLE_H__9D23B560_9219_4DBE_B0A1_B5B7097F4DF4__INCLUDED_)
#define AFX_NEEDLE_H__9D23B560_9219_4DBE_B0A1_B5B7097F4DF4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <hgesprite.h>
#include <hgevector.h>
#include <list>

#include "constants.h"
#include "Bait.h"
#include "Fish.h"
//#include "RunningComponent.h"
using namespace std;

class RunningComponent;

class Needle  
{
public:
	ChangeVelocity(float);
	float GetPositionY();
	float GetPositionX();
	bool Hit(Fish* fish);
	Needle(hgeSprite *sprite, float positionX, float positionY, hgeVector speed, float);
	virtual ~Needle();
	Draw();
	Update();
	SetComponent(RunningComponent* lpComponent);
	bool OutOfScreen();
private:
	hgeSprite *sprite;
	int score;
	float positionX;
	float positionY;
	HTEXTURE texture;
	hgeVector speed;
	float width;
	float height;
	bool hungry;
	RunningComponent* lpComponent;
//	hgeVector acceleration;
	hgeVector direction;
};

#endif // !defined(AFX_NEEDLE_H__9D23B560_9219_4DBE_B0A1_B5B7097F4DF4__INCLUDED_)
