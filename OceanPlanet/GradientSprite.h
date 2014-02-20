// GradientSprite.h: interface for the GradientSprite class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GRADIENTSPRITE_H__916ADB21_31BC_48ED_9170_E889F934F2D8__INCLUDED_)
#define AFX_GRADIENTSPRITE_H__916ADB21_31BC_48ED_9170_E889F934F2D8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <hge.h>
#include <hgesprite.h>

extern HGE* hge;

class GradientSprite  
{
public:
	GradientSprite(HTEXTURE, float, float, float, float);
	virtual ~GradientSprite();
private:
	hgeSprite* sprite;
	HTEXTURE sourceTexture;
	HTEXTURE gradientTexture;
};

#endif // !defined(AFX_GRADIENTSPRITE_H__916ADB21_31BC_48ED_9170_E889F934F2D8__INCLUDED_)
