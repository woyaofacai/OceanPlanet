// ExplodeBombState.h: interface for the ExplodeBombState class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXPLODEBOMBSTATE_H__1792AFFE_D6B4_4126_A1D8_9EE4E7DEA14B__INCLUDED_)
#define AFX_EXPLODEBOMBSTATE_H__1792AFFE_D6B4_4126_A1D8_9EE4E7DEA14B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <hge.h>
#include <hgesprite.h>
#include <hgeparticle.h>

#include "ResourceFactory.h"
#include "BombState.h"
#include "Bomb.h"


extern HGE* hge;

class ExplodeBombState : public BombState  
{
public:
	ExplodeBombState();
	virtual ~ExplodeBombState();
	virtual Update(Bomb*, float);
	virtual Draw(Bomb*);
	virtual Enter(Bomb*);
	virtual Leave(Bomb*);
private:
	hgeParticleSystem* bombParticle;
	hgeSprite* particleSprite;
	hgeSprite* powSprite;
	int powTextureWidth, powTextureHeight;
	float powTextureScale;
	SendMessage(int, Bomb*);
};

#endif // !defined(AFX_EXPLODEBOMBSTATE_H__1792AFFE_D6B4_4126_A1D8_9EE4E7DEA14B__INCLUDED_)
