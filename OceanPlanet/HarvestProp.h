// HarvestProp.h: interface for the HarvestProp class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_HARVESTPROP_H__6C6F5A19_0A5F_4C0C_A351_EC1AD2262649__INCLUDED_)
#define AFX_HARVESTPROP_H__6C6F5A19_0A5F_4C0C_A351_EC1AD2262649__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Prop.h"
#include "HarvestSpriteProduceStrategy.h"

class HarvestProp : public Prop
{
public:
	virtual  Explode(RunningComponent* component);
	HarvestProp(Bubble*);
	virtual ~HarvestProp();
	virtual Update(float);
};

#endif // !defined(AFX_HARVESTPROP_H__6C6F5A19_0A5F_4C0C_A351_EC1AD2262649__INCLUDED_)
