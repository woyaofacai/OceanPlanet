// BaitCollection.cpp: implementation of the BaitCollection class.
//
//////////////////////////////////////////////////////////////////////

#include "BaitCollection.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

BaitCollection::BaitCollection(RunningComponent* component):component(component)
{

}

BaitCollection::~BaitCollection()
{
	list<Bait*>::iterator it;
	while(!baits.empty())
	{
		it = baits.begin();
		Bait* bait = *it;
		baits.erase(it);
		delete bait;
	}
}

BaitCollection::Add(Bait* bait)
{
	baits.push_back(bait);
}

BaitCollection::Add()
{
	Bait *bait = new Bait;
	baits.push_back(bait);
}

BaitCollection::Initialize()
{
	int i;
	for (i = 0; i < 5; i++)
	{
		Bait* lpBait = new Bait();
		baits.push_back(lpBait);
	}
}

BaitCollection::Draw()
{
	list<Bait *>::iterator it2 = baits.begin();
	for (; it2 != baits.end(); it2++)
	{
		Bait* bait = *it2;
		component->fnt->printf(bait->GetCenter().x, bait->GetCenter().y,HGETEXT_LEFT, "%s %d", "B", bait->Amount);
	}
}

BaitCollection::Remove(Bait* bait)
{
	list<Bait*>::iterator it = baits.begin();
	for(; it != baits.end(); it++)
	{
		if((*it) == bait) {
			baits.erase(it);
			delete bait;
			break;
		}
	}
}

//DEL BaitCollection::DistanceFromFish(Fish* fish)
//DEL {
//DEL 
//DEL 	
//DEL 	if(lpNearestBait != NULL) {
//DEL 		hgeVector vectorPointToNearestBait = lpNearestBait->GetCenter() - fishCenter;
//DEL 		//vectorPointToNearestBait.Normalize();
//DEL 		hgeVector* lpNormalizedNearestVector = vectorPointToNearestBait.Normalize();
//DEL 		fish->speed = fish->speed + (*lpNormalizedNearestVector) * 0.01f;
//DEL 		
//DEL 		if(distanceToNearestBait < 50.0f) {
//DEL 			fish->hungry = false;				
//DEL 			lpNearestBait->Amount--;
//DEL 			if(lpNearestBait->Amount <= 0) {
//DEL 
//DEL 			}
//DEL 		}
//DEL 	}
//DEL }

Bait* BaitCollection::GetNearestBait(Fish* fish, float& distanceToNearestBaitSq) 
{
	list<Bait*>::iterator it = baits.begin();
	Bait *lpNearestBait = NULL;
	hgeVector fishCenter = fish->GetCenter();
	for(; it != baits.end(); it++) 
	{
		Bait *lpBait = *it;
		if((fish->GetSpeed().x > 0 && lpBait->GetCenter().x > fish->positionX)
			|| (fish->GetSpeed().x < 0 && lpBait->GetCenter().x < fish->positionX)) {
			hgeVector vectorPointToBait = lpBait->GetCenter() - fishCenter;
			float vectorPointToBaitLengthSq = vectorPointToBait.x * vectorPointToBait.x + vectorPointToBait.y * vectorPointToBait.y;
			if(vectorPointToBaitLengthSq <= 40000.0f) {
				if(lpNearestBait == NULL || distanceToNearestBaitSq > vectorPointToBaitLengthSq) {
					lpNearestBait = lpBait;
					distanceToNearestBaitSq = vectorPointToBaitLengthSq;
				}
			}
		}
	}
	return lpNearestBait;
}