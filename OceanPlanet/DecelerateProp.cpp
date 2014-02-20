// DecelerateProp.cpp: implementation of the DecelerateProp class.
//
//////////////////////////////////////////////////////////////////////

#include "DecelerateProp.h"
#include "RunningComponent.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

DecelerateProp::DecelerateProp(Bubble* bubble):Prop(bubble, DECELERATE_TEXTURE_INDEX)
{

}

DecelerateProp::~DecelerateProp()
{
	
}

DecelerateProp::Update(float delta)
{
	Prop::Update(delta);

}

DecelerateProp::Explode(RunningComponent* component)
{
	Prop::Explode(component);
	if(component->GetModel()->NeedleVelocity > MIN_NEEDLE_VELOCITY) {
		component->GetModel()->NeedleVelocity *= 0.75f;
		component->GetNeedles()->ChangeVelocity(0.75f);
	}

	component->GetModel()->BombCountDown += 5;
	if(component->GetModel()->BombCountDown > MAX_BOMB_COUNTDOWN)
		component->GetModel()->BombCountDown = MAX_BOMB_COUNTDOWN;
}