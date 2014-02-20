// Bubble.h: interface for the Bubble class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BUBBLE_H__CB3755FC_A63F_47E2_8600_D1937E0979E6__INCLUDED_)
#define AFX_BUBBLE_H__CB3755FC_A63F_47E2_8600_D1937E0979E6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <hge.h>
#include <hgesprite.h>
#include <hgevector.h>
#include <hgeparticle.h>
#include "ResourceFactory.h"

extern HGE *hge;
class Prop;

class Bubble  
{
friend class Prop;
friend class Treasure;
public:
	hgeVector GetCenter();
	float GetPositionY();
	float GetPositionX();
	Explode();
	bool OutOfScreen();
	Bubble(float, float, hgeVector, hgeSprite*);
	virtual ~Bubble();
	Update(float delta);
	Draw();
	float GetWidth();
	float GetHeight();
	bool InsidePoint(float x, float y);
private:
	float timeSinceBurst;
	int state;
	float positionX, positionY;
	float width, height;
	hgeSprite* sprite;
	hgeSprite* burstParticleSprite;
	hgeVector velocity;
	hgeParticleSystem* burstParticle;
};

#endif // !defined(AFX_BUBBLE_H__CB3755FC_A63F_47E2_8600_D1937E0979E6__INCLUDED_)
