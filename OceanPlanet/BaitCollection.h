// BaitCollection.h: interface for the BaitCollection class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BAITCOLLECTION_H__5E377762_02FD_41C4_83E2_989D1D34CFF0__INCLUDED_)
#define AFX_BAITCOLLECTION_H__5E377762_02FD_41C4_83E2_989D1D34CFF0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <list>
#include "Bait.h"
#include "RunningComponent.h"

class BaitCollection  
{
public:
	Remove(Bait*);
	BaitCollection(RunningComponent*);
	virtual ~BaitCollection();
	Initialize();
	Add();
	Add(Bait* bait);
	Draw();
	Bait* GetNearestBait(Fish*,float&);
private:
	list<Bait*> baits;
	RunningComponent* component;
};

#endif // !defined(AFX_BAITCOLLECTION_H__5E377762_02FD_41C4_83E2_989D1D34CFF0__INCLUDED_)
