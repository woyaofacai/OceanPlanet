// TaskPassPanel.h: interface for the TaskPassPanel class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TASKPASSPANEL_H__39A8460B_97F3_4B20_A971_3CF9D10C8E6C__INCLUDED_)
#define AFX_TASKPASSPANEL_H__39A8460B_97F3_4B20_A971_3CF9D10C8E6C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <hgesprite.h>
#include "ResourceFactory.h"
#include "TaskResultPanel.h"

class TaskPassPanel : public TaskResultPanel
{
public:
	TaskPassPanel(GameComponent*);
	virtual ~TaskPassPanel();
	virtual Update(float);
	virtual Draw();
private:
	hgeSprite* fntSprite;
	float timeSinceShowPanel;
};

#endif // !defined(AFX_TASKPASSPANEL_H__39A8460B_97F3_4B20_A971_3CF9D10C8E6C__INCLUDED_)
