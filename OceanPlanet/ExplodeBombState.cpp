// ExplodeBombState.cpp: implementation of the ExplodeBombState class.
//
//////////////////////////////////////////////////////////////////////

#include "ExplodeBombState.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ExplodeBombState::ExplodeBombState():powTextureScale(1.0f)
{
	particleSprite = new hgeSprite(ResourceFactory::GetTexture(PARTICLE_TEXTURE_INDEX), 32, 64, 32, 32);
	bombParticle = new hgeParticleSystem("particles/bomb.psi", particleSprite);
	HTEXTURE powTexture = ResourceFactory::GetTexture(POW_TEXTURE_INDEX);
	powTextureWidth = hge->Texture_GetWidth(powTexture, true);
	powTextureHeight = hge->Texture_GetHeight(powTexture, true);
	powSprite = new hgeSprite(powTexture, 0, 0, powTextureWidth, powTextureHeight);
}

ExplodeBombState::~ExplodeBombState()
{
	delete particleSprite;
	delete bombParticle;
	delete powSprite;
}

ExplodeBombState::Draw(Bomb* bomb)
{
	bombParticle->Render();
	powSprite->RenderEx(bomb->GetCenterX() - (powTextureWidth >> 1) * powTextureScale , bomb->GetCenterY() - (powTextureHeight >> 1) * powTextureScale, 0, powTextureScale, powTextureScale);
	//powSprite->Render(bomb->GetCenterX() - (powTextureWidth >> 1) , bomb->GetCenterY() - (powTextureHeight >> 1));
	//powSprite->Render();

}

ExplodeBombState::Update(Bomb* bomb, float delta)
{
	//static float bombTime = 0.0f;
	if(powTextureScale > 2.0f) {
		bomb->valid = false;
		this->SendMessage(BOMB_EXPLODE_MSG, bomb);
	}
	else 
		powTextureScale += delta * 10.0f;
	//bombParticle->Update(delta);

}

ExplodeBombState::Enter(Bomb* bomb)
{
	//bombParticle->
	bombParticle->MoveTo(bomb->positionX, bomb->positionY);
	bombParticle->Fire();
	hge->Effect_Play(ResourceFactory::GetSound(BOMB_EXPLODE_SOUND));
}

ExplodeBombState::Leave(Bomb* bomb)
{
	
}

ExplodeBombState::SendMessage(int messageType, Bomb* bomb)
{
	bomb->OnMessage(messageType);
}