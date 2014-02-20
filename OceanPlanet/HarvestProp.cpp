// HarvestProp.cpp: implementation of the HarvestProp class.
//
//////////////////////////////////////////////////////////////////////

#include "HarvestProp.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

HarvestProp::HarvestProp(Bubble* bubble):Prop(bubble, HARVEST_TEXTURE_INDEX)
{

}

HarvestProp::~HarvestProp()
{

}

HarvestProp::Update(float delta)
{
	Prop::Update(delta);
}

HarvestProp::Explode(RunningComponent* component)
{
	Prop::Explode(component);
	delete component->spriteProduceStrategy;
	component->spriteProduceStrategy = new HarvestSpriteProduceStrategy(component);
}
