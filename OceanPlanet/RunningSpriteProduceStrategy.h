// RunningSpriteProduceStrategy.h: interface for the RunningSpriteProduceStrategy class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RUNNINGSPRITEPRODUCESTRATEGY_H__88A0F151_F18A_4F58_9954_1C509399C8E1__INCLUDED_)
#define AFX_RUNNINGSPRITEPRODUCESTRATEGY_H__88A0F151_F18A_4F58_9954_1C509399C8E1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SpriteProduceStrategy.h"
#include "SpriteFactory.h"
#include "RunningComponent.h"

//class RunningComponent;

class RunningSpriteProduceStrategy : public SpriteProduceStrategy  
{
public:
	RunningSpriteProduceStrategy(RunningComponent*);
	virtual AddProp(float);
	virtual AddFish(float);
	virtual ~RunningSpriteProduceStrategy();
private:
	RunningComponent* component;

};

#endif // !defined(AFX_RUNNINGSPRITEPRODUCESTRATEGY_H__88A0F151_F18A_4F58_9954_1C509399C8E1__INCLUDED_)
