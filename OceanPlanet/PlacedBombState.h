// PlacedBombState.h: interface for the PlacedBombState class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PLACEDBOMBSTATE_H__210B884F_8968_4B43_ABD0_F43E0F48D916__INCLUDED_)
#define AFX_PLACEDBOMBSTATE_H__210B884F_8968_4B43_ABD0_F43E0F48D916__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <hge.h>
#include <hgefont.h>

#include "Bomb.h"
#include "BombState.h"
#include "ExplodeBombState.h"

extern HGE* hge;

class PlacedBombState : public BombState  
{
public:
	PlacedBombState(int);
	virtual ~PlacedBombState();
	virtual Update(Bomb*, float);
	virtual Draw(Bomb*);
	virtual Enter(Bomb*);
	virtual Leave(Bomb*);

private:
	int leftTime;
	float timeSinceLastUpdateLeftTime;
	hgeFont *fnt;
};

#endif // !defined(AFX_PLACEDBOMBSTATE_H__210B884F_8968_4B43_ABD0_F43E0F48D916__INCLUDED_)
