// FishFactory.cpp: implementation of the FishFactory class.
//
//////////////////////////////////////////////////////////////////////

#include "FishFactory.h"
#include "constants.h"

extern HGE* hge;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

FishFactory::FishFactory()
{
	
}

FishFactory::~FishFactory()
{
	
}

Fish *FishFactory::GetFish()
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
		speedVector = getSpeedVector(true);
	}
	else {
		kindId = RIGHTFISH_TEXTURE_INDEX + kind;
		fishTexture = ResourceFactory::GetTexture(kindId);
		sprite = new hgeSprite(fishTexture, 0, 0, hge->Texture_GetWidth(fishTexture), hge->Texture_GetHeight(fishTexture));
		sprite->SetZ(FISH_Z);
		positionX = SCREEN_WIDTH + hge->Texture_GetWidth(fishTexture);
		speedVector = getSpeedVector(false);
	}
	sprite->SetZ(FISH_Z);
	positionY = hge->Random_Int(150, SCREEN_HEIGHT - 150);
	Fish *fish = new Fish(kindId, sprite, 10, positionX, positionY, speedVector);
	return fish;

}


hgeVector FishFactory::getSpeedVector(bool left)
{
	float speed_y = hge->Random_Float(-0.5f, 0.5f);
	float speed_x = hge->Random_Float(0.5f, 1.5f);
	if(!left) {
		speed_x = -speed_x;
	}
	return hgeVector(speed_x, speed_y);
}

