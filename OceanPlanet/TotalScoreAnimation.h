// TotalScoreAnimation.h: interface for the TotalScoreAnimation class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TOTALSCOREANIMATION_H__BEAA9730_CDFD_4919_A3AF_D68737C956FA__INCLUDED_)
#define AFX_TOTALSCOREANIMATION_H__BEAA9730_CDFD_4919_A3AF_D68737C956FA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <hgefont.h>

class TotalScoreAnimation  
{
public:
	AddScore(int);
	TotalScoreAnimation(float, float);
	Update(float delta);
	Draw();
	virtual ~TotalScoreAnimation();
private:
	hgeFont* fnt;
	int score;
	int destinationScore;
	float positionX, positionY;
};

#endif // !defined(AFX_TOTALSCOREANIMATION_H__BEAA9730_CDFD_4919_A3AF_D68737C956FA__INCLUDED_)
