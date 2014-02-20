// Fish.cpp: implementation of the Fish class.
//
//////////////////////////////////////////////////////////////////////

#include "Fish.h"
#include "RunningComponent.h"

extern HGE* hge;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Fish::Fish(int kindId, hgeSprite *sprite,int score, float positionX, float positionY, hgeVector speed)
:kindId(kindId),sprite(sprite),score(score),positionX(positionX),positionY(positionY), speed(speed),hungry(true)
,lpComponent(NULL),dying(false), timeLeftToDie(0.5f),particleSprite(NULL), particleSystem(NULL),scoreAnimation(NULL)
{
	width = hge->Texture_GetWidth(sprite->GetTexture());
	height = hge->Texture_GetHeight(sprite->GetTexture());
	sprite->SetZ(0.1f);
}

Fish::MoveTo(float positionX, float positionY)
{
	
}

Fish::Draw() 
{
	if(!dying) {
		float directionAngle = speed.Angle();
		if(speed.x < 0) directionAngle += PI;
		sprite->RenderEx(positionX, positionY, directionAngle);
	} 
	else{
		float directionAngle = speed.Angle();
		if(speed.x < 0) directionAngle += PI;
		sprite->RenderEx(positionX, positionY, directionAngle);
		
	}
	if(dying && particleSystem != NULL) {
		particleSystem->Render();
	}
}

Fish::Update(float delta)
{
	if(dying) {
		timeLeftToDie -= delta;
	}else {
		if(hungry) {
			BaitCollection* baits = lpComponent->GetBaits();
			float distanceToNearestBaitSq = 0.0f;
			Bait *lpNearestBait = NULL;
			hgeVector fishCenter = this->GetCenter();
			lpNearestBait = baits->GetNearestBait(this, distanceToNearestBaitSq);
			
			if(lpNearestBait != NULL) {
				hgeVector vectorPointToNearestBait = lpNearestBait->GetCenter() - fishCenter;
				hgeVector* lpNormalizedNearestVector = vectorPointToNearestBait.Normalize();
				speed = speed + (*lpNormalizedNearestVector) * 0.01f;
				
				if(distanceToNearestBaitSq < 250.0f) {
					hungry = false;				
					lpNearestBait->Amount--;
					if(lpNearestBait->Amount <= 0) {
						baits->Remove(lpNearestBait);
						baits->Add();
					}
				}
			}
		}

		positionX += speed.x;
		positionY += speed.y;
	}

	
	if(particleSystem != NULL) {
		particleSystem->Update(delta);
	}
	
}

Fish::~Fish()
{
	delete particleSystem;
	delete particleSprite;
	delete sprite;
}

float Fish::getWidth()
{
	return width;
}

float Fish::getHeight()
{
	return height;
}

hgeVector& Fish::GetSpeed()
{
	return speed;
}

bool Fish::OutOfScreen()
{
	if(positionX < 0 - (width+1)) return true;
	if(positionX > SCREEN_WIDTH + width + 1) return true;
	if(positionY < 0 - (height + 1)) return true;
	if(positionY > SCREEN_HEIGHT + height + 1) return true;
	return false;
}


Fish::SetComponent(RunningComponent* lpComponent)
{
	this->lpComponent = lpComponent;
}

hgeVector Fish::GetCenter()
{
	hgeVector vectorPointToCenter(width/2, height/2);
	float angle = speed.Angle();
	if(speed.x < 0) angle = angle + PI;
	hgeVector *transformVector = vectorPointToCenter.Rotate(angle);
	hgeVector center = hgeVector(positionX, positionY) + (*transformVector); 

	return center;
}

hgeRect Fish::GetBoundaryRect()
{
	return hgeRect(0, 0, 0, 0);
}

bool Fish::InsideBoundaryRect(float x, float y)
{
//	return false;
	hgeVector vectToPoint(x - positionX, y - positionY);
	float angle = -speed.Angle();
	if(speed.x < 0) angle = angle - PI;
	vectToPoint.Rotate(angle);
	hgeRect r(positionX, positionY, positionX + width, positionY + height); 
	return r.TestPoint(vectToPoint.x + x, vectToPoint.y + y);
}

Fish::SetDying()
{
	dying = true;
	particleSprite = new hgeSprite(ResourceFactory::GetTexture(PARTICLE_TEXTURE_INDEX), 0, 0, 32, 32);
	particleSprite->SetBlendMode(BLEND_COLORMUL | BLEND_ALPHAADD | BLEND_NOZWRITE);
	particleSprite->SetZ(0.01f);
	particleSprite->SetHotSpot(16,16);
	
	particleSystem = new hgeParticleSystem("particles/fish1.psi", particleSprite);
	particleSystem->Fire();
	particleSystem->MoveTo(GetCenter().x, GetCenter().y);

	hge->Effect_PlayEx(ResourceFactory::GetSound(HIT_FISH_SOUND), 20);
}

float Fish::GetTimeLeftToDie()
{
	return timeLeftToDie;
}

bool Fish::GetDyingState()
{
	return dying;
}

int Fish::GetScore()
{
	return score;
}

Fish::SetScoreAnimation(ScoreAnimation* scoreAnimation)
{
	this->scoreAnimation = scoreAnimation;	
}

ScoreAnimation* Fish::GetScoreAnimation()
{
	return scoreAnimation;
}

float Fish::GetSqrtDistanceFromPoint(float x, float y)
{
	hgeVector center = GetCenter();
	return (center.x - x) * (center.x - x) + (center.y - y) * (center.y - y);
}

Fish::KilldedByBomb()
{
	dying = true;
	sprite->SetTexture(ResourceFactory::GetTexture(kindId + (BLACK_LEFTFISH_TEXTURE_INDEX - LEFTFISH_TEXTURE_INDEX)));
}

Fish::ChangeVelocity(float factor)
{
	speed *= factor;
}
