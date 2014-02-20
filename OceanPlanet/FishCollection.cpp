// FishCollection.cpp: implementation of the FishCollection class.
//
//////////////////////////////////////////////////////////////////////

#include "FishCollection.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

FishCollection::FishCollection(RunningComponent* component)
:component(component)
{

}

FishCollection::~FishCollection()
{
	list<Fish *>::iterator it;
	Fish *fishToDelete = NULL;
	while(!fishes.empty()) {
		it = fishes.begin();
		fishToDelete = (*it);
		fishes.erase(it);
		delete fishToDelete;
	}
}

FishCollection::Draw()
{
	list<Fish *>::iterator it = fishes.begin();
	for(; it != fishes.end(); it++)
	{
		(*it)->Draw();
	}
}

FishCollection::Update(float delta)
{
	list<Fish *>::iterator it = fishes.begin();
	for(; it != fishes.end(); it++)
	{
		if((*it)->OutOfScreen()) {
			list<Fish *>::iterator it2;
			it2 = it;
			Fish *fish = (*it);
			it--;
			fishes.erase(it2);
			delete fish;
		}
		else if((*it)->GetTimeLeftToDie() <= 0.0f) {
			list<Fish *>::iterator it2;
			it2 = it;
			Fish *fish = (*it);
			it--;
			fishes.erase(it2);
			ScoreAnimation *scoreAnimation = fish->GetScoreAnimation();
			scoreAnimation->StartToMove();
			delete fish;
		}
		else {
			(*it)->Update(delta);
		}
	}
}

FishCollection::Add(Fish* fish)
{
	fishes.push_back(fish);
}

FishCollection::CheckNeedleHit(Needle *needle)
{
	list<Fish*>::iterator it = fishes.begin();
	for (; it != fishes.end(); it++)
	{
		if(!(*it)->GetDyingState() && needle->Hit(*it)) {
			(*it)->SetDying();
			ScoreAnimation *scoreAnimation = new ScoreAnimation((*it)->GetScore(), (*it)->GetCenter().x, (*it)->GetCenter().y);
			component->scoreAnimations.push_back(scoreAnimation);
			(*it)->SetScoreAnimation(scoreAnimation);
		}
	}
}

FishCollection::ExplodeFishesNearBomb(Bomb* bomb)
{
	static maxRange = BOMB_MAX_RANGE;
	list<Fish *>::iterator it = fishes.begin();
	for(; it != fishes.end(); it++)
	{
		Fish *fish = (*it);
		if(!fish->GetDyingState() && fish->GetSqrtDistanceFromPoint(bomb->GetCenterX(), bomb->GetCenterY()) < maxRange * maxRange) {
			fish->KilldedByBomb();
			ScoreAnimation *scoreAnimation = new ScoreAnimation((*it)->GetScore(), (*it)->GetCenter().x, (*it)->GetCenter().y);
			component->scoreAnimations.push_back(scoreAnimation);
			fish->SetScoreAnimation(scoreAnimation);
		}
	}
}

FishCollection::ChangeVelocity(float factor)
{
	list<Fish*>::iterator it = fishes.begin();
	for(; it != fishes.end(); it++)
	{
		(*it)->ChangeVelocity(factor);
	}
}

