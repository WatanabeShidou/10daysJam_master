#define _USE_MATH_DEFINES
#include <math.h>
#include <Novice.h>
#include <Vector2.h>
#include "Struct.h"
#include "GameClear.h"
#include "GameOver.h"

#pragma once
class GameManager
{
public:

	void Initialize(int stageNo);

	void InitializeTutorial();

	void Update(int stageNo, char* keys, char* preKeys);

	void Draw(int stageNo);

	void MapReset(int stageNo);
	//　ヘッダー関数
	void Animation();

	GameClear* GetGameClear()
	{
		return gameClear_;
	}

	GameOver* GetGameOver()
	{
		return gameOver_;
	}

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

private:

	//　ヘッダー変数
	// アニメーション
	int spaceScrX_ = 0;
	int spaceW_ = 64;
	int animetionTimer_ = 0;

	struct Vector2 {
		float x;
		float y;
	};

	int Size = 64;	// ブロックサイズ

	// ステージ
	int stageNumber = 0;
	enum stageNumber {
		TUTORIAL,
		STAGE1,
		STAGE2,
		STAGE3,
		STAGE4,
		STAGE5,
		STAGE6,
		STAGE7 //追加分
	};

	// マップ初期値
	int mapCountX = 0, mapCountY = 0;

	//int move = 0;	// プレイヤーの向き 0右 1左

	// チュートリアル
	int tutorialMap[12][15] = {
	  {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},  // 0
	  {2,0,0,0,0,0,0,2,0,0,0,0,0,0,2},  // 1
	  {2,0,0,0,0,0,0,0,0,0,0,0,0,0,2},  // 2
	  {2,0,0,0,0,0,0,2,0,0,0,0,0,0,2},  // 3
	  {2,0,0,0,0,0,0,0,0,0,0,0,0,0,2},  // 4
	  {2,2,0,0,0,2,0,1,0,2,0,0,0,2,2},  // 5
	  {2,0,0,0,0,0,0,0,0,0,0,0,0,0,2},  // 6
	  {2,0,0,0,0,0,0,2,0,0,0,0,0,0,2},  // 7
	  {2,0,0,0,0,0,0,0,0,0,0,0,0,0,2},  // 8
	  {2,0,0,0,0,0,0,0,0,0,0,0,0,0,2},  // 9
	  {2,0,0,0,0,0,0,2,0,0,0,0,0,0,2},  // 10
	  {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},  // 11
	};

	int tutorialMapInitialize[12][15] = {
	  {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},  // 0
	  {2,0,0,0,0,0,0,0,0,0,0,0,0,0,2},  // 1
	  {2,0,0,0,0,0,0,0,0,0,0,0,0,0,2},  // 2
	  {2,0,0,0,0,0,0,0,0,0,0,0,0,0,2},  // 3
	  {2,0,0,0,0,0,0,2,0,0,0,0,0,0,2},  // 4
	  {2,0,0,0,0,0,0,0,0,0,0,0,0,0,2},  // 5
	  {2,0,0,0,0,2,0,1,0,2,0,0,0,0,2},  // 6
	  {2,0,0,0,0,0,0,0,0,0,0,0,0,0,2},  // 7
	  {2,0,0,0,0,0,0,2,0,0,0,0,0,0,2},  // 8
	  {2,0,0,0,0,0,0,0,0,0,0,0,0,0,2},  // 9
	  {2,0,0,0,0,0,0,0,0,0,0,0,0,0,2},  // 10
	  {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},  // 11
	};

