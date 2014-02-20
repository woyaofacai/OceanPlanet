// ScoreAnimation.cpp: implementation of the ScoreAnimation class.
//
//////////////////////////////////////////////////////////////////////

#include "ScoreAnimation.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ScoreAnimation::ScoreAnimation(int score, float positionX, float positionY)
:score(score), positionX(positionX), positionY(positionY),isMoving(false),
speed(TOTAL_SCORE_POS_X - positionX, TOTAL_SCORE_POS_Y - positionY)
{
	speed.Normalize();
	acceleration = speed;
	speed.x = speed.x * initSpeedValue;
	speed.y = speed.y * initSpeedValue;

	acceleration.x *= accelerationValue;
	acceleration.y *= accelerationValue;

	fnt = new hgeFont("font/score1.fnt");
	fnt->SetZ(0.1f);
	fnt->SetColor(ARGB(255, 255, 200, 0));

	particleSprite = new hgeSprite(ResourceFactory::GetTexture(PARTICLE_TEXTURE_INDEX), 32, 32, 32, 32);
	particleSprite->SetBlendMode(BLEND_COLORMUL | BLEND_ALPHAADD | BLEND_NOZWRITE);
	particleSprite->SetZ(0.01f);
	particleSprite->SetHotSpot(16,16);
	
	particleSystem = new hgeParticleSystem("particles/score1.psi", particleSprite);
	particleSystem->Fire();
	particleSystem->MoveTo(positionX, positionY);
}

ScoreAnimation::~ScoreAnimation()
{
	delete fnt;
	delete particleSprite;
	delete particleSystem;
}

ScoreAnimation::Update(float delta)
{
	if(isMoving) {
		positionX += speed.x;
		positionY += speed.y;
		
		speed.x += acceleration.x;
		speed.y += acceleration.y;

		particleSystem->MoveTo(positionX, positionY);
	}
	particleSystem->Update(delta);
}

ScoreAnimation::Draw()
{
	fnt->printf(positionX, positionY, HGETEXT_CENTER, "+%d", score);
	particleSystem->Render();
}

bool ScoreAnimation::ReachDestination()
{
	if(positionY > SCREEN_HEIGHT) return true;
	return false;
}


float ScoreAnimation::accelerationValue = 0.01f;
float ScoreAnimation::initSpeedValue = 10.0f;

ScoreAnimation::StartToMove()
{
	isMoving = true;
}

int ScoreAnimation::GetScore()
{
	return score;
}
