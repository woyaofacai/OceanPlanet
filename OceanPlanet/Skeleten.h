// Skeleten.h: interface for the Skeleten class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SKELETEN_H__56D49AB9_1196_440E_A9FF_F9F4E172720E__INCLUDED_)
#define AFX_SKELETEN_H__56D49AB9_1196_440E_A9FF_F9F4E172720E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Prop.h"
class Prop;

class Skeleten : public Prop
{
public:
	virtual  Explode(RunningComponent*);
	Skeleten(Bubble*);
	virtual ~Skeleten();
	virtual Update(float delta);
};

#endif // !defined(AFX_SKELETEN_H__56D49AB9_1196_440E_A9FF_F9F4E172720E__INCLUDED_)
