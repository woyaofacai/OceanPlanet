// RunningComponent.h: interface for the RunningComponent class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RUNNINGCOMPONENT_H__0EAB352E_55F3_4B03_9C44_09B28355BB09__INCLUDED_)
#define AFX_RUNNINGCOMPONENT_H__0EAB352E_55F3_4B03_9C44_09B28355BB09__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "GameComponent.h"
#include <hgesprite.h>
#include <hgedistort.h>
#include <hgefont.h>
#include <list>
#include <cstdlib>
#include <ctime>
#include "constants.h"
#include "Fish.h"
#include "Needle.h"
#include "Bomb.h"
#include "Bait.h"
#include "FishFactory.h"
#include "SeaBackGround.h"
#include "ResourceFactory.h"
#include "ScoreAnimation.h"
#include "TotalScoreAnimation.h"
#include "ControlPanel.h"
#include "RunningStateData.h"
#include "SpriteFactory.h"
#include "SpriteProduceStrategy.h"
#include "RunningSpriteProduceStrategy.h"
#include "HarvestSpriteProduceStrategy.h"
#include "FishCollection.h"
#include "BaitCollection.h"
#include "NeedleCollection.h"
#include "BombCollection.h"
#include "PropCollection.h"
#include "TaskFailPanel.h"
#include "TaskPassPanel.h"
#include "WelcomeComponent.h"
#include "CutsceneComponent.h"
#include "FinalWinComponent.h"
#include "ArcadeOverPanel.h"

using namespace std;

class FishCollection;
class BaitCollection;
class NeedleCollection;
class BombCollection;
class PropCollection;
class Prop;
class TaskFailPanel;
class FinalWinComponent;

extern HGE* hge;
extern RunningStateData runningModels[];

class RunningComponent : public GameComponent  
{
friend class RunningSpriteProduceStrategy;
friend class HarvestSpriteProduceStrategy;
friend class BaitCollection;
friend class Fish;
friend class FishCollection;
friend class NeedleCollection;
friend class HarvestProp;

private:
	RunningComponent();
	SpriteProduceStrategy* spriteProduceStrategy;
	updateCurrentWeapon(float delta);
	FishCollection* fishes;
	BaitCollection* baits;
	NeedleCollection* needles;
	BombCollection* bombs;
	PropCollection* props;
	list<ScoreAnimation *> scoreAnimations;
	SeaBackGround *lpSeaBackGround;
	float timeSinceLastMoveSprite;
	hgeFont* fnt;
	static GameComponent* lpInstance;
	ControlPanel* controlPanel;
	Bomb* currentBomb;
	int currentWeaponType;
	RunningStateData* model;
	changeWeapon();
	HCHANNEL backgroundMusicChanel;
public:
	bool WeaponUsedUp();
	static RunningComponent* GetInstance();
	virtual Enter();
	virtual Leave();
	RunningStateData* GetModel();
	virtual Update(float);
	virtual Draw();
	BaitCollection* GetBaits();
	FishCollection* GetFishes();
	virtual ~RunningComponent();
	OnMessage(int, void* lpinfo = NULL);
	SetGameModel(RunningStateData*);
	list<ScoreAnimation*>& GetScoreAnimations();
	NeedleCollection* GetNeedles();
	TaskResultPanel* taskResultPanel;
	bool MeetWinCondition();
};

#endif // !defined(AFX_RUNNINGCOMPONENT_H__0EAB352E_55F3_4B03_9C44_09B28355BB09__INCLUDED_)
