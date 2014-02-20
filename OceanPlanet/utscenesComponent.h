// utscenesComponent.h: interface for the CutscenesComponent class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UTSCENESCOMPONENT_H__F5A56A34_4AA7_4123_947A_850549CDA27A__INCLUDED_)
#define AFX_UTSCENESCOMPONENT_H__F5A56A34_4AA7_4123_947A_850549CDA27A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "GameComponent.h"
#include <hgesprite.h>
#include "ResourceFactory.h"

class CutscenesComponent : public GameComponent  
{
public:
	CutscenesComponent(int);
	virtual ~CutscenesComponent();
	virtual Update(float delta);
	virtual Draw();
private:
	int barrier;
	hgeSprite* backgroundSprite;
};

#endif // !defined(AFX_UTSCENESCOMPONENT_H__F5A56A34_4AA7_4123_947A_850549CDA27A__INCLUDED_)
