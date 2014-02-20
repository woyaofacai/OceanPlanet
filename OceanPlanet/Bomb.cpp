// Bomb.cpp: implementation of the Bomb class.
//
//////////////////////////////////////////////////////////////////////

#include "Bomb.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Bomb::Bomb(float positionX, float positionY, RunningComponent* lpComponent):positionX(positionX), positionY(positionY),
lpComponent(lpComponent), valid(true)
{
	HTEXTURE bombTex = Bomb::GetUnplacedTexture();
	width = hge->Texture_GetWidth(bombTex, true);
	height = hge->Texture_GetHeight(bombTex, true);
	bombSprite = new hgeSprite(bombTex, 0, 0, width, height);
	currentState = new UnplacedBombState;
}

HTEXTURE Bomb::unplacedTexture = 0;

Bomb::~Bomb()
{
	delete bombSprite;
}

Bomb::Update(float delta)
{
	currentState->Update(this, delta);
}

Bomb::Draw()
{
	currentState->Draw(this);
}

Bomb::ChangeState(BombState* newState)
{
	currentState->Leave(this);
	delete currentState;
	currentState = newState;
	currentState->Enter(this);
}

HTEXTURE Bomb::GetUnplacedTexture()
{
	if(unplacedTexture == 0) {
		unplacedTexture = ResourceFactory::GetTexture(UNPLACED_BOMB_TEXTURE_INDEX);
		DWORD* buffer = hge->Texture_Lock(unplacedTexture);
		int width = hge->Texture_GetWidth(unplacedTexture);
		int height = hge->Texture_GetHeight(unplacedTexture);
		int i;
		for (i = 0; i < width * height; i++)
		{
			buffer[i] &= 0x80FFFFFF;
		}
		hge->Texture_Unlock(unplacedTexture);
	}
	return unplacedTexture;
}

float Bomb::GetCenterX()
{
	return positionX + (width >> 1);
}

float Bomb::GetCenterY()
{
	return positionY + (height >> 1);
}

bool Bomb::OnMessage(int messageType)
{
	lpComponent->OnMessage(messageType, this);
	return true;
}

bool Bomb::IsValid()
{
	return valid;
}
