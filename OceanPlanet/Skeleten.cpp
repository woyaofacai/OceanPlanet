// Skeleten.cpp: implementation of the Skeleten class.
//
//////////////////////////////////////////////////////////////////////

#include "Skeleten.h"
#include "RunningComponent.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Skeleten::Skeleten(Bubble *bubble):Prop(bubble,SKELETON_TEXTURE_INDEX)
{
	
}

Skeleten::~Skeleten()
{
	
}

Skeleten::Update(float delta)
{
	Prop::Update(delta);
}

Skeleten::Explode(RunningComponent* component)
{
	Prop::Explode(component);
	component->GetModel()->Life--;
	if(component->GetModel()->Life < 0) {
		if(component->GetModel()->ArcadeMode)
			component->OnMessage(ARCADE_OVER_MSG);
		else 
			component->OnMessage(TASKFAIL_MSG);
	}
}
