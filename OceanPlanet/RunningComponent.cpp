// RunningComponent.cpp: implementation of the RunningComponent class.
//
//////////////////////////////////////////////////////////////////////

#include "RunningComponent.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

RunningComponent::RunningComponent()
:timeSinceLastMoveSprite(0),currentWeaponType(NEEDLE_WEAPON_TYPE),taskResultPanel(NULL)
,fishes(NULL), model(NULL), needles(NULL), bombs(NULL), props(NULL), baits(NULL),controlPanel(NULL),
currentBomb(NULL),spriteProduceStrategy(NULL)
{
	HTEXTURE backgroundTexture = hge->Texture_Load("images/background/sea.png");
	if(backgroundTexture) {
		lpSeaBackGround = new SeaBackGround(backgroundTexture);
	}
}

RunningComponent::~RunningComponent()
{
	this->Leave();
	delete lpSeaBackGround;
}

RunningComponent::Enter()
{
	delete taskResultPanel;
	delete controlPanel;
	taskResultPanel = NULL;
	controlPanel = new ControlPanel(this);
	currentBomb = new Bomb(0, 0, this);
	spriteProduceStrategy = new RunningSpriteProduceStrategy(this);
	
	fishes = new FishCollection(this);
	baits = new BaitCollection(this);
	needles = new NeedleCollection(this);
	bombs = new BombCollection(this);
	props = new PropCollection(this);
	baits->Initialize();
	backgroundMusicChanel = hge->Effect_PlayEx(ResourceFactory::GetSound(RUNNING_GAME_SOUND), 100, 0, 0, true);
}

RunningComponent::Leave()
{
	list<ScoreAnimation *>::iterator sit;
	while(!scoreAnimations.empty()) {
		sit = scoreAnimations.begin();
		scoreAnimations.erase(sit);
	}
	
	delete model;
	delete fishes;
	delete baits;
	delete bombs;
	delete props;
	delete spriteProduceStrategy;
	delete currentBomb;

	hge->Channel_Stop(backgroundMusicChanel);
}

RunningComponent::SetGameModel(RunningStateData* model)
{
	this->model = model;
}

RunningComponent::Update(float delta)
{
	spriteProduceStrategy->AddFish(delta);
	spriteProduceStrategy->AddProp(delta);

	timeSinceLastMoveSprite += delta;
	if(timeSinceLastMoveSprite > 0.01f) {
		timeSinceLastMoveSprite = 0;

		fishes->Update(delta);
		needles->Update(delta);
		bombs->Update(delta);
		props->Update(delta);

		lpSeaBackGround->Update(delta);	

		list<ScoreAnimation *>::iterator sit = scoreAnimations.begin();
		for(; sit != scoreAnimations.end(); sit++)
		{
			if((*sit)->ReachDestination()) {
				list<ScoreAnimation *>::iterator sit2 = sit;
				ScoreAnimation* scoreAnimation = *sit2;
				sit--;
				scoreAnimations.erase(sit2);
				controlPanel->AddScore(scoreAnimation->GetScore());
				delete scoreAnimation;
			}
			else {
				(*sit)->Update(delta);
			}
		}
	}

	if(model->CurrentState == FIGHT_STATE && (model->BombCount > 0 || model->NeedleCount > 0)) {
		updateCurrentWeapon(delta);
	}
	if (model->CurrentState == TASKFAIL_STATE || model->CurrentState == TASKPASS_STATE || model->CurrentState == ARCADEOVER_STATE) {
		taskResultPanel->Update(delta);
	}

	controlPanel->Update(delta);
}

RunningComponent::Draw()
{
	lpSeaBackGround->Draw();
	
	fishes->Draw();
	needles->Draw();
	props->Draw();
	bombs->Draw();
	controlPanel->Draw();

	list<ScoreAnimation *>::iterator sit = scoreAnimations.begin();
	for(; sit != scoreAnimations.end(); sit++)
	{
		(*sit)->Draw();
	}
	
	if(model->CurrentWeaponType == BOMB_WEAPON_TYPE && model->CurrentState == FIGHT_STATE)
		currentBomb->Draw();

	if(model->CurrentState == TASKFAIL_STATE
		|| model->CurrentState == TASKPASS_STATE 
		|| model->CurrentState == ARCADEOVER_STATE)
		taskResultPanel->Draw();
	
}

BaitCollection* RunningComponent::GetBaits()
{
	return baits;
}

FishCollection* RunningComponent::GetFishes()
{
	return fishes;
}

//DEL GameComponent* RunningComponent::GetInstance()
//DEL {
//DEL 	if(lpInstance == NULL) {
//DEL 		lpInstance = new RunningComponent();
//DEL 	}
//DEL 	return lpInstance;
//DEL }

GameComponent* RunningComponent::lpInstance = NULL;

