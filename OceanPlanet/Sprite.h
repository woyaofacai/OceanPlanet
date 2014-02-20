// Sprite.h: interface for the Sprite class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SPRITE_H__E909ABED_D6AE_4A95_A1E1_DE9BEDEFEDE2__INCLUDED_)
#define AFX_SPRITE_H__E909ABED_D6AE_4A95_A1E1_DE9BEDEFEDE2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <hge.h>
#include <hgesprite.h>

class Sprite  
{
public:
	Sprite();
	virtual ~Sprite();
protected:
	float positionX, positionY, width, height;
	hgeSprite* sprite;
};

#endif // !defined(AFX_SPRITE_H__E909ABED_D6AE_4A95_A1E1_DE9BEDEFEDE2__INCLUDED_)
