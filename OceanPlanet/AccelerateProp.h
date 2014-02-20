// AccelerateProp.h: interface for the AccelerateProp class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ACCELERATEPROP_H__4C407488_DBA9_4DB6_B5F6_DEFC942E32A2__INCLUDED_)
#define AFX_ACCELERATEPROP_H__4C407488_DBA9_4DB6_B5F6_DEFC942E32A2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Prop.h"

class AccelerateProp : public Prop  
{
public:
	virtual  Explode(RunningComponent*);
	AccelerateProp(Bubble*);
	virtual ~AccelerateProp();
	virtual Update(float);
};

#endif // !defined(AFX_ACCELERATEPROP_H__4C407488_DBA9_4DB6_B5F6_DEFC942E32A2__INCLUDED_)
