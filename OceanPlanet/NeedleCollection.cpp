// NeedleCollection.cpp: implementation of the NeedleCollection class.
//
//////////////////////////////////////////////////////////////////////

#include "NeedleCollection.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

NeedleCollection::NeedleCollection(RunningComponent* component)
:component(component)
{

}

NeedleCollection::~NeedleCollection()
{

}

NeedleCollection::Add(Needle* needle)
{
	needles.push_back(needle);
}

NeedleCollection::Update(float delta)
{
	list<Needle *>::iterator it = needles.begin();
	for(; it != needles.end(); it++)
	{
		if((*it)->OutOfScreen()) {
			list<Needle *>::iterator nit2 = it;
			Needle *needle = (*it);
			it--;
			needles.erase(nit2);
			delete needle;
			continue;
		}
		else {
			component->props->HitByNeedle(*it);
			(*it)->Update();
		}

		component->fishes->CheckNeedleHit(*it);
	}
}

NeedleCollection::Draw()
{
	list<Needle *>::iterator it = needles.begin();
	for (; it != needles.end(); it++)
	{
		Needle* needle = *it;
		needle->Draw();
	}
}


NeedleCollection::ChangeVelocity(float factor)
{
	list<Needle *>::iterator it = needles.begin();
	for (; it != needles.end(); it++)
	{
		(*it)->ChangeVelocity(factor);
	}
}
