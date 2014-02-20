// ScoreAnimation.h: interface for the ScoreAnimation class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SCOREANIMATION_H__5FDA4B8C_E50E_4290_BCF8_9E0F8D2EFE64__INCLUDED_)
#define AFX_SCOREANIMATION_H__5FDA4B8C_E50E_4290_BCF8_9E0F8D2EFE64__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <hge.h>
#include <hgefont.h>
#include <hgevector.h>
#include <hgesprite.h>
#include <hgeparticle.h>

#include "constants.h"
#include "ResourceFactory.h"

extern HGE* hge;

class ScoreAnimation  
{
public:
	int GetScore();
	StartToMove();
	ScoreAnimation(int, float, float);
	virtual ~ScoreAnimation();
	Update(float);
	Draw();
	bool ReachDestination();
private:
	int score;
	hgeFont* fnt;
	float positionX, positionY;
	hgeVector speed;
	hgeVector acceleration;
	bool isMoving;

	hgeParticleSystem* particleSystem;
	hgeSprite* particleSprite;
	
	static float accelerationValue;
	static float initSpeedValue;

};

#endif // !defined(AFX_SCOREANIMATION_H__5FDA4B8C_E50E_4290_BCF8_9E0F8D2EFE64__INCLUDED_)
