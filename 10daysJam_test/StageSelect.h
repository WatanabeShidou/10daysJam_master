#include <Novice.h>
#include "GameClear.h"

#pragma once
class StageSelect
{
public:

	void Initialize();

	void Update();

	void Draw();

	int GetStageNo() { return stageNo_; }

	bool IsGameStart() { return isGameStart_; }

	GameClear* GetGameClear()
	{
		return gameClear_;
	}

private:

	//ステージセレクトボックス
	//ステージ1
	int selectST1X_ = 30;
	int selectST1Y_ = 30;
	float selectEasySrcX_ = 0;
	float selectH_ = 470;
	float selectW_ = 400;
	int selectST1Color_ = WHITE;

	//ステージ2
	int selectST2X_ = 440;
	int selectST2Y_ = 30;
	float selectNormalSrcX_ = 0;
	int selectST2Color_ = WHITE;

	//ステージ3
	int selectST3X_ = 850;
	int selectST3Y_ = 30;
	float selectHardSrcX_ = 0;
	int selectST3Color_ = WHITE;

	//タイトルに戻るボックス
	int selectTutorialX_ = 30;
	int selectTutorialY_ = 588;
	float selectHSrcX_ = 0;
	float selectTW_ = 300;
	float selectTH_ = 150;
	int selectTutorialColor_ = WHITE;

	// マウスポジション
	int mousePosX_ = 0;
	int mousePosY_ = 0;

	// ステージナンバー
	int stageNo_ = 0;

	// フラグ
	bool isGameStart_ = 0;

	// テクスチャ
	int BG_ = 0;

	int stage1_ = 0;
	int stage2_ = 0;
	int stage3_ = 0;
	int tutorial_ = 0;

	int selectStage1_ = 0;
	int selectStage2_ = 0;
	int selectStage3_ = 0;
	int selectTutorial_ = 0;

	GameClear* gameClear_ = nullptr;
};