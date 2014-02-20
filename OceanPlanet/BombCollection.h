// BombCollection.h: interface for the BombCollection class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BOMBCOLLECTION_H__719F363D_C080_40AD_BF49_5B57ABA706E7__INCLUDED_)
#define AFX_BOMBCOLLECTION_H__719F363D_C080_40AD_BF49_5B57ABA706E7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <list>
#include "Bomb.h"
#include "RunningComponent.h"

class BombCollection  
{
public:
	BombCollection(RunningComponent*);
	virtual ~BombCollection();
	Add(Bomb*);
	Update(float);
	Draw();
private:
	list<Bomb*> bombs;
	RunningComponent* component;
};

#endif // !defined(AFX_BOMBCOLLECTION_H__719F363D_C080_40AD_BF49_5B57ABA706E7__INCLUDED_)
