// HarvestSpriteProduceStrategy.cpp: implementation of the HarvestSpriteProduceStrategy class.
//
//////////////////////////////////////////////////////////////////////

#include "HarvestSpriteProduceStrategy.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

HarvestSpriteProduceStrategy::HarvestSpriteProduceStrategy(RunningComponent* component)
:component(component),harvestLastTime(0.0f)
{

}

HarvestSpriteProduceStrategy::~HarvestSpriteProduceStrategy()
{
	
}

HarvestSpriteProduceStrategy::AddFish(float delta)
{
	timeSinceLastAddFish += delta;
	if(timeSinceLastAddFish > ADD_FISH_TIME_INTERVAL) {
		timeSinceLastAddFish = 0.0f;
		if(rand() % 5 == 0) {
			Fish *fish = SpriteFactory::GetInstance()->CreateFish(component->model);
			fish->SetComponent(component);
			component->fishes->Add(fish);
		}
	}
}

HarvestSpriteProduceStrategy::AddProp(float delta)
{
	timeSinceLastAddProp += delta;
	harvestLastTime += delta;
	if(timeSinceLastAddProp > ADD_PROP_TIME_INTERVAL) {
		timeSinceLastAddProp = 0.0f;
		RunningStateData *model = component->model;
		PropCollection *propCollection= component->props;
		if(model->propProbabilities[TREASURE_POSSIBILITY_INDEX] != 0 
			&& rand() % 1000 < model->propProbabilities[TREASURE_POSSIBILITY_INDEX]) {
			Prop *prop = SpriteFactory::GetInstance()->CreateTreasure(model);
			propCollection->Add(prop);
		}
	}

	if(harvestLastTime > 10.0f) {
		SpriteProduceStrategy* currentStrategy = component->spriteProduceStrategy;
		component->spriteProduceStrategy = new RunningSpriteProduceStrategy(component);
		delete currentStrategy;
	}
}