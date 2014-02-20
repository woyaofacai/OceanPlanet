// utscenesComponent.cpp: implementation of the CutscenesComponent class.
//
//////////////////////////////////////////////////////////////////////

#include "utscenesComponent.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CutscenesComponent::CutscenesComponent(int barrier):barrier(barrier)
{
	HTEXTURE tex = ResourceFactory::GetTexture(CUTSCENES_BASE_TEXTURE_INDEX + barrier - 1);
	backgroundSprite = new hgeSprite(tex, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
}

CutscenesComponent::~CutscenesComponent()
{
	delete backgroundSprite;
}

CutscenesComponent::Update(float delta)
{
	
}

CutscenesComponent::Draw()
{
	backgroundSprite->Render(0, 0);
}
