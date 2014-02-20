// TotalScoreAnimation.cpp: implementation of the TotalScoreAnimation class.
//
//////////////////////////////////////////////////////////////////////

#include "TotalScoreAnimation.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

TotalScoreAnimation::TotalScoreAnimation(float positionX, float positionY)
:score(0),destinationScore(0),positionX(positionX),positionY(positionY)
{
	fnt = new hgeFont("font/score1.fnt");
	fnt->SetZ(0.1f);
	fnt->SetColor(ARGB(255, 255, 255, 0));
}

TotalScoreAnimation::~TotalScoreAnimation()
{
	delete fnt;
}

TotalScoreAnimation::Update(float delta)
{
	if(score != destinationScore) {
		score++;
	}
}

TotalScoreAnimation::Draw()
{
	fnt->printf(positionX, positionY, HGETEXT_LEFT, "%d", score);
}


TotalScoreAnimation::AddScore(int scoreToAdd)
{
	destinationScore += scoreToAdd;
}
