#include <Novice.h>
#include "GameClear.h"

#pragma once
class Title
{
public:
	void Initialize();

	void Update();

	void Draw();

	void Animetion();

	bool GetIsStart() { return isStart_; }

	GameClear* GetGameClear()
	{
		return gameClear_;
	}

private:

	//スタートセレクトボックス（ゲーム開始のための）
	int selectStartX_ = 430;
	int selectStartY_ = 500;
	float selectStartH_ = 100;
	float selectStartW_ = 420;
	int selectStartColor_ = WHITE;

	// マウスポジション
	int mousePosX_ = 0;
	int mousePosY_ = 0;

	// テクスチャ
	int titleLogo_ = 0;
	int titleBack_ = 0;
	int start_ = 0;

	// タイトルアニメーション

	int titleScrX_ = 0;
	int titleScrW_ = 899;
	int scrLimitX_ = 14384;
	int animetionTimer = 0;

	// フラグ
	bool isStart_ = 0;

	GameClear* gameClear_ = nullptr;
};