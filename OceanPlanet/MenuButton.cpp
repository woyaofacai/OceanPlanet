// MenuButton.cpp: implementation of the MenuButton class.
//
//////////////////////////////////////////////////////////////////////

#include "MenuButton.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MenuButton::MenuButton():sprite(NULL), visible(true)
{

}

MenuButton::Initialize(float positionX, float positionY, HTEXTURE tex, 
		float x, float y, float w, float h, int msgId, GameComponent* component, int mouseOverMsg, int mouseOutMsg)
{
	this->texture = tex;
	this->positionX = positionX;
	this->positionY = positionY;
	this->component = component;
	this->x = x;
	this->y = y;
	this->width = w;
	this->height = h;
	this->msgId = msgId;
	this->mouseOutMsg = mouseOutMsg;
	this->mouseOverMsg = mouseOverMsg;
	sprite = new hgeSprite(tex,	x, y, width, height);
	rect.x1 = positionX;
	rect.y1 = positionY;
	rect.x2 = positionX + width;
	rect.y2 = positionY + height;
}

/*
MenuButton::Initialize(int id, float positionX, float positionY, GameComponent* component)
{
	this->id = id;
	this->positionX = positionX;
	this->positionY = positionY;
	this->component = component;
	HTEXTURE tex = ResourceFactory::GetTexture(MENUBUTTON_TEXTURE_INDEX);
	int texHeight = hge->Texture_GetHeight(tex, true);
	int texWidth = hge->Texture_GetWidth(tex, true);
	positionXInTexture = 0;
	switch (id)
	{
	case START_MENUBUTTON:
		msgId = START_MENUBUTTON_MSG;
		positionYInTexture = 0;
		break;
	case ARCADE_MENUBUTTON:
		msgId = ARCADE_MENUBUTTON_MSG;
		positionYInTexture = texHeight * 0.2f;
		break;
	case ABOUT_MENUBUTTON:
		msgId = ABOUT_MENUBUTTON_MSG;
		positionYInTexture = texHeight * 0.4f;
		break;
	case EXIT_MENUBUTTON:
		msgId = EXIT_MENUBUTTON_MSG;
		positionYInTexture = texHeight * 0.6f;
		break;
	case CONTINUE_MENUBUTTON:
		msgId = CONTINUE_MENUBUTTON_MSG;
		positionYInTexture = texHeight * 0.8f;
		break;
	}
	sprite = new hgeSprite(tex, positionXInTexture, positionYInTexture, texWidth * 0.5f, texHeight * 0.2f);
	sprite->SetBlendMode(BLEND_DEFAULT_Z);
	sprite->SetZ(0.01f);
	rect.x1 = positionX;
	rect.y1 = positionY;
	rect.x2 = positionX + texWidth * 0.5;
	rect.y2 = positionY + texHeight * 0.2f;
}
*/

MenuButton::~MenuButton()
{
	delete sprite;
}

MenuButton::MouseLButton(bool bDown)
{
	if(visible) {
		if(!bDown) {
			component->OnMessage(msgId, NULL);
		}
		else {
			sprite->SetTextureRect(x + 2 * width, y, width, height);
		}
	}
}

MenuButton::Render()
{
	if(visible)
		sprite->Render(positionX, positionY);
}

MenuButton::MouseOver()
{
	if(visible) {
		hge->Effect_Play(ResourceFactory::GetSound(MENU_BUTTON_SOUND));
		if(ResourceFactory::GetSound(MENU_BUTTON_SOUND) == 0) {
			MessageBox(NULL, hge->System_GetErrorMessage(), "Error", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		}
		sprite->SetTextureRect(x + width, y, width, height);
		if(mouseOverMsg != 0) {
			component->OnMessage(mouseOverMsg);
		}
	}
}

MenuButton::MouseOut()
{
	if(visible) {
		sprite->SetTextureRect(x, y, width, height);
		if(mouseOutMsg != 0) {
			component->OnMessage(mouseOutMsg);
		}
	}
}

bool MenuButton::GetVisible()
{
	return visible;
}

MenuButton::SetVisible(bool visible)
{
	this->visible = visible;	
}
