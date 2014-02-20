// NeedleCollection.h: interface for the NeedleCollection class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NEEDLECOLLECTION_H__C556BB65_824D_47AB_B70B_9D89D226103E__INCLUDED_)
#define AFX_NEEDLECOLLECTION_H__C556BB65_824D_47AB_B70B_9D89D226103E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <list>
#include "Needle.h"
#include "RunningComponent.h"

class NeedleCollection  
{
public:
	ChangeVelocity(float);
	NeedleCollection(RunningComponent*);
	virtual ~NeedleCollection();
	Add(Needle*);
	Update(float);
	Draw();
private:
	RunningComponent* component;
	list<Needle*> needles;
};

#endif // !defined(AFX_NEEDLECOLLECTION_H__C556BB65_824D_47AB_B70B_9D89D226103E__INCLUDED_)
