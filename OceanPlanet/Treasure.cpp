// Treasure.cpp: implementation of the Treasure class.
//
//////////////////////////////////////////////////////////////////////

#include "Treasure.h"
#include "RunningComponent.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Treasure::Treasure(Bubble* bubble,int score)
:Prop(bubble, TREATURE_TEXTURE_INDEX), score(score),particle(NULL),particleSprite(NULL),scoreAnimation(NULL)
{
	
}

Treasure::~Treasure()
{
	delete particle;
	delete particleSprite;
}

Treasure::Update(float delta)
{
	Prop::Update(delta);
	if(GetState() == BUBBLE_BURST_STATE)
		particle->Update(delta);
	else if(GetState() == BUBBLE_DISAPPEAR_STATE) {
		scoreAnimation->StartToMove();
	}
}

Treasure::Explode(RunningComponent* component)
{
	Prop::Explode(component);
	particleSprite = new hgeSprite(ResourceFactory::GetTexture(PARTICLE_TEXTURE_INDEX), 0, 0, 32, 32);
	particleSprite->SetBlendMode(BLEND_COLORMUL | BLEND_ALPHAADD | BLEND_NOZWRITE);
	particleSprite->SetZ(0.01f);
	particleSprite->SetHotSpot(16,16);
	
	particle = new hgeParticleSystem("particles/treasure.psi", particleSprite);
	particle->Fire();
	particle->MoveTo(bubble->positionX + width * 0.5, bubble->positionY + height * 0.5);

	scoreAnimation = new ScoreAnimation(score, bubble->GetPositionX(), bubble->GetPositionY());
	component->GetScoreAnimations().push_back(scoreAnimation);
}

Treasure::Draw()
{
	Prop::Draw();
	if(GetState() == BUBBLE_BURST_STATE)
		particle->Render();
}
