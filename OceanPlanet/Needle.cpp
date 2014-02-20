// Needle.cpp: implementation of the Needle class.
//
//////////////////////////////////////////////////////////////////////

#include "Needle.h"

#include "RunningComponent.h"

extern HGE* hge;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Needle::Needle(hgeSprite *sprite,float positionX, float positionY, hgeVector direction, float speedValue):
sprite(sprite), positionX(positionX), positionY(positionY), direction(direction),lpComponent(NULL)
{
	width = hge->Texture_GetWidth(sprite->GetTexture());
	height = hge->Texture_GetHeight(sprite->GetTexture());
	speed = direction * speedValue;
}

Needle::~Needle()
{
	
}

Needle::Update()
{
	positionX += speed.x;
	positionY += speed.y;
}

Needle::Draw()
{
	//sprite->Render(positionX, positionY);
	sprite->RenderEx(positionX, positionY, speed.Angle() + PI);
}

Needle::SetComponent(RunningComponent* lpComponent)
{
	this->lpComponent = lpComponent;
}

bool Needle::OutOfScreen()
{
	if(positionX < (width * direction.x)) return true;
	//if(positionX > SCREEN_WIDTH + width * direction.x) return true;
	//if(positionY < height * direction.y) return true;
	if(positionY > SCREEN_HEIGHT - height * direction.y) return true;
	return false;
}

bool Needle::Hit(Fish *fish)
{
	return fish->InsideBoundaryRect(positionX, positionY);
}

float Needle::GetPositionX()
{
	return positionX;
}

float Needle::GetPositionY()
{
	return positionY;
}

Needle::ChangeVelocity(float factor)
{
	speed *= factor;	
}
