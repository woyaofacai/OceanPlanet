// Prop.h: interface for the Prop class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PROP_H__5FCEDBCC_8DCC_47FE_A5CB_90EDF161C7CA__INCLUDED_)
#define AFX_PROP_H__5FCEDBCC_8DCC_47FE_A5CB_90EDF161C7CA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Bubble.h"
#include "Needle.h"
//#include "RunningComponent.h"

class RunningComponent;

class Prop  
{
public:
	float GetSqrtDistanceFromPoint(float, float);
	int GetState();
	virtual  Explode(RunningComponent*);
	Prop(Bubble*, int);
	virtual ~Prop();
	virtual Update(float delta);
	virtual Draw();
	bool OutOfScreen();
	bool Prop::HitByNeedle(Needle* needle);
protected:
	SetState(int);
	Bubble* bubble;
	hgeSprite* sprite;
	float width;
	float height;
	RunningComponent* component;
private:

};

#endif // !defined(AFX_PROP_H__5FCEDBCC_8DCC_47FE_A5CB_90EDF161C7CA__INCLUDED_)
