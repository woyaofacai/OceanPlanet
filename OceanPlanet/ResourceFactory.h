// ResourceFactory.h: interface for the ResourceFactory class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RESOURCEFACTORY_H__11C3A3D8_489B_4E3F_BAFF_A83E7AB21D0F__INCLUDED_)
#define AFX_RESOURCEFACTORY_H__11C3A3D8_489B_4E3F_BAFF_A83E7AB21D0F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <hge.h>
#include "constants.h"

extern HGE* hge;

class ResourceFactory  
{
public:
	ResourceFactory();
	virtual ~ResourceFactory();
	static HTEXTURE GetTexture(int index);
	static HEFFECT GetSound(int index);
	static LoadResources();
	static HTEXTURE GetWeaponTexture(int, bool);
private:
	static  loadBlackFishTextures();
	static HTEXTURE textures[150];
	static HEFFECT sounds[30];
};

#endif // !defined(AFX_RESOURCEFACTORY_H__11C3A3D8_489B_4E3F_BAFF_A83E7AB21D0F__INCLUDED_)
