// TaskFailPanel.h: interface for the TaskFailPanel class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TASKFAILPANEL_H__3CDC291A_E21B_43B8_8202_8BB6B85A8472__INCLUDED_)
#define AFX_TASKFAILPANEL_H__3CDC291A_E21B_43B8_8202_8BB6B85A8472__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <hgesprite.h>
#include "ResourceFactory.h"
#include "Game.h"
#include "MenuButton.h"
#include "TaskResultPanel.h"

class TaskFailPanel : public TaskResultPanel
{
public:
	TaskFailPanel(GameComponent*);
	virtual ~TaskFailPanel();
	virtual Update(float);
	virtual Draw();
private:
	hgeSprite* fntSprite;
	MenuButton buttons[2];
};

#endif // !defined(AFX_TASKFAILPANEL_H__3CDC291A_E21B_43B8_8202_8BB6B85A8472__INCLUDED_)
