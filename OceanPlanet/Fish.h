// Fish.h: interface for the Fish class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FISH_H__80D3FEE3_0EA9_4A73_898A_F9315D8AD05B__INCLUDED_)
#define AFX_FISH_H__80D3FEE3_0EA9_4A73_898A_F9315D8AD05B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <hgesprite.h>
#include <hgevector.h>
#include <hgeparticle.h>
#include <list>

#include "constants.h"
#include "Bait.h"
#include "ScoreAnimation.h"

//#include "RunningComponent.h"
using namespace std;

class RunningComponent;
class BaitCollection;

class Fish
{
friend class BaitCollection;
public:
	ChangeVelocity(float);
	Fish(int, hgeSprite *sprite, int, float, float, hgeVector);
	KilldedByBomb();
	float GetSqrtDistanceFromPoint(float x, float y);
	ScoreAnimation* GetScoreAnimation();
	SetScoreAnimation(ScoreAnimation*);
	int GetScore();
	hgeVector& GetSpeed();
	bool GetDyingState();
	bool InsideBoundaryRect(float x, float y);
	hgeRect GetBoundaryRect();
	bool OutOfScreen();
	float getHeight();
	float getWidth();
	MoveTo(float x, float y);
	Draw();
	Update(float);
	SetComponent(RunningComponent* lpComponent);
	hgeVector GetCenter();
	SetDying();
	float GetTimeLeftToDie();
	~Fish();
private:
	int kindId;
	hgeSprite *sprite;
	int score;
	float positionX;
	float positionY;
	HTEXTURE texture;
	hgeVector speed;
	float width;
	float height;
	bool hungry;
	hgeParticleSystem* particleSystem;
	RunningComponent* lpComponent;
	bool dying;
	float timeLeftToDie;
	hgeSprite* particleSprite;
	ScoreAnimation *scoreAnimation;
};

#endif // !defined(AFX_FISH_H__80D3FEE3_0EA9_4A73_898A_F9315D8AD05B__INCLUDED_)