	int tutorialMapInitialize2[12][15] = {
	  {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},  // 0
	  {2,0,0,0,0,0,0,0,0,0,0,0,0,0,2},  // 1
	  {2,0,2,2,2,2,2,2,2,2,2,2,2,0,2},  // 2
	  {2,0,2,2,2,2,2,2,2,2,2,2,2,0,2},  // 3
	  {2,0,2,2,2,2,2,2,2,2,2,2,2,0,2},  // 4
	  {2,0,2,2,2,2,2,8,2,2,2,2,2,0,2},  // 5
	  {2,0,2,2,2,2,2,0,2,2,2,2,2,0,2},  // 6
	  {2,0,2,2,2,2,2,0,2,2,2,2,2,0,2},  // 7
	  {2,0,2,2,2,2,2,0,2,2,2,2,2,0,2},  // 8
	  {2,0,2,2,2,2,2,0,2,2,2,2,2,0,2},  // 9
	  {2,1,2,2,2,2,2,0,0,0,0,0,0,0,2},  // 10
	  {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},  // 11
	};

	// 本編用マップ
	int map0[12][15] = {
	  {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},  // 0
	  {2,0,0,0,0,0,0,0,0,0,0,0,0,0,2},  // 1
	  {2,0,0,0,0,0,0,0,0,0,0,0,0,0,2},  // 2
	  {2,0,0,0,0,0,0,0,0,0,0,0,0,0,2},  // 3
	  {2,0,0,0,0,0,0,0,0,0,0,0,0,0,2},  // 4
	  {2,0,0,0,0,0,0,0,0,0,0,0,0,0,2},  // 5
	  {2,0,0,0,0,0,0,0,0,0,0,0,0,0,2},  // 6
	  {2,0,0,0,0,0,0,0,0,0,0,0,0,0,2},  // 7
	  {2,0,0,0,0,0,0,0,0,0,0,0,0,0,2},  // 8
	  {2,0,0,0,0,0,0,0,0,0,0,0,0,0,2},  // 9
	  {2,0,0,0,0,0,0,0,0,0,0,0,0,0,2},  // 10
	  {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},  // 11
	};

	int initializeMap0[12][15] = {
	  {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},  // 0
	  {2,0,0,0,0,0,0,0,0,0,0,0,0,0,2},  // 1
	  {2,0,0,0,0,0,0,0,0,0,0,0,0,0,2},  // 2
	  {2,0,0,0,0,0,2,8,2,0,0,0,0,0,2},  // 3
	  {2,0,0,0,0,0,2,2,2,0,0,0,0,0,2},  // 4
	  {2,0,0,0,0,0,0,0,0,0,0,0,0,0,2},  // 5
	  {2,0,2,2,2,0,0,0,0,0,2,2,2,0,2},  // 6
	  {2,0,0,0,0,0,0,0,0,0,0,0,0,0,2},  // 7
	  {2,0,0,0,0,0,0,0,0,0,0,0,0,0,2},  // 8
	  {2,0,0,0,0,0,2,0,2,0,0,0,0,0,2},  // 9
	  {2,0,0,0,0,0,0,1,0,0,0,0,0,0,2},  // 10
	  {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},  // 11
	};

	int map1[12][15] = {
	  {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},  // 0
	  {2,8,0,0,2,0,0,0,0,0,0,0,0,6,2},  // 1
	  {2,0,0,6,0,5,2,2,2,2,2,0,2,0,2},  // 2
	  {2,0,6,0,2,0,4,0,0,6,0,3,2,0,2},  // 3
	  {2,0,0,6,2,3,0,2,0,0,0,0,2,0,2},  // 4
	  {2,6,0,0,2,0,3,0,8,5,0,0,2,0,2},  // 5
	  {2,0,0,0,2,0,4,0,0,0,0,3,2,0,2},  // 6
	  {2,3,0,0,2,3,0,0,5,0,3,0,2,0,2},  // 7
	  {2,2,2,2,2,2,0,2,2,2,0,2,2,0,2},  // 8
	  {2,4,0,0,0,0,0,0,0,0,0,0,0,5,2},  // 9
	  {2,1,3,2,0,0,0,0,0,0,0,0,0,0,2},  // 10
	  {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},  // 11
	};

