// SpriteFactory.cpp: implementation of the SpriteFactory class.
//
//////////////////////////////////////////////////////////////////////

#include "SpriteFactory.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

SpriteFactory::SpriteFactory()
{
	
}

SpriteFactory::SpriteFactory(SpriteFactory&)
{
	
}

SpriteFactory::~SpriteFactory()
{

}

SpriteFactory* SpriteFactory::GetInstance()
{
	SpriteFactory static factory;
	return &factory;
}

Fish* SpriteFactory::CreateFish(RunningStateData* model)
{
	int kind = rand() % FISH_KIND_NUM;
	HTEXTURE fishTexture;
	int positionX = 0;
	int positionY = 0;
	hgeSprite *sprite = NULL;
	hgeVector speedVector;
	int kindId = 0;
	
	if(rand()%2 == 0) {
		kindId = LEFTFISH_TEXTURE_INDEX + kind;
		fishTexture = ResourceFactory::GetTexture(kindId);
		sprite = new hgeSprite(fishTexture, 0, 0, hge->Texture_GetWidth(fishTexture), hge->Texture_GetHeight(fishTexture));
		sprite->SetZ(FISH_Z);
		positionX = 0 - hge->Texture_GetWidth(fishTexture);
		speedVector = getFishSpeed(true, model);
	}
	else {
		kindId = RIGHTFISH_TEXTURE_INDEX + kind;
		fishTexture = ResourceFactory::GetTexture(kindId);
		sprite = new hgeSprite(fishTexture, 0, 0, hge->Texture_GetWidth(fishTexture), hge->Texture_GetHeight(fishTexture));
		sprite->SetZ(FISH_Z);
		positionX = SCREEN_WIDTH + hge->Texture_GetWidth(fishTexture);
		speedVector = getFishSpeed(false, model);
	}
	sprite->SetZ(FISH_Z);
	positionY = hge->Random_Int(150, SCREEN_HEIGHT - 150);
	Fish *fish = new Fish(kindId, sprite, 10, positionX, positionY, speedVector);
	return fish;
}

hgeVector SpriteFactory::getFishSpeed(bool left, RunningStateData* model)
{
	float speed_y = hge->Random_Float(-model->MinFishVelocity, model->MinFishVelocity);
	float speed_x = hge->Random_Float(model->MinFishVelocity, model->MaxFishVelocity);
	if(!left) {
		speed_x = -speed_x;
	}
	return hgeVector(speed_x, speed_y);
}

Treasure* SpriteFactory::CreateTreasure(RunningStateData* model)
{
	Bubble *bubble = this->CreateBubble();
	int score = rand() % model->MaxTreasureScore + 1;
	Treasure *treasure = new Treasure(bubble, score);
	return treasure;
}

Skeleten* SpriteFactory::CreateSkeleten(RunningStateData* model)
{
	Bubble *bubble = this->CreateBubble();
	Skeleten* skeleten = new Skeleten(bubble);
	return skeleten;
}

DecelerateProp* SpriteFactory::CreateDecelerateProp(RunningStateData* model)
{
	Bubble *bubble = this->CreateBubble();
	DecelerateProp* decelerate = new DecelerateProp(bubble);
	return decelerate;
}

AccelerateProp* SpriteFactory::CreateAccelerateProp(RunningStateData* model)
{
	Bubble *bubble = this->CreateBubble();
	AccelerateProp* accelerate = new AccelerateProp(bubble);
	return accelerate;
}

HarvestProp* SpriteFactory::CreateHarvestProp(RunningStateData* model)
{
	Bubble *bubble = this->CreateBubble();
	HarvestProp* harvest = new HarvestProp(bubble);
	return harvest;
}


hgeVector SpriteFactory::getBubbleVelocity()
{
	float speed_y = -hge->Random_Float(0.5f, 1.5f);
	return hgeVector(0.1f, speed_y);
}

Bubble* SpriteFactory::CreateBubble()
{
	HTEXTURE bubbleTexture = ResourceFactory::GetTexture(BUBBLE_TEXTURE_INDEX);
	hgeSprite *bubbleSprite = new hgeSprite(bubbleTexture, 0, 0, hge->Texture_GetWidth(bubbleTexture), hge->Texture_GetHeight(bubbleTexture));
	bool left = (rand() % 2 == 0) ? true : false;
	float positionX = hge->Random_Int(0, SCREEN_WIDTH - (hge->Texture_GetWidth(bubbleTexture) >> 1));
	float positionY = SCREEN_HEIGHT;
	/*
	if(left) {
		positionX = -hge->Texture_GetWidth(bubbleTexture);
	} else {
		positionX = SCREEN_WIDTH;
	}

	int positionY = hge->Random_Int(0, SCREEN_HEIGHT - 100);
	*/

	Bubble *bubble = new Bubble(positionX, positionY, getBubbleVelocity(), bubbleSprite);
	return bubble;
}

Needle* SpriteFactory::CreateNeedle(RunningStateData* model, float mousePosX, float mousePosY)
{
	hgeVector direction(mousePosX - SCREEN_WIDTH, mousePosY - SCREEN_HEIGHT);
	direction.Normalize();
	HTEXTURE needleTexture = ResourceFactory::GetTexture(NEEDLE_TEXTURE_INDEX);
	hgeSprite* sprite = new hgeSprite(needleTexture, 0, 0, hge->Texture_GetWidth(needleTexture), hge->Texture_GetHeight(needleTexture));
	Needle* needle = new Needle(sprite, SCREEN_WIDTH, SCREEN_HEIGHT, direction, model->NeedleVelocity);
	return needle;
}