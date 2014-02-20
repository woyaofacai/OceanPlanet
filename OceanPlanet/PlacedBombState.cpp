// PlacedBombState.cpp: implementation of the PlacedBombState class.
//
//////////////////////////////////////////////////////////////////////

#include "PlacedBombState.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PlacedBombState::PlacedBombState(int leftTime):leftTime(leftTime),timeSinceLastUpdateLeftTime(0.0f)
{
	fnt = new hgeFont("font/bomb1.fnt");
	fnt->SetColor(ARGB(255, 255, 0, 0));
}

PlacedBombState::~PlacedBombState()
{
	delete fnt;
}


PlacedBombState::Draw(Bomb* bomb)
{
	bomb->bombSprite->Render(bomb->positionX, bomb->positionY);
	fnt->printf(bomb->positionX + (bomb->width >> 1), bomb->positionY + (bomb->height >> 1), HGETEXT_CENTER, "%d", leftTime);
}

PlacedBombState::Update(Bomb* bomb, float delta)
{
	timeSinceLastUpdateLeftTime+= delta;
	if(timeSinceLastUpdateLeftTime > 0.15f) {
		timeSinceLastUpdateLeftTime = 0;
		if(leftTime > 0)
			leftTime--;
		else {
			bomb->ChangeState(new ExplodeBombState);
		}
	}
}

PlacedBombState::Enter(Bomb* bomb)
{
	hge->Effect_Play(ResourceFactory::GetSound(PUT_BOMB_SOUND));
}

PlacedBombState::Leave(Bomb* bomb)
{

}


