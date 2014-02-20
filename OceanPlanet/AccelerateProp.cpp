// AccelerateProp.cpp: implementation of the AccelerateProp class.
//
//////////////////////////////////////////////////////////////////////

#include "AccelerateProp.h"
#include "RunningComponent.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

AccelerateProp::AccelerateProp(Bubble* bubble):Prop(bubble, ACCELERATE_TEXTURE_INDEX)
{
	
}

AccelerateProp::~AccelerateProp()
{

}

AccelerateProp::Update(float delta)
{
	Prop::Update(delta);
}

AccelerateProp::Explode(RunningComponent* component)
{
	Prop::Explode(component);
	if(component->GetModel()->NeedleVelocity < MAX_NEEDLE_VELOCITY) {
		component->GetModel()->NeedleVelocity *= 1.5f;
		component->GetNeedles()->ChangeVelocity(1.5f);
	}

	component->GetModel()->BombCountDown -= 5;
	if(component->GetModel()->BombCountDown < MIN_BOMB_COUNTDOWN)
		component->GetModel()->BombCountDown = MIN_BOMB_COUNTDOWN;
}
