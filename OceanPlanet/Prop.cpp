// Prop.cpp: implementation of the Prop class.
//
//////////////////////////////////////////////////////////////////////

#include "Prop.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Prop::Prop(Bubble* bubble, int texIndex):bubble(bubble),sprite(NULL)
{
	HTEXTURE tex = ResourceFactory::GetTexture(texIndex);
	width = hge->Texture_GetWidth(tex, true);
	height = hge->Texture_GetHeight(tex, true);
	sprite = new hgeSprite(tex, 0, 0, width, height);
}

Prop::~Prop()
{
	delete sprite;
	delete bubble;
}

Prop::Draw()
{
	bubble->Draw();
	float x = bubble->positionX + (bubble->width - width) * 0.5f;
	float y = bubble->positionY + (bubble->height - height) * 0.5f;
	sprite->Render(x, y);
}

Prop::Update(float delta)
{
	bubble->Update(delta);
}

bool Prop::OutOfScreen()
{
	return bubble->OutOfScreen();
}

bool Prop::HitByNeedle(Needle* needle)
{
	return bubble->InsidePoint(needle->GetPositionX(), needle->GetPositionY());
}

Prop::Explode(RunningComponent* component)
{
	bubble->Explode();
}

int Prop::GetState()
{
	return bubble->state;
}

Prop::SetState(int state)
{
	bubble->state = state;
}

float Prop::GetSqrtDistanceFromPoint(float x, float y)
{
	hgeVector& center = bubble->GetCenter();
	return (center.x - x) * (center.x - x) + (center.y - y) * (center.y - y);
}