	int initializeMap1[12][15] = {
	  {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},  // 0
	  {2,8,0,0,2,0,0,0,0,0,0,0,0,6,2},  // 1
	  {2,0,0,6,17,5,2,2,2,2,2,0,2,0,2},  // 2
	  {2,0,6,0,2,0,4,0,0,6,0,3,2,0,2},  // 3
	  {2,0,0,6,2,3,0,2,0,0,0,0,2,0,2},  // 4
	  {2,6,0,0,2,0,3,0,0,5,0,0,2,13,2},  // 5
	  {2,0,0,0,2,0,4,0,0,0,0,3,2,0,2},  // 6
	  {2,3,0,0,2,3,0,0,5,0,3,0,2,0,2},  // 7
	  {2,2,2,2,2,2,0,2,2,2,0,2,2,0,2},  // 8
	  {2,4,0,0,0,0,0,0,0,0,0,0,0,5,2},  // 9
	  {2,1,3,2,0,0,0,0,0,0,0,0,0,0,2},  // 10
	  {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},  // 11
	};

	int map2[12][15] = {
		{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},  // 0
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,2},  // 1
		{2,0,0,0,0,0,0,0,0,0,2,0,0,0,2},  // 2
		{2,0,0,0,0,0,0,0,0,0,2,0,0,0,2},  // 3
		{2,0,0,0,0,0,0,0,0,0,2,0,0,0,2},  // 4
		{2,0,0,0,0,0,0,0,0,0,2,0,0,0,2},  // 5
		{2,0,0,0,0,0,0,0,0,0,2,0,0,0,2},  // 6
		{2,0,0,0,0,0,0,0,0,0,2,0,0,0,2},  // 7
		{2,0,0,0,0,0,0,0,0,0,2,0,0,0,2},  // 8
		{2,0,0,0,0,0,0,0,0,0,2,0,0,0,2},  // 9
		{2,1,0,0,0,0,0,0,0,0,2,0,0,0,2},  // 10
		{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},  // 11
	};

	int initializeMap2[12][15] = {
	  {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},  // 0
	  {2,8,0,17,0,0,0,0,0,0,12,2,0,9,2},  // 1
	  {2,0,0,17,0,0,0,0,0,0,0,2,0,0,2},  // 2
	  {2,2,2,2,2,2,2,2,2,2,2,2,0,0,2},  // 3
	  {2,13,0,2,0,0,0,0,2,0,0,18,0,0,2},  // 4
	  {2,0,0,2,0,2,0,0,0,0,0,18,0,0,2},  // 5
	  {2,2,0,2,0,2,0,0,2,0,0,2,2,0,2},  // 6
	  {2,0,0,2,0,0,0,2,2,0,0,2,0,0,2},  // 7
	  {2,0,2,2,15,2,0,0,0,0,2,2,0,0,2},  // 8
	  {2,0,2,2,2,2,2,2,2,2,2,2,0,0,2},  // 9
	  {2,10,0,0,0,0,0,0,0,0,0,2,0,1,2},  // 10
	  {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},  // 11
	};

	enum MapInfo {
		BACK,    // 0 背景
		PLAYER,    // 1 プレイヤー
		WALL,    // 2 壁
		UP,    // 3 上
		RIGHT,    // 4 右
		LEFT,    // 5 左
		DOWN,    // 6 下
		CLEAR,
		ENEMY,
		WARPPOINT1,//ワープポイント
		WARPPOINT2,
		WARPPOINT3,//ワープポイント2
		WARPPOINT4,
		SWITCH1,//スイッチ
		SWITCH2,
		SWITCH3,//スイッチ2
		SWITCH4,
		DOOR,//ドア
		DOOR2,//ドア
	};

	// マウス
	int mousePosX_ = 0;
	int mousePosY_ = 0;

	// 選択ボックス(仮)
	int selectWX_[4];
	int selectWY_[4];
	int selectWR_[4];
	int selectWColor_[4];

	int backColor_[12][15];

	// 四隅の判定
	int leftTX[4];
	int leftTY[4];
	int leftBX[4];
	int leftBY[4];
	int rightTX[4];
	int rightTY[4];
	int rightBX[4];
	int rightBY[4];
	int saveLeftTX[4];
	int saveLeftTY[4];

	// プレイヤーの弾
	int shotPosX_;//弾のX位置
	int shotPosY_;//弾のY位置
	int shotSpead_;//弾のスピード
	int shotFlag_;//打った判定をとるフラグ
	int shotMove_;//打つ弾の向き
	int collisionFlag_;//判定をとるフラグ
	int setShotFlag_;//打つまでのフラグ

	// プレイヤーの向き
	int savePlayerPosX_;
	int savePlayerPosY_;

	// チュートリアル用変数
	int countR_ = 0;
	int countL_ = 0;
	int countU_ = 0;
	int countD_ = 0;
	int textCount_ = 0;
	int tutorialScene_ = 0;
	bool isTutorial_ = 0;
	// チュートリアルテクスチャ
	int text[8] = {
		Novice::LoadTexture("./Resource/images/text0.png"),
		Novice::LoadTexture("./Resource/images/text1.png"),
		Novice::LoadTexture("./Resource/images/text2.png"),
		Novice::LoadTexture("./Resource/images/text3.png"),
		Novice::LoadTexture("./Resource/images/text4.png"),
		Novice::LoadTexture("./Resource/images/text5.png"),
		Novice::LoadTexture("./Resource/images/text6.png"),
		Novice::LoadTexture("./Resource/images/text7.png")
	};
	int mission[2] = {
		Novice::LoadTexture("./Resource/images/mission1.png"),
	};

	int blockC[2] = {
		Novice::LoadTexture("./Resource/images/warpC.png"),
		Novice::LoadTexture("./Resource/images/switchC.png"),
	};

	//イージング用変数
	float flame_ = 0.0f;
	float endFlame_ = 80.0f;
	float t_ = 0.0f;
	bool flagIn_ = 0;
	bool flagOut_ = 0;
	bool isOpen_ = 0;
	bool isClose_ = 0;
	// シーン遷移
	int sBoxX_ = 640;
	int sBoxY_ = 360;
	int sBoxR_ = 0;
	bool selectR_ = 0;
	bool selectL_ = 0;
	bool isGameClear_ = 0;
	int distance_ = 320;

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


	// フラグ
	bool isWall[4];
	int clickFlag_;
	int judgeFlag_ = 0;

	float efectPosX_[20];
	float efectPosY_[20];
	int efectTimer_;
	int efectFlag_[20];
	int saveFlag_;
	int Timer_[20];
	float efectVelocity_[20];
	float efectAcceleration_[20];
	int randSave[20];
	int shakeRandX_ = 0;
	int shakeRandY_ = 0;
	int shakeTimer_ = 0;
	int shakeFlag_ = 0;
	int update_ = 24;
	int enemyColor = 0;
	int a = 0;
	int saveShake_ = 0;

	//個数制限
	int rightBlockLimit = 0;
	int leftBlockLimit = 0;
	int upBlockLimit = 0;
	int downBlockLimit = 0;

	// フラグ
	int back = 0;
	int wall = 0;
	int deadFlag_ = 0;

	int BG = 0;

	int player = 0;
	int enemy = 0;

	int up = 0;
	int down = 0;
	int right = 0;
	int left = 0;
	int upAllow = 0;
	int downAllow = 0;
	int rightAllow = 0;
	int leftAllow = 0;
	int warpFlag = 0;
	int warpTimer = 0;
	int switchFlag_ = 0;
	int switch_ = 0;
	int switchTimer = 0;
	int textTimer_ = 0;

	int switchR1 = 0;
	int switchR2 = 0;
	int switchB1 = 0;
	int switchB2 = 0;
	int door1 = 0;
	int door2 = 0;
	int warp = 0;
	int warpR = 0;

	int space = 0;

	int panel = 0;

	int bullet = 0;

	GameClear* gameClear_ = nullptr;

	GameOver* gameOver_ = nullptr;
};