RunningComponent::OnMessage(int messageType, void* lpinfo)
{
	Bomb* bomb = NULL;
	switch(messageType) 
	{
	case BOMB_EXPLODE_MSG:
		bomb = (Bomb*)lpinfo;
		fishes->ExplodeFishesNearBomb(bomb);
		props->ExplodeFishesNearBomb(bomb);
		break;
	case BOMB_PLACED_MSG:
		bomb = (Bomb*)lpinfo;
		bombs->Add(bomb);
		currentBomb = new Bomb(0, 0, this);
		model->BombCount--;
		if(model->BombCount <= 0) model->CurrentWeaponType = NEEDLE_WEAPON_TYPE;
		break;
	case TASKFAIL_MSG:
		model->CurrentState = TASKFAIL_STATE;
		taskResultPanel = new TaskFailPanel(this);
		break;
	case RESTART_BARRIER_MSG: {
		CutsceneComponent::GetInstance()->Initialize(model->Barrier);
		Game::GetInstance()->SetComponent(CutsceneComponent::GetInstance());
		break;
	}
	case RETURN_MAINMENU_MSG:
		Game::GetInstance()->SetComponent(WelcomeComponent::GetInstance());
		break;
	case CHANGE_WEAPON_MSG:
		changeWeapon();
		break;
	case MOUSEOVER_CHANGEWEAPON_MSG:
		model->CurrentState = OPERATION_STATE;
		break;
	case MOUSEOUT_CHANGEWEAPON_MSG:
		model->CurrentState = FIGHT_STATE;
		break;
	case TASKPASS_MSG:
		model->CurrentState = TASKPASS_STATE;
		taskResultPanel = new TaskPassPanel(this);
		break;
	case NEXT_BARRIER_MSG:
		if(model->Barrier == TOTAL_BARRIER_COUNT) {
			Game::GetInstance()->SetComponent(FinalWinComponent::GetInstance());
		}
		else {
			CutsceneComponent::GetInstance()->Initialize(model->Barrier + 1);
			Game::GetInstance()->SetComponent(CutsceneComponent::GetInstance());
		}
		break;
	case ARCADE_OVER_MSG:
		model->CurrentState = ARCADEOVER_STATE;
		taskResultPanel = new ArcadeOverPanel(this, model->CurrentScore);
		break;
	case RESTART_ARCADE_MSG:
		Game::GetInstance()->SetComponent(RunningComponent::GetInstance());
		RunningComponent::GetInstance()->SetGameModel(new RunningStateData(runningModels[0]));
		break;
	default:
		break;
	}
}

RunningComponent::updateCurrentWeapon(float delta)
{
	static float pressMouseTime = 0.0f;
	static bool mousePressed = false;
	switch(model->CurrentWeaponType) {
	case NEEDLE_WEAPON_TYPE:
		if(hge->Input_KeyDown(HGEK_LBUTTON)) {
			mousePressed = true;
		}
		
		if(hge->Input_KeyUp(HGEK_LBUTTON)) {
			float mousePosX, mousePosY;
			hge->Input_GetMousePos(&mousePosX, &mousePosY);
			Needle* needle = SpriteFactory::GetInstance()->CreateNeedle(model, mousePosX, mousePosY);
			needle->SetComponent(this);
			needles->Add(needle);
			pressMouseTime = 0.0f;
			mousePressed = false;
			model->NeedleCount--;
			hge->Effect_PlayEx(ResourceFactory::GetSound(PUT_NEEDLE_SOUND), 50);
			if(model->NeedleCount <= 0) {
				model->CurrentWeaponType = BOMB_WEAPON_TYPE;
			}
		}
		break;
	case BOMB_WEAPON_TYPE:
		currentBomb->Update(delta);
		break;
	default:
		break;
	}

	if(hge->Input_KeyUp(HGEK_RBUTTON)) changeWeapon();
}

list<ScoreAnimation*>& RunningComponent::GetScoreAnimations()
{
	return scoreAnimations;
}

RunningStateData* RunningComponent::GetModel()
{
	return model;
}

NeedleCollection* RunningComponent::GetNeedles()
{
	return needles;
}

//DEL RunningComponent::SetTaskFailPanel(TaskFailPanel* taskFailPanel)
//DEL {
//DEL 	this->taskFailPanel = taskFailPanel;
//DEL }

RunningComponent::changeWeapon()
{
	if(model->CurrentWeaponType == NEEDLE_WEAPON_TYPE 
		&& model->BombCount > 0 && (model->AllowWeaponType & BOMB_WEAPON_TYPE)) {
		model->CurrentWeaponType = BOMB_WEAPON_TYPE;
	} 
	else if(model->CurrentWeaponType == BOMB_WEAPON_TYPE 
		&& model->NeedleCount > 0 && (model->AllowWeaponType & NEEDLE_WEAPON_TYPE)){
		model->CurrentWeaponType = NEEDLE_WEAPON_TYPE;
	}
}

bool RunningComponent::MeetWinCondition()
{
	return (!model->ArcadeMode) && model->CurrentScore >= model->GoalScore;
}

RunningComponent* RunningComponent::GetInstance()
{
	static RunningComponent cp;
	return &cp;
}

bool RunningComponent::WeaponUsedUp()
{
	return model->NeedleCount <= 0 && model->BombCount <= 0;
}
