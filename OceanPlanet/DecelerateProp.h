// DecelerateProp.h: interface for the DecelerateProp class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DECELERATEPROP_H__D28CD747_350A_4AC0_9F2B_3AFE23923961__INCLUDED_)
#define AFX_DECELERATEPROP_H__D28CD747_350A_4AC0_9F2B_3AFE23923961__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Prop.h"

class DecelerateProp : public Prop
{
public:
	DecelerateProp(Bubble*);
	virtual ~DecelerateProp();
	virtual Update(float);
	virtual Explode(RunningComponent*);
};

#endif // !defined(AFX_DECELERATEPROP_H__D28CD747_350A_4AC0_9F2B_3AFE23923961__INCLUDED_)
