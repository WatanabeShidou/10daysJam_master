#include "StageSelect.h"

void StageSelect::Initialize()
{
	isGameStart_ = false;

	// テクスチャロード
	BG_ = Novice::LoadTexture("./Resource/images/BG.png");

	stage1_ = Novice::LoadTexture("./Resource/images/stage1.png");
	stage2_ = Novice::LoadTexture("./Resource/images/stage2.png");
	stage3_ = Novice::LoadTexture("./Resource/images/stage3.png");
	tutorial_ = Novice::LoadTexture("./Resource/images/tutorial.png");

	selectStage1_ = Novice::LoadTexture("./Resource/images/selectStage1.png");
	selectStage2_ = Novice::LoadTexture("./Resource/images/selectStage2.png");
	selectStage3_ = Novice::LoadTexture("./Resource/images/selectStage3.png");
	selectTutorial_ = Novice::LoadTexture("./Resource/images/selectTutorial.png");

	gameClear_ = new GameClear;
	gameClear_->Initialize();
}

void StageSelect::Update()
{
	Novice::GetMousePosition(&mousePosX_, &mousePosY_);

	// チュートリアルを選択する処理
	if (mousePosX_ >= selectTutorialX_ && mousePosX_ <= selectTutorialX_ + selectTW_ && mousePosY_ >= selectTutorialY_ && mousePosY_ <= selectTutorialY_ + selectTH_)
	{
		selectTutorialColor_ = RED;
		if (selectTutorialColor_ = RED && Novice::IsPressMouse(0))
		{
			stageNo_ = 0;
			isGameStart_ = true;
		}
	}
	else
	{
		selectTutorialColor_ = WHITE;
	}

	// ステージ１を選択する処理
	if (mousePosX_ >= selectST1X_ && mousePosX_ <= selectST1X_ + selectW_ && mousePosY_ >= selectST1Y_ && mousePosY_ <= selectST1Y_ + selectH_)
	{
		selectST1Color_ = RED;
		if (selectST1Color_ = RED && Novice::IsPressMouse(0))
		{
			stageNo_ = 1;
			isGameStart_ = true;
		}
	}
	else
	{
		selectST1Color_ = WHITE;
	}

	// ステージ２を選択する処理
	if (mousePosX_ >= selectST2X_ && mousePosX_ <= selectST2X_ + selectW_ && mousePosY_ >= selectST2Y_ && mousePosY_ <= selectST2Y_ + selectH_)
	{
		selectST2Color_ = RED;
		if (selectST2Color_ = RED && Novice::IsPressMouse(0))
		{
			stageNo_ = 2;
			isGameStart_ = true;
		}
	}
	else
	{
		selectST2Color_ = WHITE;
	}

	// ステージ３を選択する処理
	if (mousePosX_ >= selectST3X_ && mousePosX_ <= selectST3X_ + selectW_ && mousePosY_ >= selectST3Y_ && mousePosY_ <= selectST3Y_ + selectH_)
	{
		selectST3Color_ = RED;
		if (selectST3Color_ = RED && Novice::IsPressMouse(0))
		{
			stageNo_ = 3;
			isGameStart_ = true;
		}
	}
	else
	{
		selectST3Color_ = WHITE;
	}

	// シーン遷移
	if (isGameStart_)
	{
		gameClear_->SetOpen(true);
	}

}

void StageSelect::Draw()
{
	// 背景
	Novice::DrawSprite(0, 0, BG_, 1, 1, 0, WHITE);

	// ステージ１を選択する処理
	if (mousePosX_ >= selectST1X_ && mousePosX_ <= selectST1X_ + selectW_ && mousePosY_ >= selectST1Y_ && mousePosY_ <= selectST1Y_ + selectH_)
	{
		Novice::DrawSprite(selectST1X_, selectST1Y_, selectStage1_, 1.f, 1.f, 0.0f, WHITE);
	}
	else
	{
		Novice::DrawSprite(selectST1X_, selectST1Y_, stage1_, 1.f, 1.f, 0.0f, WHITE);
	}

	// ステージ２を選択する処理
	if (mousePosX_ >= selectST2X_ && mousePosX_ <= selectST2X_ + selectW_ && mousePosY_ >= selectST2Y_ && mousePosY_ <= selectST2Y_ + selectH_)
	{
		Novice::DrawSprite(selectST2X_, selectST2Y_, selectStage2_, 1.f, 1.f, 0.0f, WHITE);
	}
	else
	{
		Novice::DrawSprite(selectST2X_, selectST2Y_, stage2_, 1.f, 1.f, 0.0f, WHITE);
	}

	// ステージ３を選択する処理
	if (mousePosX_ >= selectST3X_ && mousePosX_ <= selectST3X_ + selectW_ && mousePosY_ >= selectST3Y_ && mousePosY_ <= selectST3Y_ + selectH_)
	{
		Novice::DrawSprite(selectST3X_, selectST3Y_, selectStage3_, 1.f, 1.f, 0.0f, WHITE);
	}
	else
	{
		Novice::DrawSprite(selectST3X_, selectST3Y_, stage3_, 1.f, 1.f, 0.0f, WHITE);
	}

	// チュートリアルを選択する処理
	if (mousePosX_ >= selectTutorialX_ && mousePosX_ <= selectTutorialX_ + selectTW_ && mousePosY_ >= selectTutorialY_ && mousePosY_ <= selectTutorialY_ + selectTH_)
	{
		Novice::DrawSprite(selectTutorialX_, selectTutorialY_, selectTutorial_, 1.f, 1.f, 0.0f, WHITE);
	}
	else
	{
		Novice::DrawSprite(selectTutorialX_, selectTutorialY_, tutorial_, 1.f, 1.f, 0.0f, WHITE);
	}
}