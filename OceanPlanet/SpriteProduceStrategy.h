// SpriteProduceStrategy.h: interface for the SpriteProduceStrategy class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SPRITEPRODUCESTRATEGY_H__E24C1344_719A_410A_A1ED_EC60829399D4__INCLUDED_)
#define AFX_SPRITEPRODUCESTRATEGY_H__E24C1344_719A_410A_A1ED_EC60829399D4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "constants.h"

class SpriteProduceStrategy  
{
public:
	SpriteProduceStrategy();
	virtual ~SpriteProduceStrategy();
	virtual AddProp(float) = 0;
	virtual AddFish(float) = 0;
protected:
	float timeSinceLastAddProp;
	float timeSinceLastAddFish;
};

#endif // !defined(AFX_SPRITEPRODUCESTRATEGY_H__E24C1344_719A_410A_A1ED_EC60829399D4__INCLUDED_)
