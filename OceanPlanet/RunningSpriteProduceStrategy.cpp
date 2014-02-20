// RunningSpriteProduceStrategy.cpp: implementation of the RunningSpriteProduceStrategy class.
//
//////////////////////////////////////////////////////////////////////

#include "RunningSpriteProduceStrategy.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

RunningSpriteProduceStrategy::RunningSpriteProduceStrategy(RunningComponent* component)
:component(component)
{
	
}

RunningSpriteProduceStrategy::~RunningSpriteProduceStrategy()
{

}

RunningSpriteProduceStrategy::AddFish(float delta)
{
	timeSinceLastAddFish += delta;
	if(timeSinceLastAddFish > ADD_FISH_TIME_INTERVAL) {
		timeSinceLastAddFish = 0.0f;
		RunningStateData *model = component->model;
		if(rand() % 1000 < model->FishProbability) {
			Fish *fish = SpriteFactory::GetInstance()->CreateFish(component->model);
			fish->SetComponent(component);
			component->fishes->Add(fish);
		}
	}
}

RunningSpriteProduceStrategy::AddProp(float delta)
{
	timeSinceLastAddProp += delta;
	if(timeSinceLastAddProp > ADD_PROP_TIME_INTERVAL) {
		timeSinceLastAddProp = 0.0f;
		RunningStateData *model = component->model;
		PropCollection *propCollection= component->props;
		if(model->propProbabilities[TREASURE_POSSIBILITY_INDEX] != 0 
		&& rand() % 1000 < model->propProbabilities[TREASURE_POSSIBILITY_INDEX]) {
			Prop *prop = SpriteFactory::GetInstance()->CreateTreasure(model);
			propCollection->Add(prop);
		}
		
		if(model->propProbabilities[SKELETON_POSSIBILITY_INDEX] != 0
			&& rand() % 1000 < model->propProbabilities[SKELETON_POSSIBILITY_INDEX]) {
			Prop *prop = SpriteFactory::GetInstance()->CreateSkeleten(model);
			propCollection->Add(prop);
		}
		
		if(model->propProbabilities[DECELERATE_POSSIBILITY_INDEX] != 0
			&& rand() % 1000 < model->propProbabilities[DECELERATE_POSSIBILITY_INDEX]) {
			Prop *prop = SpriteFactory::GetInstance()->CreateDecelerateProp(model);
			propCollection->Add(prop);
		}
		
		if(model->propProbabilities[ACCELERATE_POSSIBILITY_INDEX] != 0
			&& rand() % 1000 < model->propProbabilities[ACCELERATE_POSSIBILITY_INDEX]) {
			Prop *prop = SpriteFactory::GetInstance()->CreateAccelerateProp(model);
			propCollection->Add(prop);
		}
		
		if(model->propProbabilities[HARVEST_POSSIBILITY_INDEX] != 0
			&& rand() % 1000 < model->propProbabilities[HARVEST_POSSIBILITY_INDEX]) {
			Prop *prop = SpriteFactory::GetInstance()->CreateHarvestProp(model);
			propCollection->Add(prop);
		}
	}
}