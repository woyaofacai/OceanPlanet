// HarvestSpriteProduceStrategy.h: interface for the HarvestSpriteProduceStrategy class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_HARVESTSPRITEPRODUCESTRATEGY_H__B860A5F2_AE47_48D1_B273_9198EF5AA576__INCLUDED_)
#define AFX_HARVESTSPRITEPRODUCESTRATEGY_H__B860A5F2_AE47_48D1_B273_9198EF5AA576__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SpriteProduceStrategy.h"
#include "SpriteFactory.h"
#include "RunningComponent.h"

class HarvestSpriteProduceStrategy : public SpriteProduceStrategy  
{
public:
	HarvestSpriteProduceStrategy(RunningComponent*);
	virtual ~HarvestSpriteProduceStrategy();
	virtual AddProp(float);
	virtual AddFish(float);
private:
	RunningComponent* component;
	float harvestLastTime;
};

#endif // !defined(AFX_HARVESTSPRITEPRODUCESTRATEGY_H__B860A5F2_AE47_48D1_B273_9198EF5AA576__INCLUDED_)
