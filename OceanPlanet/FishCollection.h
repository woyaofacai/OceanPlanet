// FishCollection.h: interface for the FishCollection class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FISHCOLLECTION_H__6596802D_6603_4BA3_96F2_F960095E68F9__INCLUDED_)
#define AFX_FISHCOLLECTION_H__6596802D_6603_4BA3_96F2_F960095E68F9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <list>
#include "Fish.h"
#include "RunningComponent.h"

class FishCollection  
{
public:
	ChangeVelocity(float factor);
	ExplodeFishesNearBomb(Bomb*);
	FishCollection(RunningComponent* component);
	virtual ~FishCollection();
	Draw();
	Update(float);
	Add(Fish*);
	CheckNeedleHit(Needle *);
private:
	list<Fish*> fishes;
	RunningComponent* component;
};

#endif // !defined(AFX_FISHCOLLECTION_H__6596802D_6603_4BA3_96F2_F960095E68F9__INCLUDED_)
