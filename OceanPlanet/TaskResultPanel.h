// TaskResultPanel.h: interface for the TaskResultPanel class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TASKRESULTPANEL_H__543A35DA_2907_47C1_9603_72CBBCE59D75__INCLUDED_)
#define AFX_TASKRESULTPANEL_H__543A35DA_2907_47C1_9603_72CBBCE59D75__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "GameComponent.h"

class TaskResultPanel  
{
public:
	TaskResultPanel(GameComponent* component);
	virtual ~TaskResultPanel();
	virtual Update(float) = 0;
	virtual Draw() = 0;
protected:
	GameComponent* component;
};

#endif // !defined(AFX_TASKRESULTPANEL_H__543A35DA_2907_47C1_9603_72CBBCE59D75__INCLUDED_)
