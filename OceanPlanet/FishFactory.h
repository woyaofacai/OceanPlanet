// FishFactory.h: interface for the FishFactory class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FISHFACTORY_H__4D91DBBE_1E5C_4A50_809D_72149B3EAB68__INCLUDED_)
#define AFX_FISHFACTORY_H__4D91DBBE_1E5C_4A50_809D_72149B3EAB68__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Fish.h"

class FishFactory  
{
public:
	FishFactory();
	virtual ~FishFactory();
	static Fish* GetFish();
private:
	static hgeVector getSpeedVector(bool left);
};

#endif // !defined(AFX_FISHFACTORY_H__4D91DBBE_1E5C_4A50_809D_72149B3EAB68__INCLUDED_)
