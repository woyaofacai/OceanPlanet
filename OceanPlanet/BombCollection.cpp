// BombCollection.cpp: implementation of the BombCollection class.
//
//////////////////////////////////////////////////////////////////////

#include "BombCollection.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

BombCollection::BombCollection(RunningComponent* component)
:component(component)
{

}

BombCollection::~BombCollection()
{
	list<Bomb*>::iterator it;
	while(!bombs.empty()) {
		it = bombs.begin();
		Bomb* bomb = *it;
		bombs.erase(it);
		delete bomb;
	}
}

BombCollection::Add(Bomb* bomb)
{
	bombs.push_back(bomb);
}

BombCollection::Update(float delta)
{
	list<Bomb* >::iterator bit = bombs.begin();
	for (; bit != bombs.end(); bit++)
	{
		(*bit)->Update(delta);
		if(!(*bit)->IsValid()) {
			list<Bomb* >::iterator bit2 = bit;
			bit--;
			Bomb* bombToDelete = (*bit2);
			bombs.erase(bit2);
			delete bombToDelete;
		}
	}
}

BombCollection::Draw()
{
	list<Bomb* >::iterator bit = bombs.begin();
	for (; bit != bombs.end(); bit++)
	{
		(*bit)->Draw();
	}
}

//DEL BombCollection::ExplodePropsNearBomb(Bomb* bomb)
//DEL {
//DEL 	
//DEL }
