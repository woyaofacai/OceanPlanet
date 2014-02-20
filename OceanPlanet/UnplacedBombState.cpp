#include "UnplacedBombState.h"

UnplacedBombState::UnplacedBombState()
{

}

UnplacedBombState::~UnplacedBombState()
{
	
}

UnplacedBombState::Draw(Bomb* bomb)
{
	bomb->bombSprite->Render(bomb->positionX, bomb->positionY);
}

UnplacedBombState::Update(Bomb* bomb, float delta)
{
	
	float x, y;
	hge->Input_GetMousePos(&x, &y);
	bomb->positionX = x - (bomb->width >> 1);
	bomb->positionY = y - (bomb->height >> 1);
	
	if(hge->Input_KeyUp(HGEK_LBUTTON)) {
		this->SendMessage(BOMB_PLACED_MSG, bomb);
		bomb->ChangeState(new PlacedBombState(bomb->lpComponent->GetModel()->BombCountDown));
	}
	
}

UnplacedBombState::Enter(Bomb* bomb)
{
	bomb->bombSprite->SetTexture(Bomb::GetUnplacedTexture());
}

UnplacedBombState::Leave(Bomb* bomb)
{
	bomb->bombSprite->SetTexture(ResourceFactory::GetTexture(BOMB_TEXTURE_INDEX));
}

UnplacedBombState::SendMessage(int messageType, Bomb *bomb)
{
	bomb->OnMessage(messageType);
}
