// Bubble.cpp: implementation of the Bubble class.
//
//////////////////////////////////////////////////////////////////////

#include "Bubble.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Bubble::Bubble(float positionX, float positionY, hgeVector velocity, hgeSprite* sprite)
:positionX(positionX), positionY(positionY),velocity(velocity),sprite(sprite)
,state(BUBBLE_MOVE_STATE),burstParticleSprite(NULL),burstParticle(NULL),timeSinceBurst(0.0f)
{
	HTEXTURE tex = sprite->GetTexture();
	width = hge->Texture_GetWidth(tex, true);
	height = hge->Texture_GetHeight(tex, true);
}

Bubble::~Bubble()
{
	delete sprite;
	delete burstParticleSprite;
	delete burstParticle;
}

Bubble::Update(float delta)
{
	if(state == BUBBLE_MOVE_STATE) {
		positionX += velocity.x;
		positionY += velocity.y;
	}
	else if(state == BUBBLE_BURST_STATE) {
		timeSinceBurst += delta;
		burstParticle->Update(delta);
		if(timeSinceBurst > 1.0f) {
			state = BUBBLE_DISAPPEAR_STATE;
		}
	}
}

Bubble::Draw()
{
	if(state == BUBBLE_MOVE_STATE) {
		sprite->Render(positionX, positionY);
	}
	else if(state == BUBBLE_BURST_STATE) {
		burstParticle->Render();
	}
}

float Bubble::GetWidth()
{
	return width;
}

float Bubble::GetHeight()
{
	return height;
}

bool Bubble::OutOfScreen()
{
	return positionX + width < 0 || positionX > SCREEN_WIDTH || positionY + height < 0;
}

bool Bubble::InsidePoint(float x, float y)
{
	float radiusSq = (width * width + height * height) * 0.25f;
	float centerX = positionX + width * 0.5f;
	float centerY = positionY + height * 0.5f;
	float distanceSq = (centerX - x) * (centerX - x) + (centerY - y) * (centerY - y);
	return distanceSq < radiusSq;
}

Bubble::Explode()
{
	state = BUBBLE_BURST_STATE;
	burstParticleSprite = new hgeSprite(ResourceFactory::GetTexture(PARTICLE_TEXTURE_INDEX), 32, 32, 32, 32);
	burstParticleSprite->SetBlendMode(BLEND_COLORMUL | BLEND_ALPHAADD | BLEND_NOZWRITE);
	burstParticleSprite->SetZ(0.01f);
	burstParticleSprite->SetHotSpot(16,16);
	
	burstParticle = new hgeParticleSystem("particles/bubble.psi", burstParticleSprite);
	burstParticle->Fire();
	burstParticle->MoveTo(positionX + width * 0.5, positionY + height * 0.5);
}




float Bubble::GetPositionX()
{
	return positionX;
}

float Bubble::GetPositionY()
{
	return positionY;
}

hgeVector Bubble::GetCenter()
{
	float centerX = positionX + width * 0.5f;
	float centerY = positionY + height * 0.5f;
	return hgeVector(centerX, centerY);
}
