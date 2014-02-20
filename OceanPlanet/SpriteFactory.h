// SpriteFactory.h: interface for the SpriteFactory class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SPRITEFACTORY_H__AC6E5EDD_3365_4CCB_B8F5_AB1D39E78EC5__INCLUDED_)
#define AFX_SPRITEFACTORY_H__AC6E5EDD_3365_4CCB_B8F5_AB1D39E78EC5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <hgesprite.h>

#include "Fish.h"
#include "Bubble.h"
#include "Prop.h"
#include "Treasure.h"
#include "Skeleten.h"
#include "DecelerateProp.h"
#include "RunningStateData.h"
#include "AccelerateProp.h"
#include "HarvestProp.h"

class HarvestProp;

class SpriteFactory  
{
public:
	
	Bubble* CreateBubble();
	static SpriteFactory* GetInstance();
	Fish* CreateFish(RunningStateData* model);
	Treasure* CreateTreasure(RunningStateData*);
	Skeleten* CreateSkeleten(RunningStateData*);
	DecelerateProp* CreateDecelerateProp(RunningStateData*);
	AccelerateProp* CreateAccelerateProp(RunningStateData*);
	HarvestProp* CreateHarvestProp(RunningStateData*);
	Needle* CreateNeedle(RunningStateData*, float x, float y);
	~SpriteFactory();
private:
	hgeVector getBubbleVelocity();
	SpriteFactory();
	SpriteFactory(SpriteFactory&);
	hgeVector getFishSpeed(bool left, RunningStateData*);
};

#endif // !defined(AFX_SPRITEFACTORY_H__AC6E5EDD_3365_4CCB_B8F5_AB1D39E78EC5__INCLUDED_)
