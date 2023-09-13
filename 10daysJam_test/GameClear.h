#define _USE_MATH_DEFINES
#include <math.h>
#include <Novice.h>
#include <Vector2.h>
#include "Struct.h"
#pragma once

class GameClear
{
private:

	//イージング用変数
	float flame_ = 0.0f;
	float endFlame_ = 80.0f;
	float t_ = 0.0f;
	bool flagIn_ = 0;
	bool flagOut_ = 0;
	bool selectR_ = 0;
	bool selectL_ = 0;
	bool isGameClear_ = 0;
	int distance_ = 320;

	// マウス
	int mousePosX_ = 0;
	int mousePosY_ = 0;

	struct Menu {
		Vector2 pos;    // 座標
		Vector2 vel;    // 速度
		Vector2 tmp;	// 加速度
		Vector2 easing;
		Vector2 src;
		int rad;        // 大きさ
		int color;
	};

	//メニューボックス
	Menu menu_
	{
	   {140,-800},
	   {0,0},
	   {10,0},
	   {5,0},
	   {0,0},
	   20,
	};
	float menuH_ = 600.0f;
	float menuW_ = 1000.0f;
	float scale = 1.0f;
	int afterLength_ = 60;

	// シーン遷移
	int sBoxX_ = 640;
	int sBoxY_ = 360;
	int sBoxR_ = 0;
	float sBoxRotate_ = 0.f;
	//フラグ
	bool isOpen_ = 0;
	bool isClose_ = 0;
	bool isSceneChange_ = 0;

	//選択肢BOX
	int boxColorR_ = WHITE;
	int boxColorL_ = WHITE;

	//テクスチャ
	int gameClear_ = 0;
	int retry_ = 0;
	int backSelect_ = 0;

	
	const int audioHandle_[5]
	{
		Novice::LoadAudio("./Resource/music/select.wav"),  //セレクトの音
		Novice::LoadAudio("./Resource/music/select.wav"),  //セレクトの音
		Novice::LoadAudio("./Resource/music/start.wav"),  //clickの音
	};
	int voiceHandle_[5]
	{
		-1,-1,-1,-1,-1
	};

public:

	//初期化関数
	void Initialize();

	/// <summary>
	/// 行動処理関数
	/// </summary>
	/// <param name="keys"></param>
	/// <param name="preKeys"></param>
	void Update(bool falgIn);

	//描画関数
	void Draw();

	/// <summary>
	/// イーズイン
	/// </summary>
	/// <param name="y"></param>
	/// <returns></returns>
	float easeInSine(float y) {
		return 1 + sinf((y * 3.14f) / 2.f);
	}

	/// <summary>
	/// イーズアウト
	/// </summary>
	/// <param name="y"></param>
	/// <returns></returns>
	float easeOutElastic(float y)
	{
		const float c4 = (2.0f * 3.14f) / 3.0f;
		return powf(2.f, -10.f * y) * sinf((y * 10.f - 0.75f) * c4) + 1.f;
	}

	/// <summary>
	/// イーズアウトバック
	/// </summary>
	/// <param name="y"></param>
	/// <returns></returns>
	float easeInOutBack(float y)
	{
		const float c1 = 1.70158f;
		const float c2 = c1 * 1.525f;

		/*if (y < 0.5f)
		{
			return (powf(2 * y, 2) * ((c2 + 1) * 2 * y - c2)) / 2;
		}*/
		return (powf(2.0f * y - 2.0f, 2.0f) * ((c2 + 1.0f) * (y * 2.0f - 2.0f) + c2) + 2.0f) /
			2.0f;
	}

	//ゲッター
	bool SelectR()
	{
		return selectR_;
	}
	bool SelectL()
	{
		return selectL_;
	}

	bool GetFIn()
	{
		return flagIn_;
	}
	bool GetFOut()
	{
		return flagOut_;
	}

	bool GetGameClear()
	{
		return isGameClear_;
	}

	bool IsSceneChange()
	{
		return isSceneChange_;
	}

	bool IsOpen()
	{
		return isOpen_;
	}

	int GetRad()
	{
		return sBoxR_;
	}

	//セッター
	void SetFIn(bool flag)
	{
		this->flagIn_ = flag;
	}
	void SetFOut(bool flag)
	{
		this->flagOut_ = flag;
	}

	void SetOpen(bool flag)
	{
		this->isOpen_ = flag;
	}

	void SetGameOver(bool isGameOver)
	{
		this->isGameClear_ = isGameOver;
	}

};