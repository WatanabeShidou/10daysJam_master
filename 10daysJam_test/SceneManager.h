#include "Input.h"
#include "GameManager.h"
#include "Title.h"
#include "StageSelect.h"
#include "GameClear.h"
#include <Novice.h>

#pragma once

// 前方宣言（ステージセレクト）
class StageSelect;

class SceneManager
{
public:

	~SceneManager();

	void Initialize();

	void Update(char* keys, char* preKeys);

	void Draw();

private:

	enum scene {
		TitleScene,
		StageSelectScene,
		Game,
		GameClearScene,
		GameOverScene
	};

	int sceneNo_ = 0;

	// ゲーム管理
	GameManager* gameManager_ = nullptr;

	// タイトル管理
	Title* title_ = nullptr;

	// ステージセレクト管理
	StageSelect* stageSelect_ = nullptr;

	// ゲームクリア画面
	GameClear* gameClear_ = nullptr;
};