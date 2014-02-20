// PropCollection.h: interface for the PropCollection class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PROPCOLLECTION_H__5E4741F7_7163_43D3_8216_727F3C3D2E25__INCLUDED_)
#define AFX_PROPCOLLECTION_H__5E4741F7_7163_43D3_8216_727F3C3D2E25__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <list>
#include "Prop.h"
#include "RunningComponent.h"

class PropCollection  
{
public:
	ExplodeFishesNearBomb(Bomb*);
	HitByNeedle(Needle*);
	PropCollection(RunningComponent*);
	virtual ~PropCollection();
	Add(Prop*);
	Update(float);
	Draw();
private:
	list<Prop*> props;
	RunningComponent* component;
};

#endif // !defined(AFX_PROPCOLLECTION_H__5E4741F7_7163_43D3_8216_727F3C3D2E25__INCLUDED_)
