// UnplacedBombState.h: interface for the UnplacedBombState class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UNPLACEDBOMBSTATE_H__325430B1_9067_4142_A4E6_71AAE8693A6F__INCLUDED_)
#define AFX_UNPLACEDBOMBSTATE_H__325430B1_9067_4142_A4E6_71AAE8693A6F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "GameState.h"
#include "Bomb.h"
#include "PlacedBombState.h"

class UnplacedBombState : public BombState
{
public:
	UnplacedBombState();
	virtual ~UnplacedBombState();
	virtual Update(Bomb*, float);
	virtual Draw(Bomb*);
	virtual Enter(Bomb*);
	virtual Leave(Bomb*);
private:
	SendMessage(int, Bomb*);
};

#endif // !defined(AFX_UNPLACEDBOMBSTATE_H__325430B1_9067_4142_A4E6_71AAE8693A6F__INCLUDED_)
