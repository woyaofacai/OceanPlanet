// Treasure.h: interface for the Treasure class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TREASURE_H__DDE23399_87FB_43E0_9259_0F2DDACD9EF7__INCLUDED_)
#define AFX_TREASURE_H__DDE23399_87FB_43E0_9259_0F2DDACD9EF7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Prop.h"
#include "ScoreAnimation.h"

class Prop;

class Treasure : public Prop  
{
public:
	virtual  Draw();
	virtual  Explode(RunningComponent*);
	Treasure(Bubble *, int);
	virtual ~Treasure();
	virtual Update(float);
private:
	int score;
	hgeParticleSystem* particle;
	hgeSprite* particleSprite;
	ScoreAnimation* scoreAnimation;
};

#endif // !defined(AFX_TREASURE_H__DDE23399_87FB_43E0_9259_0F2DDACD9EF7__INCLUDED_)
