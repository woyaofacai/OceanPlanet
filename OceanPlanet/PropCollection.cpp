// PropCollection.cpp: implementation of the PropCollection class.
//
//////////////////////////////////////////////////////////////////////

#include "PropCollection.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PropCollection::PropCollection(RunningComponent* component)
:component(component)
{

}

PropCollection::~PropCollection()
{
	list<Prop*>::iterator it;
	while(!props.empty()) {
		it = props.begin();
		Prop* prop = *it;
		props.erase(it);
		delete prop;
	}
}

PropCollection::Add(Prop* prop)
{
	props.push_back(prop);
}

PropCollection::Update(float delta)
{
	list<Prop* >::iterator it = props.begin();
	for(; it != props.end(); it++)
	{
		if((*it)->OutOfScreen()) {
			list<Prop*>::iterator it2 = it;
			Prop* propToDelete = *it2;
			it--;
			props.erase(it2);
			delete propToDelete;
			continue;
		} 

		if((*it)->GetState() == BUBBLE_DISAPPEAR_STATE) {
			list<Prop*>::iterator it2 = it;
			Prop* propToDelete = *it2;
			it--;
			props.erase(it2);
			delete propToDelete;
			continue;
		}

		(*it)->Update(delta);
	}
}

PropCollection::Draw()
{
	list<Prop* >::iterator pit = props.begin();
	for(; pit != props.end(); pit++)
	{
		(*pit)->Draw();
	}
}

PropCollection::HitByNeedle(Needle* needle)
{
	list<Prop*>::iterator it = props.begin();
	for (;it != props.end(); it++)
	{
		Prop* prop = *it;
		if(prop->HitByNeedle(needle) && prop->GetState() == BUBBLE_MOVE_STATE) {
			prop->Explode(component);
		}
	}
}

//DEL PropCollection::HitByBomb(Bomb* bomb)
//DEL {
//DEL 	list<Prop*>::iterator it = props.begin();
//DEL 	for (;it != props.end(); it++)
//DEL 	{
//DEL 		Prop* prop = *it;
//DEL 		if(prop->HitByNeedle(needle) && prop->GetState() == BUBBLE_MOVE_STATE) {
//DEL 			prop->Explode(component);
//DEL 		}
//DEL 	}
//DEL }

PropCollection::ExplodeFishesNearBomb(Bomb* bomb)
{
	static maxRange = BOMB_MAX_RANGE;
	list<Prop *>::iterator it = props.begin();
	for(; it != props.end(); it++)
	{
		Prop *prop = *it;
		if(prop->GetState() == BUBBLE_MOVE_STATE &&
			prop->GetSqrtDistanceFromPoint(bomb->GetCenterX(), bomb->GetCenterY()) < maxRange * maxRange) {
			prop->Explode(component);
		}
	}
}
