#include "GameManager.h"
#include <stdlib.h>

void GameManager::Initialize(int stageNo)
{
	shotFlag_ = 0;
	shotPosX_ = 0;
	shotPosY_ = 0;
	shotMove_ = 3;
	shotSpead_ = 8;
	collisionFlag_ = 1;
	setShotFlag_ = 0;

	rightBlockLimit = 3;
	leftBlockLimit = 4;
	upBlockLimit = 4;
	downBlockLimit = 2;
	switchFlag_ = 0;

	// ステージ１
	mapCountX = sizeof(map0[0]) / sizeof(map0[0][0]);
	mapCountY = sizeof(map0) / sizeof(map0[0]);

	for (int y = 0; y < mapCountY; y++) {
		for (int x = 0; x < mapCountX; x++) {
			// チュートリアル
			if (stageNo == TUTORIAL)
			{
				tutorialMap[y][x] = tutorialMapInitialize[y][x];
			}
			// ステージ１
			if (stageNo == STAGE1)
			{
				map0[y][x] = initializeMap0[y][x];
			}
			// ステージ２
			if (stageNo == STAGE2)
			{
				map1[y][x] = initializeMap1[y][x];
			}
			// ステージ３
			if (stageNo == STAGE3)
			{
				map2[y][x] = initializeMap2[y][x];
			}
			backColor_[y][x] = WHITE;
		}
	}

	for (int i = 0; i < 4; i++) {
		leftTX[i] = 0;
		leftTY[i] = 0;
		leftBX[i] = 0;
		leftBY[i] = 0;
		rightTX[i] = 0;
		rightTY[i] = 0;
		rightBX[i] = 0;
		rightBY[i] = 0;
		selectWX_[i] = 1085;
		selectWY_[0] = 165;
		selectWY_[1] = 330;
		selectWY_[2] = 485;
		selectWY_[3] = 650;
		selectWR_[i] = 64;
		selectWColor_[i] = 0;
		saveLeftTX[i] = 0;
		saveLeftTY[i] = 0;
		isWall[i] = 0;
		clickFlag_ = 0;
	}
	efectTimer_ = 0;
	for (int i = 0; i < 8; i++) {
		efectPosX_[i] = 0;
		efectPosY_[i] = 0;
		efectFlag_[i] = 0;
		saveFlag_ = 0;
		Timer_[i] = 0;
		efectAcceleration_[i] = 0.4f;
		efectVelocity_[i] = 0.0f;
		randSave[i] = 0;
	}

	shakeRandX_ = 0;
	shakeRandY_ = 0;
	shakeTimer_ = 0;
	shakeFlag_ = 0;
	update_ = 24;
	enemyColor = 0;
	a = 0;
	textTimer_ = 0;

	// テクスチャ

	BG = Novice::LoadTexture("./Resource/images/BG.png");
	space = Novice::LoadTexture("./Resource/images/space.png");

	back = Novice::LoadTexture("./Resource/images/backTile.png");
	wall = Novice::LoadTexture("./Resource/images/metaru.png");                     //壁
	player = Novice::LoadTexture("./Resource/images/player.png");
	enemy = Novice::LoadTexture("./Resource/images/enemy.png");

	up = Novice::LoadTexture("./Resource/images/up.png");
	down = Novice::LoadTexture("./Resource/images/down.png");
	right = Novice::LoadTexture("./Resource/images/right.png");
	left = Novice::LoadTexture("./Resource/images/left.png");
	upAllow = Novice::LoadTexture("./Resource/images/AllowUp.png");
	downAllow = Novice::LoadTexture("./Resource/images/Allowdown.png");
	rightAllow = Novice::LoadTexture("./Resource/images/AllowRight.png");
	leftAllow = Novice::LoadTexture("./Resource/images/AllowLeft.png");
	panel = Novice::LoadTexture("./Resource/images/panel.png");
	efect = Novice::LoadTexture("./Resource/images/efect.png");

	bullet = Novice::LoadTexture("./Resource/images/Bullet.png");

	text[0] = Novice::LoadTexture("./Resource/images/text0.png");
	text[1] = Novice::LoadTexture("./Resource/images/text1.png");
	text[2] = Novice::LoadTexture("./Resource/images/text2.png");
	text[3] = Novice::LoadTexture("./Resource/images/text3.png");
	text[4] = Novice::LoadTexture("./Resource/images/text4.png");
	text[5] = Novice::LoadTexture("./Resource/images/text5.png");
	text[6] = Novice::LoadTexture("./Resource/images/text6.png");
	text[7] = Novice::LoadTexture("./Resource/images/text7.png");

	mission[0] = Novice::LoadTexture("./Resource/images/mission1.png");
	mission[1] = Novice::LoadTexture("./Resource/images/mission2.png");
	switchR1 = Novice::LoadTexture("./Resource/images/redswitch1.png");
	switchR2 = Novice::LoadTexture("./Resource/images/redswitch2.png");
	switchB1 = Novice::LoadTexture("./Resource/images/blueswitch1.png");
	switchB2 = Novice::LoadTexture("./Resource/images/blueswitch2.png");
	door1 = Novice::LoadTexture("./Resource/images/doorBlock1.png");
	door2 = Novice::LoadTexture("./Resource/images/doorBlock2.png");
	warp = Novice::LoadTexture("./Resource/images/warppoint1.png");
	warpR = Novice::LoadTexture("./Resource/images/warppointR1.png");

	enemyColor = 0xFFFFFFFF;

	gameClear_ = new GameClear;
	gameClear_->Initialize();

	gameOver_ = new GameOver;
	gameOver_->Initialize();
}
void GameManager::InitializeTutorial()
{
	// チュートリアル用変数
	countR_ = 0;
	countL_ = 0;
	countU_ = 0;
	countD_ = 0;
	textCount_ = 0;
	tutorialScene_ = 0;
	isTutorial_ = 0;

	//イージング用変数
	flame_ = 0.0f;
	endFlame_ = 80.0f;
	t_ = 0.0f;
	flagIn_ = 0;
	flagOut_ = 0;
	isOpen_ = 0;
	isClose_ = 0;
	// シーン遷移
	sBoxX_ = 640;
	sBoxY_ = 360;
	sBoxR_ = 0;
	selectR_ = 0;
	selectL_ = 0;
	isGameClear_ = 0;
	distance_ = 320;

	efectTimer_ = 0;
	for (int i = 0; i < 8; i++) {
		efectPosX_[i] = 0;
		efectPosY_[i] = 0;
		efectFlag_[i] = 0;
		saveFlag_ = 0;
		Timer_[i] = 0;
		efectAcceleration_[i] = 0.4f;
		efectVelocity_[i] = 0.0f;
		randSave[i] = 0;
	}
	shakeRandX_ = 0;
	shakeRandY_ = 0;
	shakeTimer_ = 0;
	shakeFlag_ = 0;
	update_ = 24;
	enemyColor = WHITE;
	a = 0;
	deadFlag_ = 0;
	textTimer_ = 0;
}
void GameManager::Update(int stageNo, char* keys, char* preKeys)
{

	Novice::GetMousePosition(&mousePosX_, &mousePosY_);

	int leftTopX_ = (shotPosX_) / Size;
	int leftBottomX_ = (shotPosX_) / Size;

	int rightTopX_ = (shotPosX_ + Size - 1) / Size;
	int rightBottomX_ = (shotPosX_ + Size - 1) / Size;

	int leftBottomY_ = (shotPosY_ + Size - 1) / Size;
	int rightBottomY_ = (shotPosY_ + Size - 1) / Size;

	int rightTopY_ = (shotPosY_) / Size;
	int leftTopY_ = (shotPosY_) / Size;

	for (int i = 0; i < 4; i++) {
		// 四隅の判定
		leftTX[i] = selectWX_[i] / Size;
		leftTY[i] = selectWY_[i] / Size;
		leftBX[i] = selectWX_[i] / Size;
		leftBY[i] = (selectWY_[i] + selectWR_[i] - 1) / Size;
		rightTX[i] = (selectWX_[i] + selectWR_[i] - 1) / Size;
		rightTY[i] = selectWY_[i] / Size;
		rightBX[i] = (selectWX_[i] + selectWR_[i] - 1) / Size;
		rightBY[i] = (selectWY_[i] + selectWR_[i] - 1) / Size;
	}

	if (shotPosX_ >= 860 || shotPosX_ <= 0) {
		shotFlag_ = 0;
	}

	// チュートリアル
	if (stageNo == TUTORIAL)
	{
		// 弾操作
		if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0 && isTutorial_) {
			shotFlag_ = 1;
		}
		////
		if (!isTutorial_)
		{
			Animation();
			textTimer_ += 1;
			if (tutorialScene_ == 0)
			{
				if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0 && textCount_ < 3 && textTimer_ >= 150)
				{
					textCount_ += 1;
					if (textCount_ >= 3)
					{
						flagIn_ = true;
					}
				}
				if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0 && textCount_ < 4 &&
					countL_ == 1 && countR_ == 1 && countU_ == 1 && countD_ == 1)
				{
					textCount_ += 1;
					if (textCount_ >= 4)
					{
						isOpen_ = true;
					}
				}
			}

			if (tutorialScene_ == 1)
			{
				if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0 && textCount_ < 6 && sBoxR_ <= 0)
				{
					textCount_ += 1;
					if (textCount_ >= 6)
					{
						flagIn_ = true;
					}
				}
				if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0 && textCount_ < 8 && deadFlag_ == 2 && sBoxR_ <= 0)
				{
					textCount_ += 1;
					if (textCount_ >= 8)
					{
						gameClear_->SetFIn(true);
					}
				}
			}

			// シーン遷移エフェクト処理
			if (isOpen_ && !isClose_)
			{
				sBoxR_ += 10;
			}
			if (isClose_)
			{
				sBoxR_ -= 10;
			}
			if (sBoxR_ >= 1400)
			{
				isClose_ = true;
				if (tutorialScene_ == 0)
				{
					tutorialScene_ = 1;
					deadFlag_ = 0;
					enemyColor = WHITE;
					shakeFlag_ = 0;
					shakeRandX_ = 0;
					shakeRandY_ = 0;
					MapReset(stageNo);
				}
			}
			if (sBoxR_ <= 0)
			{
				isOpen_ = false;
				isClose_ = false;
			}

			// イージング
			if (flagIn_)
			{
				flame_++;
				if (flame_ >= endFlame_)
				{
					flame_ = endFlame_;
				}

				t_ = flame_ / endFlame_;
				menu_.easing.y = easeOutElastic(t_);
				menu_.vel.y = menu_.easing.y * distance_;
				menu_.pos.y = menu_.vel.y + (-240);
			}

			if (keys[DIK_C] && !flagIn_)
			{
				flagOut_ = true;
			}
			if (flagOut_)
			{
				flame_--;
				t_ = flame_ / endFlame_;
				menu_.easing.y = easeInOutBack(t_);
				menu_.vel.y = menu_.easing.y * distance_;
				menu_.pos.y = menu_.vel.y + (-240);
			}

			if (flame_ >= endFlame_ && flagIn_)
			{
				flagIn_ = false;
			}

			if (flame_ <= 0 && flagOut_)
			{
				flagOut_ = false;
				isTutorial_ = true;
			}
		}
		////
		if (isTutorial_)
		{
			if (tutorialMap[leftTopY_][leftTopX_] == ENEMY || tutorialMap[rightTopY_][rightTopX_] == ENEMY) {
				judgeFlag_ = 1;
				deadFlag_ = 1;
				shotFlag_ = 0;
				shakeFlag_ = 1;
			}
			else {
				judgeFlag_ = 0;
			}

			//シェイク
			if (shakeFlag_ == 1) {
				if (Novice::IsPlayingAudio(voiceHandle[1]) == 0 || voiceHandle[1] == -1)
				{
					voiceHandle[1] = Novice::PlayAudio(audioHandle[1], 0, 0.1f);
				}
				shakeRandX_ = update_;
				shakeRandX_ = rand() % shakeRandX_ - 12;
				shakeRandY_ = update_;
				shakeRandY_ = rand() % shakeRandY_ - 12;
				if (saveFlag_ == 25) {
					Novice::StopAudio(voiceHandle[1]);
					saveShake_ = 1;
					a += 1;
					if (a == 5) {
						update_ -= 1;
						a = 0;
					}
				}
				if (update_ <= 0) {
					if (Novice::IsPlayingAudio(voiceHandle[2]) == 0 || voiceHandle[2] == -1)
					{
						voiceHandle[2] = Novice::PlayAudio(audioHandle[2], 0, 0.1f);
					}
					saveShake_ = 0;
					shakeFlag_ = 2;
					update_ = 24;
				}
			}
			if (shakeFlag_ == 2) {
				enemyColor -= 3;
				for (int i = 0; i < 8; i++) {
					if (efectTimer_ >= 50) {
						if (efectFlag_[i] == 1) {

							if (Timer_[i] <= 3000) {
								Timer_[i] += 1;
								efectPosX_[0] += 0.5f;
								efectPosX_[1] -= 0.5f;
								efectPosY_[2] += 0.5f;
								efectPosY_[3] -= 0.5f;

								efectPosX_[4] += 0.5f;
								efectPosY_[4] += 0.5f;
								efectPosX_[5] -= 0.5f;
								efectPosY_[5] -= 0.5f;
								efectPosX_[6] -= 0.5f;
								efectPosY_[6] += 0.5f;
								efectPosX_[7] += 0.5f;
								efectPosY_[7] -= 0.5f;
							}
							if (Timer_[i] >= 3000) {
								efectFlag_[i] = 0;
								Timer_[i] = 0;

							}
						}
						else {
							efectFlag_[i] = 1;
							//efectTimer_ = 0;
							for (int y = 0; y < mapCountY; y++) {
								for (int x = 0; x < mapCountX; x++) {
									if (tutorialMap[y][x] == ENEMY) {
										efectPosX_[i] = (float(x * Size));
										efectPosY_[i] = (float(y * Size));
									}
								}
							}
						}
					}
				}
				if (enemyColor <= -255) {
					Novice::StopAudio(voiceHandle[2]);
					enemyColor = -255;
					shakeFlag_ = 3;
				}
			}

			if (shakeFlag_ == 3) {
				deadFlag_ = 2;
			}

			//エフェクト
			for (int i = 0; i < 8; i++) {
				randSave[0] = rand() % 4 + 1;
				randSave[1] = rand() % 4 + 1;
				randSave[2] = rand() % 4 + 1;
				randSave[3] = rand() % 4 + 1;
				randSave[4] = rand() % 7 + 5;
				randSave[5] = rand() % 7 + 5;
				randSave[6] = rand() % 7 + 5;
				randSave[7] = rand() % 7 + 5;
				if (deadFlag_ == 1) {
					if (efectTimer_ <= 50) {
						efectTimer_ += 1;

						if (efectTimer_ >= 51) {
							efectTimer_ -= 1;
						}
					}
					if (efectTimer_ == 50) {

						if (saveFlag_ <= 24) {
							if (efectFlag_[i] == 1) {


								if (Timer_[i] <= 15) {
									Timer_[i] += 1;
									efectPosX_[0] += 0.5f;
									efectPosX_[1] -= 0.5f;
									efectPosX_[2] += 1.0f;
									efectPosX_[3] -= 1.0f;
									efectPosX_[4] += 0.1f;
									efectPosX_[5] -= 0.1f;
									efectPosX_[6] += 1.5f;
									efectPosX_[7] -= 1.5f;

									efectPosY_[i] -= efectVelocity_[i];
									efectVelocity_[i] -= efectAcceleration_[i];
								}
								if (Timer_[i] >= 15) {
									efectFlag_[i] = 0;
									Timer_[i] = 0;

								}

							}
							else {
								efectFlag_[i] = 1;
								saveFlag_ += 1;
								efectVelocity_[i] = (float(randSave[i]));
								efectTimer_ = 0;
								for (int y = 0; y < mapCountY; y++) {
									for (int x = 0; x < mapCountX; x++) {
										if (tutorialMap[y][x] == ENEMY) {
											efectPosX_[i] = (float(x * Size));
											efectPosY_[i] = (float(y * Size));
										}
									}
								}
							}
						}
					}
				}
			}


			// プレイヤー操作
			for (int y = 0; y < mapCountY; y++) {
				for (int x = 0; x < mapCountX; x++) {
					if (tutorialMap[y][x] == PLAYER) {
						if (shotFlag_ == 0) {

							shotPosX_ = x * Size;
							shotPosY_ = y * Size;
							savePlayerPosX_ = shotPosX_;
							savePlayerPosY_ = shotPosY_;
						}
					}

					if (judgeFlag_ == 1) {
						if (tutorialMap[y][x] == ENEMY) {
							for (int i = 0; i < 8; i++) {

								efectPosX_[i] = (float(x * Size));
								efectPosY_[i] = (float(y * Size));

							}
						}
					}
					//壁の判定

					//左
					if (shotMove_ == 1) {
						if (collisionFlag_ == 1) {
							if (tutorialMap[leftTopY_][leftTopX_] == WALL) {
								if (tutorialMap[rightTopY_][rightTopX_] == BACK || tutorialMap[rightTopY_][rightTopX_] == PLAYER) {
									setShotFlag_ = 1;
								}
								if (tutorialMap[rightTopY_][rightTopX_] == LEFT) {
									setShotFlag_ = 1;
								}
							}
							if (tutorialMap[leftTopY_][leftTopX_] == UP || tutorialMap[rightBottomY_][rightBottomX_] == DOWN ||
								tutorialMap[leftBottomY_][leftBottomX_] == RIGHT) {
								setShotFlag_ = 2;
							}
						}

						if (setShotFlag_ == 1) {
							shotFlag_ = 0;
							setShotFlag_ = 0;
						}
						if (setShotFlag_ == 2) {
							setShotFlag_ = 0;
						}

						if (tutorialMap[leftTopY_][leftTopX_] == WALL) {
							collisionFlag_ = 1;
						}
						else {
							collisionFlag_ = 0;

						}
					}

					//右
					if (shotMove_ == 2) {


						if (tutorialMap[rightTopY_][rightTopX_] == WALL) {
							collisionFlag_ = 1;
						}
						else {
							collisionFlag_ = 0;

						}

						if (collisionFlag_ == 1) {

							if (tutorialMap[leftTopY_][leftTopX_] == BACK && tutorialMap[leftBottomY_][leftBottomX_] == BACK || tutorialMap[leftTopY_][leftTopX_] == PLAYER) {
								setShotFlag_ = 1;
							}
							if (tutorialMap[leftTopY_][leftTopX_] == RIGHT) {
								setShotFlag_ = 1;
							}

							if (tutorialMap[rightTopY_][rightTopX_] == WALL && tutorialMap[rightBottomY_][rightBottomX_] == WALL &&
								tutorialMap[leftBottomY_][leftBottomX_] == WALL) {
								setShotFlag_ = 1;
							}

							if (tutorialMap[leftTopY_][leftTopX_] == UP || tutorialMap[leftBottomY_][leftBottomX_] == DOWN ||
								tutorialMap[leftBottomY_][leftBottomX_] == LEFT) {
								setShotFlag_ = 2;
							}
						}

						if (tutorialMap[rightTopY_][rightTopX_] == BACK && tutorialMap[rightBottomY_][rightBottomX_] == BACK &&
							tutorialMap[leftTopY_][leftTopX_] == BACK && tutorialMap[leftBottomY_][leftBottomX_] == BACK) {
							setShotFlag_ = 2;
						}
						if (setShotFlag_ == 1) {
							shotFlag_ = 0;
							setShotFlag_ = 0;
						}
						if (setShotFlag_ == 2) {
							setShotFlag_ = 0;
						}



					}

					//上
					if (shotMove_ == 3) {

						if (collisionFlag_ == 1) {
							if (tutorialMap[leftTopY_][leftTopX_] == WALL) {
								if (tutorialMap[leftBottomY_][leftBottomX_] == BACK || tutorialMap[leftBottomY_][leftBottomX_] == PLAYER) {
									setShotFlag_ = 1;
								}
								if (tutorialMap[leftBottomY_][leftBottomX_] == UP) {
									setShotFlag_ = 1;
								}
							}
							if (tutorialMap[leftTopY_][leftTopX_] == DOWN ||
								tutorialMap[leftTopY_][leftTopX_] == RIGHT || tutorialMap[leftTopY_][leftTopX_] == LEFT) {
								setShotFlag_ = 2;
							}

						}

						if (setShotFlag_ == 1) {
							shotFlag_ = 0;
							setShotFlag_ = 0;
						}
						if (setShotFlag_ == 2) {
							setShotFlag_ = 0;
						}

						if (tutorialMap[leftTopY_][leftTopX_] == WALL) {
							collisionFlag_ = 1;
						}
						else {
							collisionFlag_ = 0;
						}

					}

					//下
					if (shotMove_ == 4) {

						if (collisionFlag_ == 1) {
							if (tutorialMap[leftBottomY_][leftBottomX_] == WALL) {
								if (tutorialMap[leftTopY_][leftTopX_] == BACK || tutorialMap[leftTopY_][leftTopX_] == PLAYER || tutorialMap[rightTopY_][rightTopX_] == PLAYER) {
									setShotFlag_ = 1;
								}
								if (tutorialMap[leftTopY_][leftTopX_] == DOWN) {
									setShotFlag_ = 1;
								}
							}

							if (tutorialMap[leftTopY_][leftTopX_] == UP ||
								tutorialMap[leftTopY_][leftTopX_] == RIGHT || tutorialMap[leftTopY_][leftTopX_] == LEFT) {
								setShotFlag_ = 2;
							}
						}

						if (setShotFlag_ == 1) {
							shotFlag_ = 0;
							setShotFlag_ = 0;
						}
						if (setShotFlag_ == 2) {
							setShotFlag_ = 0;
						}

						if (tutorialMap[leftBottomY_][leftBottomX_] == WALL) {
							collisionFlag_ = 1;
						}
						else {
							collisionFlag_ = 0;

						}

					}

					//スライド
					if (shotMove_ == 1) {
						if (tutorialMap[rightBottomY_][rightBottomX_] == UP) {
							shotMove_ = 3;
						}

						if (tutorialMap[rightTopY_][rightTopX_] == RIGHT) {
							shotMove_ = 2;
						}

						if (tutorialMap[rightTopY_][rightTopX_] == LEFT) {
							shotMove_ = 1;
						}

						if (tutorialMap[rightBottomY_][rightBottomX_] == DOWN) {
							shotMove_ = 4;
						}
					}

					if (shotMove_ == 2) {
						if (tutorialMap[leftTopY_][leftTopX_] == UP) {
							shotMove_ = 3;
						}

						if (tutorialMap[leftTopY_][leftTopX_] == RIGHT) {
							shotMove_ = 2;
						}

						if (tutorialMap[leftTopY_][leftTopX_] == LEFT) {
							shotMove_ = 1;
						}

						if (tutorialMap[leftTopY_][leftTopX_] == DOWN) {
							shotMove_ = 4;
						}
					}

					if (shotMove_ == 3) {
						if (tutorialMap[leftBottomY_][leftBottomX_] == UP) {
							shotMove_ = 3;
						}

						if (tutorialMap[leftBottomY_][leftBottomX_] == RIGHT) {
							shotMove_ = 2;
						}

						if (tutorialMap[leftBottomY_][leftBottomX_] == LEFT) {
							shotMove_ = 1;
						}

						if (tutorialMap[leftBottomY_][leftBottomX_] == DOWN) {
							shotMove_ = 4;
						}
					}

					if (shotMove_ == 4) {

						if (tutorialMap[leftTopY_][leftTopX_] == UP) {
							shotMove_ = 3;
						}

						if (tutorialMap[leftTopY_][leftTopX_] == RIGHT) {
							shotMove_ = 2;
						}

						if (tutorialMap[leftTopY_][leftTopX_] == LEFT) {
							shotMove_ = 1;
						}
						if (tutorialMap[leftTopY_][leftTopX_] == DOWN) {
							shotMove_ = 4;
						}
					}

				}
			}
			if (shotFlag_ == 0) {
				//左ブロック
				if (mousePosX_ >= selectWX_[0] && mousePosX_ <= selectWX_[0] + selectWR_[0] &&
					mousePosY_ >= selectWY_[0] && mousePosY_ <= selectWY_[0] + selectWR_[0] && !isWall[0])
				{
					if (Novice::IsPlayingAudio(voiceHandle[6]) == 0 || voiceHandle[6] == -1)
					{
						voiceHandle[6] = Novice::PlayAudio(audioHandle[6], 0, 0.1f);
					}
					selectWColor_[0] = RED;
				}
				else
				{
					Novice::StopAudio(voiceHandle[6]);
					selectWColor_[0] = WHITE;
				}
				if (clickFlag_ == 0) {
					if (selectWColor_[0] == RED && Novice::IsPressMouse(0))
					{
						isWall[0] = true;
						clickFlag_ = 1;
					}
				}
				if (clickFlag_ == 1) {
					if (isWall[0])
					{
						selectWX_[0] = mousePosX_;
						selectWY_[0] = mousePosY_;
					}

					// マップとブロックの配置判定
					if (tutorialMap[leftTY[0]][leftTX[0]] == BACK && isWall[0] && selectWX_[0] <= 960)
					{
						backColor_[saveLeftTY[0]][saveLeftTX[0]] = WHITE;
						backColor_[leftTY[0]][leftTX[0]] = RED;
						saveLeftTX[0] = leftTX[0];
						saveLeftTY[0] = leftTY[0];
					}

					if (Novice::IsPressMouse(1) && backColor_[leftTY[0]][leftTX[0]] == RED && tutorialMap[leftTY[0]][leftTX[0]] == BACK)
					{
						if (Novice::IsPlayingAudio(voiceHandle[0]) == 0 || voiceHandle[0] == -1)
						{
							voiceHandle[0] = Novice::PlayAudio(audioHandle[0], 0, 0.1f);
						}
						tutorialMap[leftTY[0]][leftTX[0]] = LEFT;
						isWall[0] = false;
						clickFlag_ = 0;
						selectWX_[0] = 1085;
						selectWY_[0] = 165;
					}
				}
				//右ブロック
				if (mousePosX_ >= selectWX_[1] && mousePosX_ <= selectWX_[1] + selectWR_[1] &&
					mousePosY_ >= selectWY_[1] && mousePosY_ <= selectWY_[1] + selectWR_[1] && !isWall[1])
				{
					if (Novice::IsPlayingAudio(voiceHandle[7]) == 0 || voiceHandle[7] == -1)
					{
						voiceHandle[7] = Novice::PlayAudio(audioHandle[7], 0, 0.1f);
					}
					selectWColor_[1] = RED;
				}
				else
				{
					Novice::StopAudio(voiceHandle[7]);
					selectWColor_[1] = WHITE;
				}
				if (clickFlag_ == 0) {
					if (selectWColor_[1] == RED && Novice::IsPressMouse(0))
					{
						isWall[1] = true;
						clickFlag_ = 2;
					}
				}
				if (clickFlag_ == 2) {
					if (isWall[1])
					{
						selectWX_[1] = mousePosX_;
						selectWY_[1] = mousePosY_;
					}
					// マップとブロックの配置判定
					if (tutorialMap[leftTY[1]][leftTX[1]] == BACK && isWall[1] && selectWX_[1] <= 960)
					{
						backColor_[saveLeftTY[1]][saveLeftTX[1]] = WHITE;
						backColor_[leftTY[1]][leftTX[1]] = RED;
						saveLeftTX[1] = leftTX[1];
						saveLeftTY[1] = leftTY[1];
					}

					if (Novice::IsPressMouse(1) && backColor_[leftTY[1]][leftTX[1]] == RED && tutorialMap[leftTY[1]][leftTX[1]] == BACK)
					{
						if (Novice::IsPlayingAudio(voiceHandle[0]) == 0 || voiceHandle[0] == -1)
						{
							voiceHandle[0] = Novice::PlayAudio(audioHandle[0], 0, 0.1f);
						}
						tutorialMap[leftTY[1]][leftTX[1]] = RIGHT;
						isWall[1] = false;
						clickFlag_ = 0;
						selectWX_[1] = 1085;
						selectWY_[1] = 330;
					}

				}
				//下ブロック
				if (mousePosX_ >= selectWX_[2] && mousePosX_ <= selectWX_[2] + selectWR_[2] &&
					mousePosY_ >= selectWY_[2] && mousePosY_ <= selectWY_[2] + selectWR_[2] && !isWall[2])
				{
					if (Novice::IsPlayingAudio(voiceHandle[8]) == 0 || voiceHandle[8] == -1)
					{
						voiceHandle[8] = Novice::PlayAudio(audioHandle[8], 0, 0.1f);
					}
					selectWColor_[2] = RED;
				}
				else
				{
					Novice::StopAudio(voiceHandle[8]);
					selectWColor_[2] = WHITE;
				}
				if (clickFlag_ == 0) {
					if (selectWColor_[2] == RED && Novice::IsPressMouse(0))
					{
						isWall[2] = true;
						clickFlag_ = 3;
					}
				}
				if (clickFlag_ == 3) {
					if (isWall[2])
					{
						selectWX_[2] = mousePosX_;
						selectWY_[2] = mousePosY_;
					}
					// マップとブロックの配置判定
					if (tutorialMap[leftTY[2]][leftTX[2]] == BACK && isWall[2] && selectWX_[2] <= 960)
					{
						backColor_[saveLeftTY[2]][saveLeftTX[2]] = WHITE;
						backColor_[leftTY[2]][leftTX[2]] = RED;
						saveLeftTX[2] = leftTX[2];
						saveLeftTY[2] = leftTY[2];
					}

					if (Novice::IsPressMouse(1) && backColor_[leftTY[2]][leftTX[2]] == RED && tutorialMap[leftTY[2]][leftTX[2]] == BACK)
					{
						if (Novice::IsPlayingAudio(voiceHandle[0]) == 0 || voiceHandle[0] == -1)
						{
							voiceHandle[0] = Novice::PlayAudio(audioHandle[0], 0, 0.1f);
						}
						tutorialMap[leftTY[2]][leftTX[2]] = DOWN;
						isWall[2] = false;
						clickFlag_ = 0;
						selectWX_[2] = 1085;
						selectWY_[2] = 485;
					}
				}
				//上ブロック
				if (mousePosX_ >= selectWX_[3] && mousePosX_ <= selectWX_[3] + selectWR_[3] &&
					mousePosY_ >= selectWY_[3] && mousePosY_ <= selectWY_[3] + selectWR_[3] && !isWall[3])
				{
					if (Novice::IsPlayingAudio(voiceHandle[9]) == 0 || voiceHandle[9] == -1)
					{
						voiceHandle[9] = Novice::PlayAudio(audioHandle[9], 0, 0.1f);
					}
					selectWColor_[3] = RED;
				}
				else
				{
					Novice::StopAudio(voiceHandle[9]);
					selectWColor_[3] = WHITE;
				}
				if (clickFlag_ == 0) {
					if (selectWColor_[3] == RED && Novice::IsPressMouse(0))
					{
						isWall[3] = true;
						clickFlag_ = 4;
					}
				}
				if (clickFlag_ == 4) {
					if (isWall[3])
					{
						selectWX_[3] = mousePosX_;
						selectWY_[3] = mousePosY_;
					}
					// マップとブロックの配置判定
					if (tutorialMap[leftTY[3]][leftTX[3]] == BACK && isWall[3] && selectWX_[3] <= 960)
					{
						backColor_[saveLeftTY[3]][saveLeftTX[3]] = WHITE;
						backColor_[leftTY[3]][leftTX[3]] = RED;
						saveLeftTX[3] = leftTX[3];
						saveLeftTY[3] = leftTY[3];
					}

					if (Novice::IsPressMouse(1) && backColor_[leftTY[3]][leftTX[3]] == RED && tutorialMap[leftTY[3]][leftTX[3]] == BACK)
					{
						if (Novice::IsPlayingAudio(voiceHandle[0]) == 0 || voiceHandle[0] == -1)
						{
							voiceHandle[0] = Novice::PlayAudio(audioHandle[0], 0, 0.1f);
						}
						tutorialMap[leftTY[3]][leftTX[3]] = UP;
						isWall[3] = false;
						clickFlag_ = 0;
						selectWX_[3] = 1085;
						selectWY_[3] = 650;
					}
				}
			}

			// チュートリアルミッション
			if (tutorialScene_ == 0)
			{
				if (countL_ == 1 && countR_ == 1 && countU_ == 1 && countD_ == 1 && shotFlag_ == 0)
				{
					isTutorial_ = false;
				}
			}
			if (tutorialScene_ == 1)
			{
				if (deadFlag_ == 2)
				{
					isTutorial_ = false;
				}
			}
		}
		// 弾操作
		if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0 && isTutorial_ && shotFlag_ == 0) {
			shotFlag_ = 1;
			if (Novice::IsPlayingAudio(voiceHandle[3]) == 0 || voiceHandle[3] == -1)
			{
				voiceHandle[3] = Novice::PlayAudio(audioHandle[3], 0, 0.1f);
			}
		}
		if (shotFlag_ == 0) {
			Novice::StopAudio(voiceHandle[3]);
		}
	}

	// ステージ1
	if (stageNo == STAGE1)
	{
		if (deadFlag_ == 0) {
			// 弾操作
			if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0 && shotFlag_ == 0) {
				shotFlag_ = 1;
				if (Novice::IsPlayingAudio(voiceHandle[3]) == 0 || voiceHandle[3] == -1)
				{
					voiceHandle[3] = Novice::PlayAudio(audioHandle[3], 0, 0.1f);
				}
			}
			if (shotFlag_ == 0) {
				Novice::StopAudio(voiceHandle[3]);
			}
		}
		if (map0[leftTopY_][leftTopX_] == ENEMY || map0[rightTopY_][rightTopX_] == ENEMY) {
			judgeFlag_ = 1;
			deadFlag_ = 1;
			shotFlag_ = 0;
			shakeFlag_ = 1;
		}
		else {
			judgeFlag_ = 0;
		}

		//シェイク
		if (shakeFlag_ == 1) {
			if (Novice::IsPlayingAudio(voiceHandle[1]) == 0 || voiceHandle[1] == -1)
			{
				voiceHandle[1] = Novice::PlayAudio(audioHandle[1], 0, 0.1f);
			}
			shakeRandX_ = update_;
			shakeRandX_ = rand() % shakeRandX_ - 12;
			shakeRandY_ = update_;
			shakeRandY_ = rand() % shakeRandY_ - 12;
			if (saveFlag_ == 25) {
				Novice::StopAudio(voiceHandle[1]);
				saveShake_ = 1;
				a += 1;
				if (a == 5) {
					update_ -= 1;
					a = 0;
				}
			}
			if (update_ <= 0) {
				if (Novice::IsPlayingAudio(voiceHandle[2]) == 0 || voiceHandle[2] == -1)
				{
					voiceHandle[2] = Novice::PlayAudio(audioHandle[2], 0, 0.1f);
				}
				saveShake_ = 0;
				shakeFlag_ = 2;
				update_ = 24;
			}
		}
		if (shakeFlag_ == 2) {
			
			enemyColor -= 3;
			for (int i = 0; i < 8; i++) {
				if (efectTimer_ >= 50) {
					if (efectFlag_[i] == 1) {

						if (Timer_[i] <= 3000) {
							Timer_[i] += 1;
							efectPosX_[0] += 0.5f;
							efectPosX_[1] -= 0.5f;
							efectPosY_[2] += 0.5f;
							efectPosY_[3] -= 0.5f;

							efectPosX_[4] += 0.5f;
							efectPosY_[4] += 0.5f;
							efectPosX_[5] -= 0.5f;
							efectPosY_[5] -= 0.5f;
							efectPosX_[6] -= 0.5f;
							efectPosY_[6] += 0.5f;
							efectPosX_[7] += 0.5f;
							efectPosY_[7] -= 0.5f;
						}
						if (Timer_[i] >= 3000) {
							efectFlag_[i] = 0;
							Timer_[i] = 0;

						}
					}
					else {
						efectFlag_[i] = 1;
						//efectTimer_ = 0;
						for (int y = 0; y < mapCountY; y++) {
							for (int x = 0; x < mapCountX; x++) {
								if (map0[y][x] == ENEMY) {
									efectPosX_[i] = (float(x * Size));
									efectPosY_[i] = (float(y * Size));
								}
							}
						}
					}
				}
			}
			if (enemyColor <= -255) {
				Novice::StopAudio(voiceHandle[2]);
				enemyColor = -255;
				shakeFlag_ = 3;
			}
		}

		if (shakeFlag_ == 3) {
			deadFlag_ = 2;
			shakeFlag_ = 0;
		}

		//エフェクト
		for (int i = 0; i < 8; i++) {
			randSave[0] = rand() % 4 + 1;
			randSave[1] = rand() % 4 + 1;
			randSave[2] = rand() % 4 + 1;
			randSave[3] = rand() % 4 + 1;
			randSave[4] = rand() % 7 + 5;
			randSave[5] = rand() % 7 + 5;
			randSave[6] = rand() % 7 + 5;
			randSave[7] = rand() % 7 + 5;
			if (deadFlag_ == 1) {
				if (efectTimer_ <= 50) {
					efectTimer_ += 1;

					if (efectTimer_ >= 51) {
						efectTimer_ -= 1;
					}
				}
				if (efectTimer_ == 50) {

					if (saveFlag_ <= 24) {
						if (efectFlag_[i] == 1) {


							if (Timer_[i] <= 15) {
								Timer_[i] += 1;
								efectPosX_[0] += 0.5f;
								efectPosX_[1] -= 0.5f;
								efectPosX_[2] += 1.0f;
								efectPosX_[3] -= 1.0f;
								efectPosX_[4] += 0.1f;
								efectPosX_[5] -= 0.1f;
								efectPosX_[6] += 1.5f;
								efectPosX_[7] -= 1.5f;

								efectPosY_[i] -= efectVelocity_[i];
								efectVelocity_[i] -= efectAcceleration_[i];
							}
							if (Timer_[i] >= 15) {
								efectFlag_[i] = 0;
								Timer_[i] = 0;

							}

						}
						else {
							efectFlag_[i] = 1;
							saveFlag_ += 1;
							efectVelocity_[i] = (float(randSave[i]));
							efectTimer_ = 0;
							for (int y = 0; y < mapCountY; y++) {
								for (int x = 0; x < mapCountX; x++) {
									if (map0[y][x] == ENEMY) {
										efectPosX_[i] = (float(x * Size));
										efectPosY_[i] = (float(y * Size));
									}
								}
							}
						}
					}
				}
			}
		}


		// プレイヤー操作
		for (int y = 0; y < mapCountY; y++) {
			for (int x = 0; x < mapCountX; x++) {
				if (map0[y][x] == PLAYER) {
					if (shotFlag_ == 0) {

						shotPosX_ = x * Size;
						shotPosY_ = y * Size;
						savePlayerPosX_ = shotPosX_;
						savePlayerPosY_ = shotPosY_;
					}
				}

				if (judgeFlag_ == 1) {
					if (map0[y][x] == ENEMY) {
						for (int i = 0; i < 8; i++) {

							efectPosX_[i] = (float(x * Size));
							efectPosY_[i] = (float(y * Size));

						}
					}
				}
				//壁の判定

				//左
				if (shotMove_ == 1) {
					if (collisionFlag_ == 1) {
						if (map0[leftTopY_][leftTopX_] == WALL) {
							if (map0[rightTopY_][rightTopX_] == BACK || map0[rightTopY_][rightTopX_] == PLAYER) {
								setShotFlag_ = 1;
							}
							if (map0[rightTopY_][rightTopX_] == LEFT) {
								setShotFlag_ = 1;
							}
						}
						if (map0[leftTopY_][leftTopX_] == UP || map0[rightBottomY_][rightBottomX_] == DOWN ||
							map0[leftBottomY_][leftBottomX_] == RIGHT) {
							setShotFlag_ = 2;
						}
					}

					if (setShotFlag_ == 1) {
						shotFlag_ = 0;
						setShotFlag_ = 0;
					}
					if (setShotFlag_ == 2) {
						setShotFlag_ = 0;
					}

					if (map0[leftTopY_][leftTopX_] == WALL) {
						collisionFlag_ = 1;
					}
					else {
						collisionFlag_ = 0;

					}
				}

				//右
				if (shotMove_ == 2) {


					if (map0[rightTopY_][rightTopX_] == WALL) {
						collisionFlag_ = 1;
					}
					else {
						collisionFlag_ = 0;

					}

					if (collisionFlag_ == 1) {

						if (map0[leftTopY_][leftTopX_] == BACK && map0[leftBottomY_][leftBottomX_] == BACK || map0[leftTopY_][leftTopX_] == PLAYER) {
							setShotFlag_ = 1;
						}
						if (map0[leftTopY_][leftTopX_] == RIGHT) {
							setShotFlag_ = 1;
						}

						if (map0[rightTopY_][rightTopX_] == WALL && map0[rightBottomY_][rightBottomX_] == WALL &&
							map0[leftBottomY_][leftBottomX_] == WALL) {
							setShotFlag_ = 1;
						}

						if (map0[leftTopY_][leftTopX_] == UP || map0[leftBottomY_][leftBottomX_] == DOWN ||
							map0[leftBottomY_][leftBottomX_] == LEFT) {
							setShotFlag_ = 2;
						}
					}

					if (map0[rightTopY_][rightTopX_] == BACK && map0[rightBottomY_][rightBottomX_] == BACK &&
						map0[leftTopY_][leftTopX_] == BACK && map0[leftBottomY_][leftBottomX_] == BACK) {
						setShotFlag_ = 2;
					}
					if (setShotFlag_ == 1) {
						shotFlag_ = 0;
						setShotFlag_ = 0;
					}
					if (setShotFlag_ == 2) {
						setShotFlag_ = 0;
					}



				}

				//上
				if (shotMove_ == 3) {

					if (collisionFlag_ == 1) {
						if (map0[leftTopY_][leftTopX_] == WALL) {
							if (map0[leftBottomY_][leftBottomX_] == BACK || map0[leftBottomY_][leftBottomX_] == PLAYER) {
								setShotFlag_ = 1;
							}
							if (map0[leftBottomY_][leftBottomX_] == UP) {
								setShotFlag_ = 1;
							}
						}
						if (map0[leftTopY_][leftTopX_] == DOWN ||
							map0[leftTopY_][leftTopX_] == RIGHT || map0[leftTopY_][leftTopX_] == LEFT) {
							setShotFlag_ = 2;
						}

					}

					if (setShotFlag_ == 1) {
						shotFlag_ = 0;
						setShotFlag_ = 0;
					}
					if (setShotFlag_ == 2) {
						setShotFlag_ = 0;
					}

					if (map0[leftTopY_][leftTopX_] == WALL) {
						collisionFlag_ = 1;
					}
					else {
						collisionFlag_ = 0;
					}

				}

				//下
				if (shotMove_ == 4) {

					if (collisionFlag_ == 1) {
						if (map0[leftBottomY_][leftBottomX_] == WALL) {
							if (map0[leftTopY_][leftTopX_] == BACK || map0[leftTopY_][leftTopX_] == PLAYER || map0[rightTopY_][rightTopX_] == PLAYER) {
								setShotFlag_ = 1;
							}
							if (map0[leftTopY_][leftTopX_] == DOWN) {
								setShotFlag_ = 1;
							}
						}

						if (map0[leftTopY_][leftTopX_] == UP ||
							map0[leftTopY_][leftTopX_] == RIGHT || map0[leftTopY_][leftTopX_] == LEFT) {
							setShotFlag_ = 2;
						}
					}

					if (setShotFlag_ == 1) {
						shotFlag_ = 0;
						setShotFlag_ = 0;
					}
					if (setShotFlag_ == 2) {
						setShotFlag_ = 0;
					}

					if (map0[leftBottomY_][leftBottomX_] == WALL) {
						collisionFlag_ = 1;
					}
					else {
						collisionFlag_ = 0;

					}

				}

				//スライド
				if (shotMove_ == 1) {
					if (map0[rightBottomY_][rightBottomX_] == UP) {
						shotMove_ = 3;
					}

					if (map0[rightTopY_][rightTopX_] == RIGHT) {
						shotMove_ = 2;
					}

					if (map0[rightTopY_][rightTopX_] == LEFT) {
						shotMove_ = 1;
					}

					if (map0[rightBottomY_][rightBottomX_] == DOWN) {
						shotMove_ = 4;
					}
				}

				if (shotMove_ == 2) {
					if (map0[leftTopY_][leftTopX_] == UP) {
						shotMove_ = 3;
					}

					if (map0[leftTopY_][leftTopX_] == RIGHT) {
						shotMove_ = 2;
					}

					if (map0[leftTopY_][leftTopX_] == LEFT) {
						shotMove_ = 1;
					}

					if (map0[leftTopY_][leftTopX_] == DOWN) {
						shotMove_ = 4;
					}
				}

				if (shotMove_ == 3) {
					if (map0[leftBottomY_][leftBottomX_] == UP) {
						shotMove_ = 3;
					}

					if (map0[leftBottomY_][leftBottomX_] == RIGHT) {
						shotMove_ = 2;
					}

					if (map0[leftBottomY_][leftBottomX_] == LEFT) {
						shotMove_ = 1;
					}

					if (map0[leftBottomY_][leftBottomX_] == DOWN) {
						shotMove_ = 4;
					}
				}

				if (shotMove_ == 4) {

					if (map0[leftTopY_][leftTopX_] == UP) {
						shotMove_ = 3;
					}

					if (map0[leftTopY_][leftTopX_] == RIGHT) {
						shotMove_ = 2;
					}

					if (map0[leftTopY_][leftTopX_] == LEFT) {
						shotMove_ = 1;
					}
					if (map0[leftTopY_][leftTopX_] == DOWN) {
						shotMove_ = 4;
					}
				}

			}
		}
		if (shotFlag_ == 0) {
			//左ブロック
			if (mousePosX_ >= selectWX_[0] && mousePosX_ <= selectWX_[0] + selectWR_[0] &&
				mousePosY_ >= selectWY_[0] && mousePosY_ <= selectWY_[0] + selectWR_[0] && !isWall[0])
			{
				if (Novice::IsPlayingAudio(voiceHandle[6]) == 0 || voiceHandle[6] == -1)
				{
					voiceHandle[6] = Novice::PlayAudio(audioHandle[6], 0, 0.1f);
				}
				selectWColor_[0] = RED;
			}
			else
			{
				Novice::StopAudio(voiceHandle[6]);
				selectWColor_[0] = WHITE;
			}
			if (clickFlag_ == 0) {
				if (selectWColor_[0] == RED && Novice::IsPressMouse(0))
				{
					isWall[0] = true;
					clickFlag_ = 1;
				}
			}
			if (clickFlag_ == 1) {
				if (isWall[0])
				{
					selectWX_[0] = mousePosX_;
					selectWY_[0] = mousePosY_;
				}

				// マップとブロックの配置判定
				if (map0[leftTY[0]][leftTX[0]] == BACK && isWall[0] && selectWX_[0] <= 960)
				{
					backColor_[saveLeftTY[0]][saveLeftTX[0]] = WHITE;
					backColor_[leftTY[0]][leftTX[0]] = RED;
					saveLeftTX[0] = leftTX[0];
					saveLeftTY[0] = leftTY[0];
				}

				if (Novice::IsPressMouse(1) && backColor_[leftTY[0]][leftTX[0]] == RED && map0[leftTY[0]][leftTX[0]] == BACK)
				{
					if (Novice::IsPlayingAudio(voiceHandle[0]) == 0 || voiceHandle[0] == -1)
					{
						voiceHandle[0] = Novice::PlayAudio(audioHandle[0], 0, 0.1f);
					}
					map0[leftTY[0]][leftTX[0]] = LEFT;
					isWall[0] = false;
					clickFlag_ = 0;
					selectWX_[0] = 1085;
					selectWY_[0] = 165;
				}
			}
			//右ブロック
			if (mousePosX_ >= selectWX_[1] && mousePosX_ <= selectWX_[1] + selectWR_[1] &&
				mousePosY_ >= selectWY_[1] && mousePosY_ <= selectWY_[1] + selectWR_[1] && !isWall[1])
			{
				if (Novice::IsPlayingAudio(voiceHandle[7]) == 0 || voiceHandle[7] == -1)
				{
					voiceHandle[7] = Novice::PlayAudio(audioHandle[7], 0, 0.1f);
				}
				selectWColor_[1] = RED;
			}
			else
			{
				Novice::StopAudio(voiceHandle[7]);
				selectWColor_[1] = WHITE;
			}
			if (clickFlag_ == 0) {
				if (selectWColor_[1] == RED && Novice::IsPressMouse(0))
				{
					isWall[1] = true;
					clickFlag_ = 2;
				}
			}
			if (clickFlag_ == 2) {
				if (isWall[1])
				{
					selectWX_[1] = mousePosX_;
					selectWY_[1] = mousePosY_;
				}
				// マップとブロックの配置判定
				if (map0[leftTY[1]][leftTX[1]] == BACK && isWall[1] && selectWX_[1] <= 960)
				{
					backColor_[saveLeftTY[1]][saveLeftTX[1]] = WHITE;
					backColor_[leftTY[1]][leftTX[1]] = RED;
					saveLeftTX[1] = leftTX[1];
					saveLeftTY[1] = leftTY[1];
				}

				if (Novice::IsPressMouse(1) && backColor_[leftTY[1]][leftTX[1]] == RED && map0[leftTY[1]][leftTX[1]] == BACK)
				{
					if (Novice::IsPlayingAudio(voiceHandle[0]) == 0 || voiceHandle[0] == -1)
					{
						voiceHandle[0] = Novice::PlayAudio(audioHandle[0], 0, 0.1f);
					}
					map0[leftTY[1]][leftTX[1]] = RIGHT;
					isWall[1] = false;
					clickFlag_ = 0;
					selectWX_[1] = 1085;
					selectWY_[1] = 330;
				}

			}
			//下ブロック
			if (mousePosX_ >= selectWX_[2] && mousePosX_ <= selectWX_[2] + selectWR_[2] &&
				mousePosY_ >= selectWY_[2] && mousePosY_ <= selectWY_[2] + selectWR_[2] && !isWall[2])
			{
				if (Novice::IsPlayingAudio(voiceHandle[8]) == 0 || voiceHandle[8] == -1)
				{
					voiceHandle[8] = Novice::PlayAudio(audioHandle[8], 0, 0.1f);
				}
				selectWColor_[2] = RED;
			}
			else
			{
				Novice::StopAudio(voiceHandle[8]);
				selectWColor_[2] = WHITE;
			}
			if (clickFlag_ == 0) {
				if (selectWColor_[2] == RED && Novice::IsPressMouse(0))
				{
					isWall[2] = true;
					clickFlag_ = 3;
				}
			}
			if (clickFlag_ == 3) {
				if (isWall[2])
				{
					selectWX_[2] = mousePosX_;
					selectWY_[2] = mousePosY_;
				}
				// マップとブロックの配置判定
				if (map0[leftTY[2]][leftTX[2]] == BACK && isWall[2] && selectWX_[2] <= 960)
				{
					backColor_[saveLeftTY[2]][saveLeftTX[2]] = WHITE;
					backColor_[leftTY[2]][leftTX[2]] = RED;
					saveLeftTX[2] = leftTX[2];
					saveLeftTY[2] = leftTY[2];
				}

				if (Novice::IsPressMouse(1) && backColor_[leftTY[2]][leftTX[2]] == RED && map0[leftTY[2]][leftTX[2]] == BACK)
				{
					if (Novice::IsPlayingAudio(voiceHandle[0]) == 0 || voiceHandle[0] == -1)
					{
						voiceHandle[0] = Novice::PlayAudio(audioHandle[0], 0, 0.1f);
					}
					map0[leftTY[2]][leftTX[2]] = DOWN;
					isWall[2] = false;
					clickFlag_ = 0;
					selectWX_[2] = 1085;
					selectWY_[2] = 485;
				}
			}
			//上ブロック
			if (mousePosX_ >= selectWX_[3] && mousePosX_ <= selectWX_[3] + selectWR_[3] &&
				mousePosY_ >= selectWY_[3] && mousePosY_ <= selectWY_[3] + selectWR_[3] && !isWall[3])
			{
				if (Novice::IsPlayingAudio(voiceHandle[9]) == 0 || voiceHandle[9] == -1)
				{
					voiceHandle[9] = Novice::PlayAudio(audioHandle[9], 0, 0.1f);
				}
				selectWColor_[3] = RED;
			}
			else
			{
				Novice::StopAudio(voiceHandle[9]);
				selectWColor_[3] = WHITE;
			}
			if (clickFlag_ == 0) {
				if (selectWColor_[3] == RED && Novice::IsPressMouse(0))
				{
					isWall[3] = true;
					clickFlag_ = 4;
				}
			}
			if (clickFlag_ == 4) {
				if (isWall[3])
				{
					selectWX_[3] = mousePosX_;
					selectWY_[3] = mousePosY_;
				}
				// マップとブロックの配置判定
				if (map0[leftTY[3]][leftTX[3]] == BACK && isWall[3] && selectWX_[3] <= 960)
				{
					backColor_[saveLeftTY[3]][saveLeftTX[3]] = WHITE;
					backColor_[leftTY[3]][leftTX[3]] = RED;
					saveLeftTX[3] = leftTX[3];
					saveLeftTY[3] = leftTY[3];
				}

				if (Novice::IsPressMouse(1) && backColor_[leftTY[3]][leftTX[3]] == RED && map0[leftTY[3]][leftTX[3]] == BACK)
				{
					if (Novice::IsPlayingAudio(voiceHandle[0]) == 0 || voiceHandle[0] == -1)
					{
						voiceHandle[0] = Novice::PlayAudio(audioHandle[0], 0, 0.1f);
					}
					map0[leftTY[3]][leftTX[3]] = UP;
					isWall[3] = false;
					clickFlag_ = 0;
					selectWX_[3] = 1085;
					selectWY_[3] = 650;
				}
			}
		}
	}

	// ステージ2
	if (stageNo == STAGE2)
	{
		
		// 弾操作
		if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0 && shotFlag_ == 0) {
			shotFlag_ = 1;
			if (Novice::IsPlayingAudio(voiceHandle[3]) == 0 || voiceHandle[3] == -1)
			{
				voiceHandle[3] = Novice::PlayAudio(audioHandle[3], 0, 0.1f);
			}
		}
		if (shotFlag_ == 0) {
			Novice::StopAudio(voiceHandle[3]);
		}
		if (switch_ == 0) {
			switchTimer += 1;
			if (switchTimer == 160) {
				flagIn_ = true;
				if (Novice::IsPlayingAudio(voiceHandle[10]) == 0 || voiceHandle[10] == -1)
				{
					voiceHandle[10] = Novice::PlayAudio(audioHandle[10], 0, 0.1f);
				}
			}

			// イージング
			if (flagIn_)
			{
				flame_++;
				if (flame_ >= endFlame_)
				{
					flame_ = endFlame_;
				}

				t_ = flame_ / endFlame_;
				menu_.easing.y = easeOutElastic(t_);
				menu_.vel.y = menu_.easing.y * distance_;
				menu_.pos.y = menu_.vel.y + (-240);
			}

			if (keys[DIK_C] && !flagIn_)
			{
				flagOut_ = true;
			}
			if (flagOut_)
			{
				flame_--;
				t_ = flame_ / endFlame_;
				menu_.easing.y = easeInOutBack(t_);
				menu_.vel.y = menu_.easing.y * distance_;
				menu_.pos.y = menu_.vel.y + (-240);
			}

			if (flame_ >= endFlame_ && flagIn_)
			{
				flagIn_ = false;
			}

			if (flame_ <= 0 && flagOut_)
			{
				flagOut_ = false;
				switchTimer = 0;
				switch_ = 1;
			}
		}

		if (switch_ == 1) {
			if (map1[leftTopY_][leftTopX_] == ENEMY || map1[rightTopY_][rightTopX_] == ENEMY) {
				judgeFlag_ = 1;
				deadFlag_ = 1;
				shotFlag_ = 0;
				shakeFlag_ = 1;
			}
			else {
				judgeFlag_ = 0;
			}
			//シェイク
			if (shakeFlag_ == 1) {
				if (Novice::IsPlayingAudio(voiceHandle[1]) == 0 || voiceHandle[1] == -1)
				{
					voiceHandle[1] = Novice::PlayAudio(audioHandle[1], 0, 0.1f);
				}
				shakeRandX_ = update_;
				shakeRandX_ = rand() % shakeRandX_ - 12;
				shakeRandY_ = update_;
				shakeRandY_ = rand() % shakeRandY_ - 12;
				if (saveFlag_ == 25) {
					Novice::StopAudio(voiceHandle[1]);
					saveShake_ = 1;
					a += 1;
					if (a == 5) {
						update_ -= 1;
						a = 0;
					}
				}
				if (update_ <= 0) {
					if (Novice::IsPlayingAudio(voiceHandle[2]) == 0 || voiceHandle[2] == -1)
					{
						voiceHandle[2] = Novice::PlayAudio(audioHandle[2], 0, 0.1f);
					}
					saveShake_ = 0;
					shakeFlag_ = 2;
					update_ = 24;
				}
			}
			if (shakeFlag_ == 2) {
				enemyColor -= 3;
				for (int i = 0; i < 8; i++) {
					if (efectTimer_ >= 50) {
						if (efectFlag_[i] == 1) {

							if (Timer_[i] <= 3000) {
								Timer_[i] += 1;
								efectPosX_[0] += 0.5f;
								efectPosX_[1] -= 0.5f;
								efectPosY_[2] += 0.5f;
								efectPosY_[3] -= 0.5f;

								efectPosX_[4] += 0.5f;
								efectPosY_[4] += 0.5f;
								efectPosX_[5] -= 0.5f;
								efectPosY_[5] -= 0.5f;
								efectPosX_[6] -= 0.5f;
								efectPosY_[6] += 0.5f;
								efectPosX_[7] += 0.5f;
								efectPosY_[7] -= 0.5f;
							}
							if (Timer_[i] >= 3000) {
								efectFlag_[i] = 0;
								Timer_[i] = 0;

							}
						}
						else {
							efectFlag_[i] = 1;
							//efectTimer_ = 0;
							for (int y = 0; y < mapCountY; y++) {
								for (int x = 0; x < mapCountX; x++) {
									if (map1[y][x] == ENEMY) {
										efectPosX_[i] = (float(x * Size));
										efectPosY_[i] = (float(y * Size));
									}
								}
							}
						}
					}
				}
				if (enemyColor <= -255) {
					Novice::StopAudio(voiceHandle[2]);
					enemyColor = -255;
					shakeFlag_ = 3;
				}
			}

			if (shakeFlag_ == 3) {
				deadFlag_ = 2;
				shakeFlag_ = 0;
			}

			//エフェクト
			for (int i = 0; i < 8; i++) {
				randSave[0] = rand() % 4 + 1;
				randSave[1] = rand() % 4 + 1;
				randSave[2] = rand() % 4 + 1;
				randSave[3] = rand() % 4 + 1;
				randSave[4] = rand() % 7 + 5;
				randSave[5] = rand() % 7 + 5;
				randSave[6] = rand() % 7 + 5;
				randSave[7] = rand() % 7 + 5;
				if (deadFlag_ == 1) {
					if (efectTimer_ <= 50) {
						efectTimer_ += 1;

						if (efectTimer_ >= 51) {
							efectTimer_ -= 1;
						}
					}
					if (efectTimer_ == 50) {

						if (saveFlag_ <= 24) {
							if (efectFlag_[i] == 1) {


								if (Timer_[i] <= 15) {
									Timer_[i] += 1;
									efectPosX_[0] += 0.5f;
									efectPosX_[1] -= 0.5f;
									efectPosX_[2] += 1.0f;
									efectPosX_[3] -= 1.0f;
									efectPosX_[4] += 0.1f;
									efectPosX_[5] -= 0.1f;
									efectPosX_[6] += 1.5f;
									efectPosX_[7] -= 1.5f;

									efectPosY_[i] -= efectVelocity_[i];
									efectVelocity_[i] -= efectAcceleration_[i];
								}
								if (Timer_[i] >= 15) {
									efectFlag_[i] = 0;
									Timer_[i] = 0;

								}


							}
							else {
								efectFlag_[i] = 1;
								saveFlag_ += 1;
								efectVelocity_[i] = (float(randSave[i]));
								efectTimer_ = 0;
								for (int y = 0; y < mapCountY; y++) {
									for (int x = 0; x < mapCountX; x++) {
										if (map1[y][x] == ENEMY) {
											efectPosX_[i] = (float(x * Size));
											efectPosY_[i] = (float(y * Size));
										}
									}
								}
							}
						}
					}
				}
			}
			// プレイヤー操作
			for (int y = 0; y < mapCountY; y++) {
				for (int x = 0; x < mapCountX; x++) {
					if (map1[y][x] == PLAYER) {
						if (shotFlag_ == 0) {

							shotPosX_ = x * Size;
							shotPosY_ = y * Size;
							savePlayerPosX_ = shotPosX_;
							savePlayerPosY_ = shotPosY_;

						}
					}
					//壁の判定

					if (switchFlag_ == 1) {
						if (map1[y][x] == DOOR) {
							map1[y][x] = BACK;
						}
					}
					if (map1[leftBottomY_][leftBottomX_] == DOOR) {
						shotFlag_ = 0;
					}
					//左
					if (shotMove_ == 1) {
						if (collisionFlag_ == 1) {
							if (map1[leftTopY_][leftTopX_] == WALL) {
								if (map1[rightTopY_][rightTopX_] == BACK || map0[rightTopY_][rightTopX_] == PLAYER) {
									setShotFlag_ = 1;
								}
								if (map1[rightTopY_][rightTopX_] == LEFT) {
									setShotFlag_ = 1;
								}
							}
							if (map1[leftTopY_][leftTopX_] == UP || map1[rightBottomY_][rightBottomX_] == DOWN ||
								map1[leftBottomY_][leftBottomX_] == RIGHT) {
								setShotFlag_ = 2;
							}
						}

						if (setShotFlag_ == 1) {
							shotFlag_ = 0;
							setShotFlag_ = 0;
						}
						if (setShotFlag_ == 2) {
							setShotFlag_ = 0;
						}

						if (map1[leftTopY_][leftTopX_] == WALL) {
							collisionFlag_ = 1;
						}
						else {
							collisionFlag_ = 0;

						}
					}

					//右
					if (shotMove_ == 2) {
						if (map1[rightBottomY_][rightBottomX_] == WARPPOINT1 || map1[rightTopY_][rightTopX_] == WARPPOINT1) {
							if (map1[y][x] == WARPPOINT2) {

								shotPosX_ = x * Size;
								shotPosY_ = y * Size;
							}
						}

						if (map1[rightTopY_][rightTopX_] == WALL) {
							collisionFlag_ = 1;
						}
						else {
							collisionFlag_ = 0;

						}

						if (collisionFlag_ == 1) {

							if (map1[leftTopY_][leftTopX_] == BACK && map1[leftBottomY_][leftBottomX_] == BACK || map0[leftTopY_][leftTopX_] == PLAYER) {
								setShotFlag_ = 1;
							}
							if (map1[leftTopY_][leftTopX_] == RIGHT) {
								setShotFlag_ = 1;
							}

							if (map1[rightTopY_][rightTopX_] == WALL && map1[rightBottomY_][rightBottomX_] == WALL &&
								map1[leftBottomY_][leftBottomX_] == WALL) {
								setShotFlag_ = 1;
							}

							if (map1[leftTopY_][leftTopX_] == UP || map1[leftBottomY_][leftBottomX_] == DOWN ||
								map1[leftBottomY_][leftBottomX_] == LEFT) {
								setShotFlag_ = 2;
							}
						}

						if (map1[rightTopY_][rightTopX_] == BACK && map1[rightBottomY_][rightBottomX_] == BACK &&
							map1[leftTopY_][leftTopX_] == BACK && map1[leftBottomY_][leftBottomX_] == BACK) {
							setShotFlag_ = 2;
						}
						if (setShotFlag_ == 1) {
							shotFlag_ = 0;
							setShotFlag_ = 0;
						}
						if (setShotFlag_ == 2) {
							setShotFlag_ = 0;
						}
					}

					//上
					if (shotMove_ == 3) {
						if (map1[leftTopY_][leftTopX_] == WARPPOINT2) {
							shotFlag_ = 0;
						}
						if (collisionFlag_ == 1) {
							if (map1[leftTopY_][leftTopX_] == WALL) {
								if (map1[leftBottomY_][leftBottomX_] == BACK || map1[leftBottomY_][leftBottomX_] == PLAYER) {
									setShotFlag_ = 1;
								}
								if (map1[leftBottomY_][leftBottomX_] == UP) {
									setShotFlag_ = 1;
								}
							}
							if (map1[leftTopY_][leftTopX_] == DOWN ||
								map1[leftTopY_][leftTopX_] == RIGHT || map1[leftTopY_][leftTopX_] == LEFT) {
								setShotFlag_ = 2;
							}

						}

						if (setShotFlag_ == 1) {
							shotFlag_ = 0;
							setShotFlag_ = 0;
						}
						if (setShotFlag_ == 2) {
							setShotFlag_ = 0;
						}

						if (map1[leftTopY_][leftTopX_] == WALL) {
							collisionFlag_ = 1;
						}
						else {
							collisionFlag_ = 0;
						}

					}

					//下
					if (shotMove_ == 4) {
						if (map1[leftBottomY_][leftBottomX_] == WARPPOINT1) {
							if (map1[y][x] == WARPPOINT2) {

								shotPosX_ = x * Size;
								shotPosY_ = y * Size;
							}
						}

						if (map1[leftBottomY_][leftBottomX_] == SWITCH1) {
							//shotFlag_ = 0;
							switchFlag_ = 1;
							if (Novice::IsPlayingAudio(voiceHandle[5]) == 0 || voiceHandle[5] == -1)
							{
								voiceHandle[5] = Novice::PlayAudio(audioHandle[5], 0, 0.1f);
							}
							if (map1[y][x] == SWITCH1) {
								map1[y][x] = SWITCH2;
							}

						}

						if (collisionFlag_ == 1) {
							if (map1[leftBottomY_][leftBottomX_] == WALL) {
								if (map1[leftTopY_][leftTopX_] == BACK || map1[leftTopY_][leftTopX_] == PLAYER || map1[rightTopY_][rightTopX_] == PLAYER) {
									setShotFlag_ = 1;
								}
								if (map1[leftTopY_][leftTopX_] == DOWN) {
									setShotFlag_ = 1;
								}
							}

							if (map1[leftTopY_][leftTopX_] == UP ||
								map1[leftTopY_][leftTopX_] == RIGHT || map1[leftTopY_][leftTopX_] == LEFT) {
								setShotFlag_ = 2;
							}
						}

						if (setShotFlag_ == 1) {
							shotFlag_ = 0;
							setShotFlag_ = 0;
						}
						if (setShotFlag_ == 2) {
							setShotFlag_ = 0;
						}

						if (map1[leftBottomY_][leftBottomX_] == WALL) {
							collisionFlag_ = 1;
						}
						else {
							collisionFlag_ = 0;

						}

					}

					//スライド
					if (shotMove_ == 1) {
						if (map1[rightBottomY_][rightBottomX_] == UP) {
							shotMove_ = 3;
						}

						if (map1[rightTopY_][rightTopX_] == RIGHT) {
							shotMove_ = 2;
						}

						if (map1[rightTopY_][rightTopX_] == LEFT) {
							shotMove_ = 1;
						}

						if (map1[rightBottomY_][rightBottomX_] == DOWN) {
							shotMove_ = 4;
						}
					}

					if (shotMove_ == 2) {
						if (map1[leftTopY_][leftTopX_] == UP) {
							shotMove_ = 3;
						}

						if (map1[leftTopY_][leftTopX_] == RIGHT) {
							shotMove_ = 2;
						}

						if (map1[leftTopY_][leftTopX_] == LEFT) {
							shotMove_ = 1;
						}

						if (map1[leftTopY_][leftTopX_] == DOWN) {
							shotMove_ = 4;
						}
					}

					if (shotMove_ == 3) {
						if (map1[leftBottomY_][leftBottomX_] == UP) {
							shotMove_ = 3;
						}

						if (map1[leftBottomY_][leftBottomX_] == RIGHT) {
							shotMove_ = 2;
						}

						if (map1[leftBottomY_][leftBottomX_] == LEFT) {
							shotMove_ = 1;
						}

						if (map1[leftBottomY_][leftBottomX_] == DOWN) {
							shotMove_ = 4;
						}
					}

					if (shotMove_ == 4) {

						if (map1[leftTopY_][leftTopX_] == UP) {
							shotMove_ = 3;
						}

						if (map1[leftTopY_][leftTopX_] == RIGHT) {
							shotMove_ = 2;
						}

						if (map1[leftTopY_][leftTopX_] == LEFT) {
							shotMove_ = 1;
						}
						if (map1[leftTopY_][leftTopX_] == DOWN) {
							shotMove_ = 4;
						}
					}

				}
			}
			if (shotFlag_ == 0) {
				//左ブロック
				if (mousePosX_ >= selectWX_[0] && mousePosX_ <= selectWX_[0] + selectWR_[0] &&
					mousePosY_ >= selectWY_[0] && mousePosY_ <= selectWY_[0] + selectWR_[0] && !isWall[0])
				{
					if (Novice::IsPlayingAudio(voiceHandle[6]) == 0 || voiceHandle[6] == -1)
					{
						voiceHandle[6] = Novice::PlayAudio(audioHandle[6], 0, 0.1f);
					}
					selectWColor_[0] = RED;
				}
				else
				{
					Novice::StopAudio(voiceHandle[6]);
					selectWColor_[0] = WHITE;
				}
				if (clickFlag_ == 0) {
					if (selectWColor_[0] == RED && Novice::IsPressMouse(0))
					{
						isWall[0] = true;
						clickFlag_ = 1;
					}
				}
				if (clickFlag_ == 1) {
					if (isWall[0])
					{
						selectWX_[0] = mousePosX_;
						selectWY_[0] = mousePosY_;
					}

					// マップとブロックの配置判定
					if (map1[leftTY[0]][leftTX[0]] == BACK && isWall[0] && selectWX_[0] <= 960)
					{
						backColor_[saveLeftTY[0]][saveLeftTX[0]] = WHITE;
						backColor_[leftTY[0]][leftTX[0]] = RED;
						saveLeftTX[0] = leftTX[0];
						saveLeftTY[0] = leftTY[0];
					}

					if (Novice::IsPressMouse(1) && backColor_[leftTY[0]][leftTX[0]] == RED && map1[leftTY[0]][leftTX[0]] == BACK)
					{
						if (Novice::IsPlayingAudio(voiceHandle[0]) == 0 || voiceHandle[0] == -1)
						{
							voiceHandle[0] = Novice::PlayAudio(audioHandle[0], 0, 0.1f);
						}
						map1[leftTY[0]][leftTX[0]] = LEFT;
						isWall[0] = false;
						clickFlag_ = 0;
						selectWX_[0] = 1085;
						selectWY_[0] = 165;
					}
				}
				//右ブロック
				if (mousePosX_ >= selectWX_[1] && mousePosX_ <= selectWX_[1] + selectWR_[1] &&
					mousePosY_ >= selectWY_[1] && mousePosY_ <= selectWY_[1] + selectWR_[1] && !isWall[1])
				{
					if (Novice::IsPlayingAudio(voiceHandle[7]) == 0 || voiceHandle[7] == -1)
					{
						voiceHandle[7] = Novice::PlayAudio(audioHandle[7], 0, 0.1f);
					}
					selectWColor_[1] = RED;
				}
				else
				{
					Novice::StopAudio(voiceHandle[7]);
					selectWColor_[1] = WHITE;
				}
				if (clickFlag_ == 0) {
					if (selectWColor_[1] == RED && Novice::IsPressMouse(0))
					{
						isWall[1] = true;
						clickFlag_ = 2;
					}
				}
				if (clickFlag_ == 2) {
					if (isWall[1])
					{
						selectWX_[1] = mousePosX_;
						selectWY_[1] = mousePosY_;
					}
					// マップとブロックの配置判定
					if (map1[leftTY[1]][leftTX[1]] == BACK && isWall[1] && selectWX_[1] <= 960)
					{
						backColor_[saveLeftTY[1]][saveLeftTX[1]] = WHITE;
						backColor_[leftTY[1]][leftTX[1]] = RED;
						saveLeftTX[1] = leftTX[1];
						saveLeftTY[1] = leftTY[1];
					}

					if (Novice::IsPressMouse(1) && backColor_[leftTY[1]][leftTX[1]] == RED && map1[leftTY[1]][leftTX[1]] == BACK)
					{
						if (Novice::IsPlayingAudio(voiceHandle[0]) == 0 || voiceHandle[0] == -1)
						{
							voiceHandle[0] = Novice::PlayAudio(audioHandle[0], 0, 0.1f);
						}
						map1[leftTY[1]][leftTX[1]] = RIGHT;
						isWall[1] = false;
						clickFlag_ = 0;
						selectWX_[1] = 1085;
						selectWY_[1] = 330;
					}

				}
				//下ブロック
				if (mousePosX_ >= selectWX_[2] && mousePosX_ <= selectWX_[2] + selectWR_[2] &&
					mousePosY_ >= selectWY_[2] && mousePosY_ <= selectWY_[2] + selectWR_[2] && !isWall[2])
				{
					if (Novice::IsPlayingAudio(voiceHandle[8]) == 0 || voiceHandle[8] == -1)
					{
						voiceHandle[8] = Novice::PlayAudio(audioHandle[8], 0, 0.1f);
					}
					selectWColor_[2] = RED;
				}
				else
				{
					Novice::StopAudio(voiceHandle[8]);
					selectWColor_[2] = WHITE;
				}
				if (clickFlag_ == 0) {
					if (selectWColor_[2] == RED && Novice::IsPressMouse(0))
					{
						isWall[2] = true;
						clickFlag_ = 3;
					}
				}
				if (clickFlag_ == 3) {
					if (isWall[2])
					{
						selectWX_[2] = mousePosX_;
						selectWY_[2] = mousePosY_;
					}
					// マップとブロックの配置判定
					if (map1[leftTY[2]][leftTX[2]] == BACK && isWall[2] && selectWX_[2] <= 960)
					{
						backColor_[saveLeftTY[2]][saveLeftTX[2]] = WHITE;
						backColor_[leftTY[2]][leftTX[2]] = RED;
						saveLeftTX[2] = leftTX[2];
						saveLeftTY[2] = leftTY[2];
					}

					if (Novice::IsPressMouse(1) && backColor_[leftTY[2]][leftTX[2]] == RED && map1[leftTY[2]][leftTX[2]] == BACK)
					{
						if (Novice::IsPlayingAudio(voiceHandle[0]) == 0 || voiceHandle[0] == -1)
						{
							voiceHandle[0] = Novice::PlayAudio(audioHandle[0], 0, 0.1f);
						}
						map1[leftTY[2]][leftTX[2]] = DOWN;
						isWall[2] = false;
						clickFlag_ = 0;
						selectWX_[2] = 1085;
						selectWY_[2] = 485;
					}
				}
				//上ブロック
				if (mousePosX_ >= selectWX_[3] && mousePosX_ <= selectWX_[3] + selectWR_[3] &&
					mousePosY_ >= selectWY_[3] && mousePosY_ <= selectWY_[3] + selectWR_[3] && !isWall[3])
				{
					if (Novice::IsPlayingAudio(voiceHandle[9]) == 0 || voiceHandle[9] == -1)
					{
						voiceHandle[9] = Novice::PlayAudio(audioHandle[9], 0, 0.1f);
					}
					selectWColor_[3] = RED;
				}
				else
				{
					Novice::StopAudio(voiceHandle[9]);
					selectWColor_[3] = WHITE;
				}
				if (clickFlag_ == 0) {
					if (selectWColor_[3] == RED && Novice::IsPressMouse(0))
					{
						isWall[3] = true;
						clickFlag_ = 4;
					}
				}
				if (clickFlag_ == 4) {
					if (isWall[3])
					{
						selectWX_[3] = mousePosX_;
						selectWY_[3] = mousePosY_;
					}
					// マップとブロックの配置判定
					if (map1[leftTY[3]][leftTX[3]] == BACK && isWall[3] && selectWX_[3] <= 960)
					{
						backColor_[saveLeftTY[3]][saveLeftTX[3]] = WHITE;
						backColor_[leftTY[3]][leftTX[3]] = RED;
						saveLeftTX[3] = leftTX[3];
						saveLeftTY[3] = leftTY[3];
					}

					if (Novice::IsPressMouse(1) && backColor_[leftTY[3]][leftTX[3]] == RED && map1[leftTY[3]][leftTX[3]] == BACK)
					{
						if (Novice::IsPlayingAudio(voiceHandle[0]) == 0 || voiceHandle[0] == -1)
						{
							voiceHandle[0] = Novice::PlayAudio(audioHandle[0], 0, 0.1f);
						}
						map1[leftTY[3]][leftTX[3]] = UP;
						isWall[3] = false;
						clickFlag_ = 0;
						selectWX_[3] = 1085;
						selectWY_[3] = 650;
					}
				}
			}
		}
	}

	// ステージ3
	if (stageNo == STAGE3)
	{
		// 弾操作
		if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0 && shotFlag_ == 0) {
			shotFlag_ = 1;
			if (Novice::IsPlayingAudio(voiceHandle[3]) == 0 || voiceHandle[3] == -1)
			{
				voiceHandle[3] = Novice::PlayAudio(audioHandle[3], 0, 0.1f);
			}
		}
		if (shotFlag_ == 0) {
			Novice::StopAudio(voiceHandle[3]);
		}

		if (warpFlag == 0) {
			warpTimer += 1;
			if (warpTimer == 160) {
				if (Novice::IsPlayingAudio(voiceHandle[10]) == 0 || voiceHandle[10] == -1)
				{
					voiceHandle[10] = Novice::PlayAudio(audioHandle[10], 0, 0.1f);
				}
				flagIn_ = true;
			}

			// イージング
			if (flagIn_)
			{
				flame_++;
				if (flame_ >= endFlame_)
				{
					flame_ = endFlame_;
				}

				t_ = flame_ / endFlame_;
				menu_.easing.y = easeOutElastic(t_);
				menu_.vel.y = menu_.easing.y * distance_;
				menu_.pos.y = menu_.vel.y + (-240);
			}

			if (keys[DIK_C] && !flagIn_)
			{
				flagOut_ = true;
			}
			if (flagOut_)
			{
				flame_--;
				t_ = flame_ / endFlame_;
				menu_.easing.y = easeInOutBack(t_);
				menu_.vel.y = menu_.easing.y * distance_;
				menu_.pos.y = menu_.vel.y + (-240);
			}

			if (flame_ >= endFlame_ && flagIn_)
			{
				flagIn_ = false;
			}

			if (flame_ <= 0 && flagOut_)
			{
				flagOut_ = false;
				warpFlag = 1;
				warpTimer = 0;
			}
		}

		if (warpFlag == 1) {
			if (map2[leftTopY_][leftTopX_] == ENEMY || map2[rightTopY_][rightTopX_] == ENEMY) {
				judgeFlag_ = 1;
				deadFlag_ = 1;
				shotFlag_ = 0;
				shakeFlag_ = 1;
			}
			else {
				judgeFlag_ = 0;
			}

			if (shakeFlag_ == 1) {
				if (Novice::IsPlayingAudio(voiceHandle[1]) == 0 || voiceHandle[1] == -1)
				{
					voiceHandle[1] = Novice::PlayAudio(audioHandle[1], 0, 0.1f);
				}
				shakeRandX_ = update_;
				shakeRandX_ = rand() % shakeRandX_ - 12;
				shakeRandY_ = update_;
				shakeRandY_ = rand() % shakeRandY_ - 12;
				if (saveFlag_ == 25) {
					Novice::StopAudio(voiceHandle[1]);
					saveShake_ = 1;
					a += 1;
					if (a == 5) {
						update_ -= 1;
						a = 0;
					}
				}
				if (update_ <= 0) {
					if (Novice::IsPlayingAudio(voiceHandle[2]) == 0 || voiceHandle[2] == -1)
					{
						voiceHandle[2] = Novice::PlayAudio(audioHandle[2], 0, 0.1f);
					}
					saveShake_ = 0;
					shakeFlag_ = 2;
					update_ = 24;
				}
			}
			if (shakeFlag_ == 2) {
				enemyColor -= 3;
				for (int i = 0; i < 8; i++) {
					if (efectTimer_ >= 50) {
						if (efectFlag_[i] == 1) {

							if (Timer_[i] <= 3000) {
								Timer_[i] += 1;
								efectPosX_[0] += 0.5f;
								efectPosX_[1] -= 0.5f;
								efectPosY_[2] += 0.5f;
								efectPosY_[3] -= 0.5f;

								efectPosX_[4] += 0.5f;
								efectPosY_[4] += 0.5f;
								efectPosX_[5] -= 0.5f;
								efectPosY_[5] -= 0.5f;
								efectPosX_[6] -= 0.5f;
								efectPosY_[6] += 0.5f;
								efectPosX_[7] += 0.5f;
								efectPosY_[7] -= 0.5f;
							}
							if (Timer_[i] >= 3000) {
								efectFlag_[i] = 0;
								Timer_[i] = 0;

							}
						}
						else {
							efectFlag_[i] = 1;
							//efectTimer_ = 0;
							for (int y = 0; y < mapCountY; y++) {
								for (int x = 0; x < mapCountX; x++) {
									if (map2[y][x] == ENEMY) {
										efectPosX_[i] = (float(x * Size));
										efectPosY_[i] = (float(y * Size));
									}
								}
							}
						}
					}
				}
				if (enemyColor <= -255) {
					Novice::StopAudio(voiceHandle[2]);
					enemyColor = -255;
					shakeFlag_ = 3;
				}
			}

			if (shakeFlag_ == 3) {
				deadFlag_ = 2;
				shakeFlag_ = 0;
			}

			//エフェクト
			for (int i = 0; i < 8; i++) {
				randSave[0] = rand() % 4 + 1;
				randSave[1] = rand() % 4 + 1;
				randSave[2] = rand() % 4 + 1;
				randSave[3] = rand() % 4 + 1;
				randSave[4] = rand() % 7 + 5;
				randSave[5] = rand() % 7 + 5;
				randSave[6] = rand() % 7 + 5;
				randSave[7] = rand() % 7 + 5;
				if (deadFlag_ == 1) {
					if (efectTimer_ <= 50) {
						efectTimer_ += 1;

						if (efectTimer_ >= 51) {
							efectTimer_ -= 1;
						}
					}
					if (efectTimer_ == 50) {

						if (saveFlag_ <= 24) {
							if (efectFlag_[i] == 1) {


								if (Timer_[i] <= 15) {
									Timer_[i] += 1;
									efectPosX_[0] += 0.5f;
									efectPosX_[1] -= 0.5f;
									efectPosX_[2] += 1.0f;
									efectPosX_[3] -= 1.0f;
									efectPosX_[4] += 0.1f;
									efectPosX_[5] -= 0.1f;
									efectPosX_[6] += 1.5f;
									efectPosX_[7] -= 1.5f;

									efectPosY_[i] -= efectVelocity_[i];
									efectVelocity_[i] -= efectAcceleration_[i];
								}
								if (Timer_[i] >= 15) {
									efectFlag_[i] = 0;
									Timer_[i] = 0;

								}


							}
							else {
								efectFlag_[i] = 1;
								saveFlag_ += 1;
								efectVelocity_[i] = (float(randSave[i]));
								efectTimer_ = 0;
								for (int y = 0; y < mapCountY; y++) {
									for (int x = 0; x < mapCountX; x++) {
										if (map2[y][x] == ENEMY) {
											efectPosX_[i] = (float(x * Size));
											efectPosY_[i] = (float(y * Size));
										}
									}
								}
							}
						}
					}
				}
			}

			// プレイヤー操作
			for (int y = 0; y < mapCountY; y++) {
				for (int x = 0; x < mapCountX; x++) {
					if (map2[y][x] == PLAYER) {
						if (shotFlag_ == 0) {

							shotPosX_ = x * Size;
							shotPosY_ = y * Size;
							savePlayerPosX_ = shotPosX_;
							savePlayerPosY_ = shotPosY_;
						}
					}
					//壁の判定

					if (switchFlag_ == 1) {
						if (map2[y][x] == DOOR2) {
							map2[y][x] = WALL;
						}
					}
					if (switchFlag_ == 3) {
						if (map2[y][x] == DOOR) {
							map2[y][x] = BACK;
						}
						if (map2[y][x] == WARPPOINT2) {
							map2[y][x] = WARPPOINT3;
						}
					}
					//左
					if (shotMove_ == 1) {
						if (map2[leftBottomY_][leftBottomX_] == DOOR) {
							shotFlag_ = 0;
						}
						if (map2[leftBottomY_][leftBottomX_] == SWITCH1) {
							shotFlag_ = 0;
							if (Novice::IsPlayingAudio(voiceHandle[5]) == 0 || voiceHandle[5] == -1)
							{
								voiceHandle[5] = Novice::PlayAudio(audioHandle[5], 0, 0.1f);
							}

							if (switchFlag_ == 2 || switchFlag_ == 3) {
								switchFlag_ = 3;
							}
							else
							{
								switchFlag_ = 1;
							}
							if (map2[y][x] == SWITCH1) {
								map2[y][x] = SWITCH2;
							}

						}
						if (map2[leftBottomY_][leftBottomX_] == SWITCH3) {
							shotFlag_ = 0;
							switchFlag_ = 2;
							if (Novice::IsPlayingAudio(voiceHandle[5]) == 0 || voiceHandle[5] == -1)
							{
								voiceHandle[5] = Novice::PlayAudio(audioHandle[5], 0, 0.1f);
							}
							if (map2[y][x] == SWITCH3) {
								map2[y][x] = SWITCH4;
							}

						}
						if (map2[rightBottomY_][rightBottomX_] == WARPPOINT3) {
							if (Novice::IsPlayingAudio(voiceHandle[4]) == 0 || voiceHandle[4] == -1)
							{
								voiceHandle[4] = Novice::PlayAudio(audioHandle[4], 0, 0.1f);
							}
							if (switchFlag_ == 3) {
								if (map2[y][x] == WARPPOINT4) {
									
									shotPosX_ = x * Size;
									shotPosY_ = y * Size;
								}
							}
						}
						if (collisionFlag_ == 1) {
							if (map2[leftTopY_][leftTopX_] == WALL) {
								if (map2[rightTopY_][rightTopX_] == BACK || map0[rightTopY_][rightTopX_] == PLAYER) {
									setShotFlag_ = 1;
								}
								if (map2[rightTopY_][rightTopX_] == LEFT) {
									setShotFlag_ = 1;
								}
							}
							if (map2[leftTopY_][leftTopX_] == UP || map2[rightBottomY_][rightBottomX_] == DOWN ||
								map2[leftBottomY_][leftBottomX_] == RIGHT) {
								setShotFlag_ = 2;
							}
						}

						if (setShotFlag_ == 1) {
							shotFlag_ = 0;
							setShotFlag_ = 0;
						}
						if (setShotFlag_ == 2) {
							setShotFlag_ = 0;
						}

						if (map2[leftTopY_][leftTopX_] == WALL) {
							collisionFlag_ = 1;
						}
						else {
							collisionFlag_ = 0;

						}
					}

					//右
					if (shotMove_ == 2) {
						if (map2[leftBottomY_][leftBottomX_] == DOOR) {
							shotFlag_ = 0;
						}
						if (map2[leftBottomY_][leftBottomX_] == SWITCH1) {
							shotFlag_ = 0;
							if (Novice::IsPlayingAudio(voiceHandle[5]) == 0 || voiceHandle[5] == -1)
							{
								voiceHandle[5] = Novice::PlayAudio(audioHandle[5], 0, 0.1f);
							}
							if (switchFlag_ == 2 || switchFlag_ == 3) {
								switchFlag_ = 3;
							}
							else
							{
								switchFlag_ = 1;
							}
							if (map2[y][x] == SWITCH1) {
								map2[y][x] = SWITCH2;
							}

						}
						if (map2[leftBottomY_][leftBottomX_] == SWITCH3) {
							shotFlag_ = 0;
							switchFlag_ = 2;
							if (Novice::IsPlayingAudio(voiceHandle[5]) == 0 || voiceHandle[5] == -1)
							{
								voiceHandle[5] = Novice::PlayAudio(audioHandle[5], 0, 0.1f);
							}
							if (map2[y][x] == SWITCH3) {
								map2[y][x] = SWITCH4;
							}

						}
						if (map2[rightBottomY_][rightBottomX_] == WARPPOINT1) {
							if (Novice::IsPlayingAudio(voiceHandle[4]) == 0 || voiceHandle[4] == -1)
							{
								voiceHandle[4] = Novice::PlayAudio(audioHandle[4], 0, 0.1f);
							}
							if (switchFlag_ == 3) {
								if (map2[y][x] == WARPPOINT3) {

									shotPosX_ = x * Size;
									shotPosY_ = y * Size;
								}
							}
							else {
								if (map2[y][x] == WARPPOINT2) {

									shotPosX_ = x * Size;
									shotPosY_ = y * Size;
								}
							}
						}

						if (map2[rightTopY_][rightTopX_] == WALL) {
							collisionFlag_ = 1;
						}
						else {
							collisionFlag_ = 0;

						}

						if (collisionFlag_ == 1) {

							if (map2[leftTopY_][leftTopX_] == BACK && map2[leftBottomY_][leftBottomX_] == BACK || map0[leftTopY_][leftTopX_] == PLAYER) {
								setShotFlag_ = 1;
							}
							if (map2[leftTopY_][leftTopX_] == RIGHT) {
								setShotFlag_ = 1;
							}

							if (map2[rightTopY_][rightTopX_] == WALL && map2[rightBottomY_][rightBottomX_] == WALL &&
								map2[leftBottomY_][leftBottomX_] == WALL) {
								setShotFlag_ = 1;
							}

							if (map2[leftTopY_][leftTopX_] == UP || map2[leftBottomY_][leftBottomX_] == DOWN ||
								map2[leftBottomY_][leftBottomX_] == LEFT) {
								setShotFlag_ = 2;
							}
						}

						if (map2[rightTopY_][rightTopX_] == BACK && map2[rightBottomY_][rightBottomX_] == BACK &&
							map2[leftTopY_][leftTopX_] == BACK && map2[leftBottomY_][leftBottomX_] == BACK) {
							setShotFlag_ = 2;
						}
						if (setShotFlag_ == 1) {
							shotFlag_ = 0;
							setShotFlag_ = 0;
						}
						if (setShotFlag_ == 2) {
							setShotFlag_ = 0;
						}



					}

					//上
					if (shotMove_ == 3) {
						if (map2[leftBottomY_][leftBottomX_] == DOOR) {
							shotFlag_ = 0;
						}
						if (map2[leftBottomY_][leftBottomX_] == SWITCH1) {
							shotFlag_ = 0;
							if (Novice::IsPlayingAudio(voiceHandle[5]) == 0 || voiceHandle[5] == -1)
							{
								voiceHandle[5] = Novice::PlayAudio(audioHandle[5], 0, 0.1f);
							}

							if (switchFlag_ == 2 || switchFlag_ == 3) {
								switchFlag_ = 3;
							}
							else
							{
								switchFlag_ = 1;
							}
							if (map2[y][x] == SWITCH1) {
								map2[y][x] = SWITCH2;
							}

						}
						if (map2[leftBottomY_][leftBottomX_] == SWITCH3) {
							shotFlag_ = 0;
							switchFlag_ = 2;
							if (Novice::IsPlayingAudio(voiceHandle[5]) == 0 || voiceHandle[5] == -1)
							{
								voiceHandle[5] = Novice::PlayAudio(audioHandle[5], 0, 0.1f);
							}
							if (map2[y][x] == SWITCH3) {
								map2[y][x] = SWITCH4;
							}

						}

						if (map2[leftTopY_][leftTopX_] == WARPPOINT2) {
							shotFlag_ = 0;
						}

						if (map2[leftBottomY_][leftBottomX_] == WARPPOINT1) {
							if (Novice::IsPlayingAudio(voiceHandle[4]) == 0 || voiceHandle[4] == -1)
							{
								voiceHandle[4] = Novice::PlayAudio(audioHandle[4], 0, 0.1f);
							}
							if (switchFlag_ == 3) {
								if (map2[y][x] == WARPPOINT3) {

									shotPosX_ = x * Size;
									shotPosY_ = y * Size;
								}
							}
							else {
								if (map2[y][x] == WARPPOINT2) {

									shotPosX_ = x * Size;
									shotPosY_ = y * Size;
								}
							}
						}
						if (collisionFlag_ == 1) {
							if (map2[leftTopY_][leftTopX_] == WALL) {
								if (map2[leftBottomY_][leftBottomX_] == BACK || map2[leftBottomY_][leftBottomX_] == PLAYER) {
									setShotFlag_ = 1;
								}
								if (map2[leftBottomY_][leftBottomX_] == UP) {
									setShotFlag_ = 1;
								}
							}
							if (map2[leftTopY_][leftTopX_] == DOWN ||
								map2[leftTopY_][leftTopX_] == RIGHT || map2[leftTopY_][leftTopX_] == LEFT) {
								setShotFlag_ = 2;
							}

						}

						if (setShotFlag_ == 1) {
							shotFlag_ = 0;
							setShotFlag_ = 0;
						}
						if (setShotFlag_ == 2) {
							setShotFlag_ = 0;
						}

						if (map2[leftTopY_][leftTopX_] == WALL) {
							collisionFlag_ = 1;
						}
						else {
							collisionFlag_ = 0;
						}

					}

					//下
					if (shotMove_ == 4) {
						if (map2[leftBottomY_][leftBottomX_] == DOOR) {
							shotFlag_ = 0;
						}
						if (map2[leftBottomY_][leftBottomX_] == SWITCH1) {
							shotFlag_ = 0;
							if (Novice::IsPlayingAudio(voiceHandle[5]) == 0 || voiceHandle[5] == -1)
							{
								voiceHandle[5] = Novice::PlayAudio(audioHandle[5], 0, 0.1f);
							}

							if (switchFlag_ == 2 || switchFlag_ == 3) {
								switchFlag_ = 3;
							}
							else
							{
								switchFlag_ = 1;
							}
							if (map2[y][x] == SWITCH1) {
								map2[y][x] = SWITCH2;
							}

						}
						if (map2[leftBottomY_][leftBottomX_] == SWITCH3) {
							shotFlag_ = 0;
							switchFlag_ = 2;
							if (Novice::IsPlayingAudio(voiceHandle[5]) == 0 || voiceHandle[5] == -1)
							{
								voiceHandle[5] = Novice::PlayAudio(audioHandle[5], 0, 0.1f);
							}
							if (map2[y][x] == SWITCH3) {
								map2[y][x] = SWITCH4;
							}

						}
						if (map2[leftBottomY_][leftBottomX_] == WARPPOINT1) {
							if (Novice::IsPlayingAudio(voiceHandle[4]) == 0 || voiceHandle[4] == -1)
							{
								voiceHandle[4] = Novice::PlayAudio(audioHandle[4], 0, 0.1f);
							}
							if (map2[y][x] == WARPPOINT2) {

								shotPosX_ = x * Size;
								shotPosY_ = y * Size;
							}
						}

						if (collisionFlag_ == 1) {
							if (map2[leftBottomY_][leftBottomX_] == WALL) {
								if (map2[leftTopY_][leftTopX_] == BACK || map2[leftTopY_][leftTopX_] == PLAYER || map2[rightTopY_][rightTopX_] == PLAYER) {
									setShotFlag_ = 1;
								}
								if (map2[leftTopY_][leftTopX_] == DOWN) {
									setShotFlag_ = 1;
								}
							}

							if (map2[leftTopY_][leftTopX_] == UP ||
								map2[leftTopY_][leftTopX_] == RIGHT || map2[leftTopY_][leftTopX_] == LEFT) {
								setShotFlag_ = 2;
							}
						}

						if (setShotFlag_ == 1) {
							shotFlag_ = 0;
							setShotFlag_ = 0;
						}
						if (setShotFlag_ == 2) {
							setShotFlag_ = 0;
						}

						if (map2[leftBottomY_][leftBottomX_] == WALL) {
							collisionFlag_ = 1;
						}
						else {
							collisionFlag_ = 0;

						}

					}


					//スライド
					if (shotMove_ == 1) {
						if (map2[rightBottomY_][rightBottomX_] == UP) {
							shotMove_ = 3;
						}

						if (map2[leftTopY_][leftTopX_] == RIGHT) {
							shotMove_ = 2;
						}

						if (map2[leftTopY_][leftTopX_] == LEFT) {
							shotMove_ = 1;
						}

						if (map2[rightBottomY_][rightBottomX_] == DOWN) {
							shotMove_ = 4;
						}
					}

					if (shotMove_ == 2) {
						if (map2[leftTopY_][leftTopX_] == UP) {
							shotMove_ = 3;
						}

						if (map2[leftTopY_][leftTopX_] == RIGHT) {
							shotMove_ = 2;
						}

						if (map2[leftTopY_][leftTopX_] == LEFT) {
							shotMove_ = 1;
						}

						if (map2[leftTopY_][leftTopX_] == DOWN) {
							shotMove_ = 4;
						}
					}

					if (shotMove_ == 3) {
						if (map2[leftBottomY_][leftBottomX_] == UP) {
							shotMove_ = 3;
						}

						if (map2[leftBottomY_][leftBottomX_] == RIGHT) {
							shotMove_ = 2;
						}

						if (map2[leftBottomY_][leftBottomX_] == LEFT) {
							shotMove_ = 1;
						}

						if (map2[leftBottomY_][leftBottomX_] == DOWN) {
							shotMove_ = 4;
						}
					}

					if (shotMove_ == 4) {

						if (map2[leftTopY_][leftTopX_] == UP) {
							shotMove_ = 3;
						}

						if (map2[leftTopY_][leftTopX_] == RIGHT) {
							shotMove_ = 2;
						}

						if (map2[leftTopY_][leftTopX_] == LEFT) {
							shotMove_ = 1;
						}
						if (map2[leftTopY_][leftTopX_] == DOWN) {
							shotMove_ = 4;
						}
					}
				}
			}
			if (shotFlag_ == 0) {
				
				if (leftBlockLimit > 0) {
					//左ブロック
					if (mousePosX_ >= selectWX_[0] && mousePosX_ <= selectWX_[0] + selectWR_[0] &&
						mousePosY_ >= selectWY_[0] && mousePosY_ <= selectWY_[0] + selectWR_[0] && !isWall[0])
					{
						if (Novice::IsPlayingAudio(voiceHandle[6]) == 0 || voiceHandle[6] == -1)
						{
							voiceHandle[6] = Novice::PlayAudio(audioHandle[6], 0, 0.1f);
						}
						selectWColor_[0] = RED;
					}
					else
					{
						Novice::StopAudio(voiceHandle[6]);
						selectWColor_[0] = WHITE;
					}
					
					if (clickFlag_ == 0) {
						if (selectWColor_[0] == RED && Novice::IsPressMouse(0))
						{
							isWall[0] = true;
							clickFlag_ = 1;
						}
					}
					if (clickFlag_ == 1) {
						if (isWall[0])
						{
							selectWX_[0] = mousePosX_;
							selectWY_[0] = mousePosY_;
						}
						// マップとブロックの配置判定
						if (map2[leftTY[0]][leftTX[0]] == BACK && isWall[0] && selectWX_[0] <= 960)
						{
							backColor_[saveLeftTY[0]][saveLeftTX[0]] = WHITE;
							backColor_[leftTY[0]][leftTX[0]] = RED;
							saveLeftTX[0] = leftTX[0];
							saveLeftTY[0] = leftTY[0];
						}

						if (Novice::IsPressMouse(1) && backColor_[leftTY[0]][leftTX[0]] == RED && map2[leftTY[0]][leftTX[0]] == BACK)
						{
							if (Novice::IsPlayingAudio(voiceHandle[0]) == 0 || voiceHandle[0] == -1)
							{
								voiceHandle[0] = Novice::PlayAudio(audioHandle[0], 0, 0.1f);
							}
							map2[leftTY[0]][leftTX[0]] = LEFT;
							isWall[0] = false;
							clickFlag_ = 0;
							leftBlockLimit -= 1;
							selectWX_[0] = 1085;
							selectWY_[0] = 165;
						}
					}
				}
				if (rightBlockLimit > 0) {
					//右ブロック
					if (mousePosX_ >= selectWX_[1] && mousePosX_ <= selectWX_[1] + selectWR_[1] &&
						mousePosY_ >= selectWY_[1] && mousePosY_ <= selectWY_[1] + selectWR_[1] && !isWall[1])
					{
						if (Novice::IsPlayingAudio(voiceHandle[7]) == 0 || voiceHandle[7] == -1)
						{
							voiceHandle[7] = Novice::PlayAudio(audioHandle[7], 0, 0.1f);
						}
						selectWColor_[1] = RED;
					}
					else
					{
						Novice::StopAudio(voiceHandle[7]);
						selectWColor_[1] = WHITE;
					}
					
					if (clickFlag_ == 0) {
						if (selectWColor_[1] == RED && Novice::IsPressMouse(0))
						{
							isWall[1] = true;
							clickFlag_ = 2;
						}
					}
					if (clickFlag_ == 2) {
						if (isWall[1])
						{
							selectWX_[1] = mousePosX_;
							selectWY_[1] = mousePosY_;
						}
						// マップとブロックの配置判定
						if (map2[leftTY[1]][leftTX[1]] == BACK && isWall[1] && selectWX_[1] <= 960)
						{
							backColor_[saveLeftTY[1]][saveLeftTX[1]] = WHITE;
							backColor_[leftTY[1]][leftTX[1]] = RED;
							saveLeftTX[1] = leftTX[1];
							saveLeftTY[1] = leftTY[1];
						}

						if (Novice::IsPressMouse(1) && backColor_[leftTY[1]][leftTX[1]] == RED && map2[leftTY[1]][leftTX[1]] == BACK)
						{
							if (Novice::IsPlayingAudio(voiceHandle[0]) == 0 || voiceHandle[0] == -1)
							{
								voiceHandle[0] = Novice::PlayAudio(audioHandle[0], 0, 0.1f);
							}
							map2[leftTY[1]][leftTX[1]] = RIGHT;
							isWall[1] = false;
							clickFlag_ = 0;
							rightBlockLimit -= 1;
							selectWX_[1] = 1085;
							selectWY_[1] = 330;
						}

					}
				}
				if (downBlockLimit > 0) {
					//下ブロック
					if (mousePosX_ >= selectWX_[2] && mousePosX_ <= selectWX_[2] + selectWR_[2] &&
						mousePosY_ >= selectWY_[2] && mousePosY_ <= selectWY_[2] + selectWR_[2] && !isWall[2])
					{
						if (Novice::IsPlayingAudio(voiceHandle[8]) == 0 || voiceHandle[8] == -1)
						{
							voiceHandle[8] = Novice::PlayAudio(audioHandle[8], 0, 0.1f);
						}
						selectWColor_[2] = RED;
					}
					else
					{
						Novice::StopAudio(voiceHandle[8]);
						selectWColor_[2] = WHITE;
					}
					
					if (clickFlag_ == 0) {
						if (selectWColor_[2] == RED && Novice::IsPressMouse(0))
						{
							isWall[2] = true;
							clickFlag_ = 3;
						}
					}
					if (clickFlag_ == 3) {
						if (isWall[2])
						{
							selectWX_[2] = mousePosX_;
							selectWY_[2] = mousePosY_;
						}
						// マップとブロックの配置判定
						if (map2[leftTY[2]][leftTX[2]] == BACK && isWall[2] && selectWX_[2] <= 960)
						{
							backColor_[saveLeftTY[2]][saveLeftTX[2]] = WHITE;
							backColor_[leftTY[2]][leftTX[2]] = RED;
							saveLeftTX[2] = leftTX[2];
							saveLeftTY[2] = leftTY[2];
						}

						if (Novice::IsPressMouse(1) && backColor_[leftTY[2]][leftTX[2]] == RED && map2[leftTY[2]][leftTX[2]] == BACK)
						{
							if (Novice::IsPlayingAudio(voiceHandle[0]) == 0 || voiceHandle[0] == -1)
							{
								voiceHandle[0] = Novice::PlayAudio(audioHandle[0], 0, 0.1f);
							}
							map2[leftTY[2]][leftTX[2]] = DOWN;
							isWall[2] = false;
							clickFlag_ = 0;
							downBlockLimit -= 1;
							selectWX_[2] = 1085;
							selectWY_[2] = 485;
						}
					}
				}
				if (upBlockLimit > 0) {
					//上ブロック
					if (mousePosX_ >= selectWX_[3] && mousePosX_ <= selectWX_[3] + selectWR_[3] &&
						mousePosY_ >= selectWY_[3] && mousePosY_ <= selectWY_[3] + selectWR_[3] && !isWall[3])
					{
						if (Novice::IsPlayingAudio(voiceHandle[9]) == 0 || voiceHandle[9] == -1)
						{
							voiceHandle[9] = Novice::PlayAudio(audioHandle[9], 0, 0.1f);
						}
						selectWColor_[3] = RED;
					}
					else
					{
						Novice::StopAudio(voiceHandle[9]);
						selectWColor_[3] = WHITE;
					}
					
					if (clickFlag_ == 0) {
						if (selectWColor_[3] == RED && Novice::IsPressMouse(0))
						{
							isWall[3] = true;
							clickFlag_ = 4;
						}
					}
					if (clickFlag_ == 4) {
						if (isWall[3])
						{
							selectWX_[3] = mousePosX_;
							selectWY_[3] = mousePosY_;
						}
						// マップとブロックの配置判定
						if (map2[leftTY[3]][leftTX[3]] == BACK && isWall[3] && selectWX_[3] <= 960)
						{
							backColor_[saveLeftTY[3]][saveLeftTX[3]] = WHITE;
							backColor_[leftTY[3]][leftTX[3]] = RED;
							saveLeftTX[3] = leftTX[3];
							saveLeftTY[3] = leftTY[3];
						}

						if (Novice::IsPressMouse(1) && backColor_[leftTY[3]][leftTX[3]] == RED && map2[leftTY[3]][leftTX[3]] == BACK)
						{
							if (Novice::IsPlayingAudio(voiceHandle[0]) == 0 || voiceHandle[0] == -1)
							{
								voiceHandle[0] = Novice::PlayAudio(audioHandle[0], 0, 0.1f);
							}
							map2[leftTY[3]][leftTX[3]] = UP;
							isWall[3] = false;
							clickFlag_ = 0;
							upBlockLimit -= 1;
							selectWX_[3] = 1085;
							selectWY_[3] = 650;
						}
					}
				}
			}
		}
	}

	if (shotFlag_ == 1 && shotMove_ == 1) {
		shotPosX_ -= shotSpead_;
		countL_ = 1;
	}
	if (shotFlag_ == 1 && shotMove_ == 2) {
		shotPosX_ += shotSpead_;
		countR_ = 1;
	}
	if (shotFlag_ == 1 && shotMove_ == 3) {
		shotPosY_ -= shotSpead_;
		countU_ = 1;
	}
	if (shotFlag_ == 1 && shotMove_ == 4) {
		shotPosY_ += shotSpead_;
		countD_ = 1;
	}

	if (shotFlag_ == 0) {

		if (keys[DIK_LEFT]) {
			shotMove_ = 1;
		}
		if (keys[DIK_RIGHT]) {
			shotMove_ = 2;
		}
		if (keys[DIK_UP]) {
			shotMove_ = 3;
		}
		if (keys[DIK_DOWN]) {
			shotMove_ = 4;
		}
	}

	if (Novice::IsPressMouse(1) && isWall[0])
	{
		isWall[0] = false;
		backColor_[saveLeftTY[0]][saveLeftTX[0]] = WHITE;
		saveLeftTX[0] = leftTX[0];
		saveLeftTY[0] = leftTY[0];
		clickFlag_ = 0;
		selectWX_[0] = 1085;
		selectWY_[0] = 165;
	}

	if (Novice::IsPressMouse(1) && isWall[1])
	{
		isWall[1] = false;
		backColor_[saveLeftTY[1]][saveLeftTX[1]] = WHITE;
		saveLeftTX[1] = leftTX[1];
		saveLeftTY[1] = leftTY[1];
		clickFlag_ = 0;
		selectWX_[1] = 1085;
		selectWY_[1] = 330;
	}

	if (Novice::IsPressMouse(1) && isWall[2])
	{
		isWall[2] = false;
		backColor_[saveLeftTY[2]][saveLeftTX[2]] = WHITE;
		saveLeftTX[2] = leftTX[2];
		saveLeftTY[2] = leftTY[2];
		clickFlag_ = 0;
		selectWX_[2] = 1085;
		selectWY_[2] = 485;
	}

	if (Novice::IsPressMouse(1) && isWall[3])
	{
		isWall[3] = false;
		backColor_[saveLeftTY[3]][saveLeftTX[3]] = WHITE;
		saveLeftTX[3] = leftTX[3];
		saveLeftTY[3] = leftTY[3];
		clickFlag_ = 0;
		selectWX_[3] = 1085;
		selectWY_[3] = 650;
	}

	// リセット
	if (keys[DIK_R]) {
		MapReset(stageNo);
		shotFlag_ = 0;
		switchFlag_ = 0;
		rightBlockLimit = 3;
		leftBlockLimit = 4;
		upBlockLimit = 4;
		downBlockLimit = 2;
	}

	// ゲームクリア処理
	if (deadFlag_ == 2 && stageNo == STAGE1 || deadFlag_ == 2 && stageNo == STAGE2 || deadFlag_ == 2 && stageNo == STAGE3)
	{
		gameClear_->SetFIn(true);
		shotMove_ = 3;
		deadFlag_ = 0;
	}

	// ゲームオーバー処理
	/*if (keys[DIK_O])
	{
		gameOver_->SetFIn(true);
	}*/
}


void GameManager::Draw(int stageNo)
{
	stageNumber = stageNo;

	Novice::DrawSprite(0, 0, BG, 1, 1, 0, WHITE);

	// チュートリアル
	if (stageNumber == TUTORIAL)
	{
		for (int y = 0; y < mapCountY; y++) {
			for (int x = 0; x < mapCountX; x++) {
				// 背景
				if (tutorialMap[y][x] == BACK) {
					Novice::DrawSprite(x * Size, y * Size, back, 1, 1, 0, backColor_[y][x]);
				}

				// 壁
				if (tutorialMap[y][x] == WALL) {
					Novice::DrawSprite(x * Size, y * Size, wall, 1, 1, 0, WHITE);
				}
			}
		}
		
		for (int y = 0; y < mapCountY; y++) {
			for (int x = 0; x < mapCountX; x++) {
				// プレイヤー
				if (tutorialMap[y][x] == PLAYER) {
					Novice::DrawSprite(x * Size, y * Size, player, 1, 1, 0, WHITE);
				}
				// 上
				if (tutorialMap[y][x] == UP) {
					Novice::DrawSprite(x * Size, y * Size, up, 1, 1, 0, WHITE);
				}
				// 下
				if (tutorialMap[y][x] == DOWN) {
					Novice::DrawSprite(x * Size, y * Size, down, 1, 1, 0, WHITE);
				}
				// 右
				if (tutorialMap[y][x] == RIGHT) {
					Novice::DrawSprite(x * Size, y * Size, right, 1, 1, 0, WHITE);
				}
				// 左
				if (tutorialMap[y][x] == LEFT) {
					Novice::DrawSprite(x * Size, y * Size, left, 1, 1, 0, WHITE);
				}

				// エネミー
				if (tutorialMap[y][x] == ENEMY) {
					Novice::DrawSprite(x * Size - shakeRandX_, y * Size - shakeRandY_, enemy, 1, 1, 0, enemyColor);

				}
			}
		}
		if (shakeFlag_ == 1 && saveShake_ == 0 || shakeFlag_ == 2) {
			for (int i = 0; i < 8; i++) {
				if (efectFlag_[i] == 1) {
					if (efectTimer_ >= 50) {
						Novice::DrawSprite((int)efectPosX_[i] + 16, (int)efectPosY_[i] + 16, efect, 0.5f, 0.5f, 0, WHITE);
					}
				}
			}
		}
		if (shotFlag_ == 0 && isTutorial_) {
			// プレイヤーの向き
			if (shotMove_ == 1) // 左向き
			{
				Novice::DrawSprite(savePlayerPosX_ - 64, savePlayerPosY_, leftAllow, 1, 1, 0, WHITE);
			}
			if (shotMove_ == 2) // 右向き
			{
				Novice::DrawSprite(savePlayerPosX_ + 64, savePlayerPosY_, rightAllow, 1, 1, 0, WHITE);
			}
			if (shotMove_ == 3) // 上向き
			{
				Novice::DrawSprite(savePlayerPosX_, savePlayerPosY_ - 64, upAllow, 1, 1, 0, WHITE);
			}
			if (shotMove_ == 4) // 下向き
			{
				Novice::DrawSprite(savePlayerPosX_, savePlayerPosY_ + 64, downAllow, 1, 1, 0, WHITE);
			}
		}
		// 選択欄
		Novice::DrawSprite(960, 0, panel, 1, 1, 0, WHITE);
		Novice::DrawSprite(selectWX_[0], selectWY_[0], left, 1, 1, 0, selectWColor_[0]);
		Novice::DrawSprite(selectWX_[1], selectWY_[1], right, 1, 1, 0, selectWColor_[1]);
		Novice::DrawSprite(selectWX_[2], selectWY_[2], down, 1, 1, 0, selectWColor_[2]);
		Novice::DrawSprite(selectWX_[3], selectWY_[3], up, 1, 1, 0, selectWColor_[3]);
		// チュートリアルテキスト

		if (!isTutorial_)
		{
			if (tutorialScene_ == 0)
			{
				if (textCount_ == 0)
				{
					Novice::DrawSprite(0, 528, text[0], 1.f, 1.f, 0.f, WHITE);
					Novice::DrawSpriteRect(1030, 660, spaceScrX_, 0, spaceW_, 64, space, 0.6f, 1.6f, 0.f, WHITE);
				}
				if (textCount_ == 1)
				{
					Novice::DrawSprite(0, 528, text[1], 1.f, 1.f, 0.f, WHITE);
					Novice::DrawSpriteRect(1030, 660, spaceScrX_, 0, spaceW_, 64, space, 0.6f, 1.6f, 0.f, WHITE);
				}
				if (textCount_ == 2)
				{
					Novice::DrawSprite(0, 528, text[2], 1.f, 1.f, 0.f, WHITE);
					Novice::DrawSpriteRect(1030, 660, spaceScrX_, 0, spaceW_, 64, space, 0.6f, 1.6f, 0.f, WHITE);
				}
				if (textCount_ == 3 && countL_ == 1 && countR_ == 1 && countU_ == 1 && countD_ == 1)
				{
					Novice::DrawSprite(0, 528, text[3], 1.f, 1.f, 0.f, WHITE);
					Novice::DrawSpriteRect(1030, 660, spaceScrX_, 0, spaceW_, 64, space, 0.6f, 1.6f, 0.f, WHITE);
				}
				Novice::DrawSprite(int(menu_.pos.x), int(menu_.pos.y), mission[0], 1.0f, 1.f, 0.0f, WHITE);
			}

			if (tutorialScene_ == 1)
			{
				if (textCount_ == 4)
				{
					Novice::DrawSprite(0, 528, text[4], 1.f, 1.f, 0.f, WHITE);
					Novice::DrawSpriteRect(1030, 660, spaceScrX_, 0, spaceW_, 64, space, 0.6f, 1.6f, 0.f, WHITE);
				}
				if (textCount_ == 5)
				{
					Novice::DrawSprite(0, 528, text[5], 1.f, 1.f, 0.f, WHITE);
					Novice::DrawSpriteRect(1030, 660, spaceScrX_, 0, spaceW_, 64, space, 0.6f, 1.6f, 0.f, WHITE);
				}
				if (textCount_ == 6 && deadFlag_ == 2)
				{
					Novice::DrawSprite(0, 528, text[6], 1.f, 1.f, 0.f, WHITE);
					Novice::DrawSpriteRect(1030, 660, spaceScrX_, 0, spaceW_, 64, space, 0.6f, 1.6f, 0.f, WHITE);
				}
				if (textCount_ == 7 && deadFlag_ == 2)
				{
					Novice::DrawSprite(0, 528, text[7], 1.f, 1.f, 0.f, WHITE);
					Novice::DrawSpriteRect(1030, 660, spaceScrX_, 0, spaceW_, 64, space, 0.6f, 1.6f, 0.f, WHITE);
				}
				Novice::DrawSprite(int(menu_.pos.x), int(menu_.pos.y), mission[1], 1.0f, 1.f, 0.0f, WHITE);
			}

			if (isOpen_)
			{
				Novice::DrawEllipse(sBoxX_, sBoxY_, sBoxR_, sBoxR_, 0.f, BLACK, kFillModeSolid);
			}
		}
	}

	// 本編
	if (stageNumber == STAGE1) {
		for (int y = 0; y < mapCountY; y++) {
			for (int x = 0; x < mapCountX; x++) {
				// 背景
				if (map0[y][x] == BACK) {
					Novice::DrawSprite(x * Size, y * Size, back, 1, 1, 0, backColor_[y][x]);
				}

				// 壁
				if (map0[y][x] == WALL) {
					Novice::DrawSprite(x * Size, y * Size, wall, 1, 1, 0, WHITE);
				}
			}
		}
	
		for (int y = 0; y < mapCountY; y++) {
			for (int x = 0; x < mapCountX; x++) {
				// プレイヤー
				if (map0[y][x] == PLAYER) {
					Novice::DrawSprite(x * Size, y * Size, player, 1, 1, 0, WHITE);
				}
				// 上
				if (map0[y][x] == UP) {
					Novice::DrawSprite(x * Size, y * Size, up, 1, 1, 0, WHITE);
				}
				// 下
				if (map0[y][x] == DOWN) {
					Novice::DrawSprite(x * Size, y * Size, down, 1, 1, 0, WHITE);
				}
				// 右
				if (map0[y][x] == RIGHT) {
					Novice::DrawSprite(x * Size, y * Size, right, 1, 1, 0, WHITE);
				}
				// 左
				if (map0[y][x] == LEFT) {
					Novice::DrawSprite(x * Size, y * Size, left, 1, 1, 0, WHITE);
				}

				// エネミー
				if (map0[y][x] == ENEMY) {
					Novice::DrawSprite(x * Size - shakeRandX_, y * Size - shakeRandY_, enemy, 1, 1, 0, enemyColor);

				}
			}
		}
		if (shakeFlag_ == 1 && saveShake_ == 0 || shakeFlag_ == 2) {
			for (int i = 0; i < 8; i++) {
				if (efectFlag_[i] == 1) {
					if (efectTimer_ >= 50) {
						Novice::DrawSprite((int)efectPosX_[i] + 16, (int)efectPosY_[i] + 16, efect, 0.5f, 0.5f, 0, WHITE);
					}
				}
			}
		}
		if (deadFlag_ == 0){
			if (shotFlag_ == 0) {
				// プレイヤーの向き
				if (shotMove_ == 1) // 左向き
				{
					Novice::DrawSprite(savePlayerPosX_ - 64, savePlayerPosY_, leftAllow, 1, 1, 0, WHITE);
				}
				if (shotMove_ == 2) // 右向き
				{
					Novice::DrawSprite(savePlayerPosX_ + 64, savePlayerPosY_, rightAllow, 1, 1, 0, WHITE);
				}
				if (shotMove_ == 3) // 上向き
				{
					Novice::DrawSprite(savePlayerPosX_, savePlayerPosY_ - 64, upAllow, 1, 1, 0, WHITE);
				}
				if (shotMove_ == 4) // 下向き
				{
					Novice::DrawSprite(savePlayerPosX_, savePlayerPosY_ + 64, downAllow, 1, 1, 0, WHITE);
				}
			}
		}
		// 選択欄
		Novice::DrawSprite(960, 0, panel, 1, 1, 0, WHITE);
		Novice::DrawSprite(selectWX_[0], selectWY_[0], left, 1, 1, 0, selectWColor_[0]);
		Novice::DrawSprite(selectWX_[1], selectWY_[1], right, 1, 1, 0, selectWColor_[1]);
		Novice::DrawSprite(selectWX_[2], selectWY_[2], down, 1, 1, 0, selectWColor_[2]);
		Novice::DrawSprite(selectWX_[3], selectWY_[3], up, 1, 1, 0, selectWColor_[3]);
	}

	if (stageNumber == STAGE2) {
		for (int y = 0; y < mapCountY; y++) {
			for (int x = 0; x < mapCountX; x++) {
				// 背景
				if (map1[y][x] == BACK) {
					Novice::DrawSprite(x * Size, y * Size, back, 1, 1, 0, backColor_[y][x]);
				}

				// 壁
				if (map1[y][x] == WALL) {
					Novice::DrawSprite(x * Size, y * Size, wall, 1, 1, 0, WHITE);
				}
			}
		}
		
		for (int y = 0; y < mapCountY; y++) {
			for (int x = 0; x < mapCountX; x++) {
				// プレイヤー
				if (map1[y][x] == PLAYER) {
					Novice::DrawSprite(x * Size, y * Size, player, 1, 1, 0, WHITE);
				}
				// 上
				if (map1[y][x] == UP) {
					Novice::DrawSprite(x * Size, y * Size, up, 1, 1, 0, WHITE);
				}
				// 下
				if (map1[y][x] == DOWN) {
					Novice::DrawSprite(x * Size, y * Size, down, 1, 1, 0, WHITE);
				}
				// 右
				if (map1[y][x] == RIGHT) {
					Novice::DrawSprite(x * Size, y * Size, right, 1, 1, 0, WHITE);
				}
				// 左
				if (map1[y][x] == LEFT) {
					Novice::DrawSprite(x * Size, y * Size, left, 1, 1, 0, WHITE);
				}
				// エネミー
				if (map1[y][x] == ENEMY) {
					Novice::DrawSprite(x * Size - shakeRandX_, y * Size - shakeRandY_, enemy, 1, 1, 0, enemyColor);
				}
				// ドア
				if (map1[y][x] == DOOR) {
					Novice::DrawSprite(x * Size, y * Size, door2, 1, 1, 0, WHITE);
				}
				// スイッチ
				if (map1[y][x] == SWITCH1) {
					Novice::DrawSprite(x * Size, y * Size, switchR1, 1, 1, 0, WHITE);
				}
				// スイッチ押した後
				if (map1[y][x] == SWITCH2) {
					Novice::DrawSprite(x * Size, y * Size, switchR2, 1, 1, 0, WHITE);
				}
			}
		}
		if (shakeFlag_ == 1 && saveShake_ == 0 || shakeFlag_ == 2) {
			for (int i = 0; i < 8; i++) {
				if (efectFlag_[i] == 1) {
					if (efectTimer_ >= 50) {
						Novice::DrawSprite((int)efectPosX_[i] + 16, (int)efectPosY_[i] + 16, efect, 0.5f, 0.5f, 0, WHITE);
					}
				}
			}
		}
		if (switch_ == 1 && deadFlag_ == 0) {
			if (shotFlag_ == 0) {
				// プレイヤーの向き
				if (shotMove_ == 1) // 左向き
				{
					Novice::DrawSprite(savePlayerPosX_ - 64, savePlayerPosY_, leftAllow, 1, 1, 0, WHITE);
				}
				if (shotMove_ == 2) // 右向き
				{
					Novice::DrawSprite(savePlayerPosX_ + 64, savePlayerPosY_, rightAllow, 1, 1, 0, WHITE);
				}
				if (shotMove_ == 3) // 上向き
				{
					Novice::DrawSprite(savePlayerPosX_, savePlayerPosY_ - 64, upAllow, 1, 1, 0, WHITE);
				}
				if (shotMove_ == 4) // 下向き
				{
					Novice::DrawSprite(savePlayerPosX_, savePlayerPosY_ + 64, downAllow, 1, 1, 0, WHITE);
				}
			}
		}
		// 選択欄
		Novice::DrawSprite(960, 0, panel, 1, 1, 0, WHITE);
		Novice::DrawSprite(selectWX_[0], selectWY_[0], left, 1, 1, 0, selectWColor_[0]);
		Novice::DrawSprite(selectWX_[1], selectWY_[1], right, 1, 1, 0, selectWColor_[1]);
		Novice::DrawSprite(selectWX_[2], selectWY_[2], down, 1, 1, 0, selectWColor_[2]);
		Novice::DrawSprite(selectWX_[3], selectWY_[3], up, 1, 1, 0, selectWColor_[3]);
		if (switch_ == 0) {
			Novice::DrawSprite(int(menu_.pos.x), int(menu_.pos.y), blockC[1], 1.0f, 1.f, 0.0f, WHITE);
		}
	}

	if (stageNumber == STAGE3) {
		for (int y = 0; y < mapCountY; y++) {
			for (int x = 0; x < mapCountX; x++) {
				// 背景
				if (map2[y][x] == BACK) {
					Novice::DrawSprite(x * Size, y * Size, back, 1, 1, 0, backColor_[y][x]);
				}

				// 壁
				if (map2[y][x] == WALL) {
					Novice::DrawSprite(x * Size, y * Size, wall, 1, 1, 0, WHITE);
				}
			}
		}
	
		for (int y = 0; y < mapCountY; y++) {
			for (int x = 0; x < mapCountX; x++) {
				// プレイヤー
				if (map2[y][x] == PLAYER) {
					Novice::DrawSprite(x * Size, y * Size, player, 1, 1, 0, WHITE);
				}
				// 上
				if (map2[y][x] == UP) {
					Novice::DrawSprite(x * Size, y * Size, up, 1, 1, 0, WHITE);
				}
				// 下
				if (map2[y][x] == DOWN) {
					Novice::DrawSprite(x * Size, y * Size, down, 1, 1, 0, WHITE);
				}
				// 右
				if (map2[y][x] == RIGHT) {
					Novice::DrawSprite(x * Size, y * Size, right, 1, 1, 0, WHITE);
				}
				// 左
				if (map2[y][x] == LEFT) {
					Novice::DrawSprite(x * Size, y * Size, left, 1, 1, 0, WHITE);
				}
				// エネミー
				if (map2[y][x] == ENEMY) {
					Novice::DrawSprite(x * Size - shakeRandX_, y * Size - shakeRandY_, enemy, 1, 1, 0, enemyColor);
				}
				// ワープポイント
				if (map2[y][x] == WARPPOINT1) {
					Novice::DrawSprite(x * Size, y * Size, warp, 1, 1, 0, WHITE);
				}
				// ワープ先
				if (map2[y][x] == WARPPOINT2) {
					Novice::DrawSprite(x * Size, y * Size, warp, 1, 1, 0, WHITE);
				}
				// ワープポイント
				if (map2[y][x] == WARPPOINT3) {
					Novice::DrawSprite(x * Size, y * Size, warpR, 1, 1, 0, WHITE);
				}
				// ワープ先
				if (map2[y][x] == WARPPOINT4) {
					Novice::DrawSprite(x * Size, y * Size, warpR, 1, 1, 0, WHITE);
				}
				// スイッチ
				if (map2[y][x] == SWITCH1) {
					Novice::DrawSprite(x * Size, y * Size, switchR1, 1, 1, 0, WHITE);
				}
				// スイッチ押した後
				if (map2[y][x] == SWITCH2) {
					Novice::DrawSprite(x * Size, y * Size, switchR2, 1, 1, 0, WHITE);
				}
				// スイッチ
				if (map2[y][x] == SWITCH3) {
					Novice::DrawSprite(x * Size, y * Size, switchB1, 1, 1, 0, WHITE);
				}
				// スイッチ押した後
				if (map2[y][x] == SWITCH4) {
					Novice::DrawSprite(x * Size, y * Size, switchB2, 1, 1, 0, WHITE);
				}
				// ドア
				if (map2[y][x] == DOOR) {
					Novice::DrawSprite(x * Size, y * Size, door2, 1, 1, 0, WHITE);
				}
				// ドア
				if (map2[y][x] == DOOR2) {
					Novice::DrawSprite(x * Size, y * Size, door1, 1, 1, 0, WHITE);
				}
			}
		}
		if (shakeFlag_ == 1 && saveShake_ == 0 || shakeFlag_ == 2) {
			for (int i = 0; i < 8; i++) {
				if (efectFlag_[i] == 1) {
					if (efectTimer_ >= 50) {
						Novice::DrawSprite((int)efectPosX_[i] + 16, (int)efectPosY_[i] + 16, efect, 0.5f, 0.5f, 0, WHITE);
					}
				}
			}
		}
		if (warpFlag == 1 && deadFlag_ == 0) {
			if (shotFlag_ == 0) {
				// プレイヤーの向き
				if (shotMove_ == 1) // 左向き
				{
					Novice::DrawSprite(savePlayerPosX_ - 64, savePlayerPosY_, leftAllow, 1, 1, 0, WHITE);
				}
				if (shotMove_ == 2) // 右向き
				{
					Novice::DrawSprite(savePlayerPosX_ + 64, savePlayerPosY_, rightAllow, 1, 1, 0, WHITE);
				}
				if (shotMove_ == 3) // 上向き
				{
					Novice::DrawSprite(savePlayerPosX_, savePlayerPosY_ - 64, upAllow, 1, 1, 0, WHITE);
				}
				if (shotMove_ == 4) // 下向き
				{
					Novice::DrawSprite(savePlayerPosX_, savePlayerPosY_ + 64, downAllow, 1, 1, 0, WHITE);
				}
			}
		}

		// 選択欄
		Novice::DrawSprite(960, 0, panel, 1, 1, 0, WHITE);
		Novice::DrawSprite(selectWX_[0], selectWY_[0], left, 1, 1, 0, selectWColor_[0]);
		Novice::DrawSprite(selectWX_[1], selectWY_[1], right, 1, 1, 0, selectWColor_[1]);
		Novice::DrawSprite(selectWX_[2], selectWY_[2], down, 1, 1, 0, selectWColor_[2]);
		Novice::DrawSprite(selectWX_[3], selectWY_[3], up, 1, 1, 0, selectWColor_[3]);
		if (warpFlag == 1) {
			NumberDraw();
		}
		if (warpFlag == 0) {
			Novice::DrawSprite(int(menu_.pos.x), int(menu_.pos.y), blockC[0], 1.0f, 1.f, 0.0f, WHITE);
		}
	}
	
		//Novice::ScreenPrintf(1000, 0, "map[%d][%d]", leftTY, leftTX);
		//Novice::ScreenPrintf(1000, 20, "saveMap[%d][%d]", saveLeftTY, saveLeftTX);

		if (shotFlag_ == 1) {
			Novice::DrawSprite(shotPosX_, shotPosY_, bullet, 1.0f, 1.0f, 0.0f, WHITE);
		}

	/*	Novice::ScreenPrintf(0, 0, "flagOut : %d", flagOut_);
		Novice::ScreenPrintf(0, 20, "flagIn : %d", flagIn_);
		Novice::ScreenPrintf(0, 40, "textTimer : %d", textTimer_);*/
	
}

void GameManager::MapReset(int stageNo)
{
	// リセット
	for (int y = 0; y < mapCountY; y++) {
		for (int x = 0; x < mapCountX; x++) {

			// チュートリアル
			if (stageNo == TUTORIAL)
			{
				if (tutorialScene_ == 0)
				{
					tutorialMap[y][x] = tutorialMapInitialize[y][x];
				}
				if (tutorialScene_ == 1)
				{
					tutorialMap[y][x] = tutorialMapInitialize2[y][x];
				}
			}
			// ステージ１
			if (stageNo == STAGE1)
			{
				map0[y][x] = initializeMap0[y][x];
			}
			// ステージ２
			if (stageNo == STAGE2)
			{
				map1[y][x] = initializeMap1[y][x];
			}
			// ステージ３
			if (stageNo == STAGE3)
			{
				map2[y][x] = initializeMap2[y][x];
			}

			backColor_[y][x] = WHITE;
		}
	}
}

void GameManager::Animation()
{
	animetionTimer_ += 1;

	if (animetionTimer_ >= 7)
	{
		spaceScrX_ += 64;
		animetionTimer_ = 0;
		if (spaceScrX_ >= 320)
		{
			spaceScrX_ = 0;
		}
	}
}

void GameManager::NumberDraw()
{
	//上ブロック
	if (upBlockLimit == 0) {
		Novice::DrawSprite(1165, 684, number[0], 1, 1, 0, WHITE);
	}
	if (upBlockLimit == 1) {
		Novice::DrawSprite(1165, 684, number[1], 1, 1, 0, WHITE);
	}
	if (upBlockLimit == 2) {
		Novice::DrawSprite(1165, 684, number[2], 1, 1, 0, WHITE);
	}
	if (upBlockLimit == 3) {
		Novice::DrawSprite(1165, 684, number[3], 1, 1, 0, WHITE);
	}
	if (upBlockLimit == 4) {
		Novice::DrawSprite(1165, 684, number[4], 1, 1, 0, WHITE);
	}
	if (upBlockLimit == 5) {
		Novice::DrawSprite(1165, 684, number[5], 1, 1, 0, WHITE);
	}
	if (upBlockLimit == 6) {
		Novice::DrawSprite(1165, 684, number[6], 1, 1, 0, WHITE);
	}
	if (upBlockLimit == 7) {
		Novice::DrawSprite(1165, 684, number[7], 1, 1, 0, WHITE);
	}
	if (upBlockLimit == 8) {
		Novice::DrawSprite(1165, 684, number[8], 1, 1, 0, WHITE);
	}
	if (upBlockLimit == 9) {
		Novice::DrawSprite(1165, 684, number[9], 1, 1, 0, WHITE);
	}

	//上ブロック
	if (downBlockLimit == 0) {
		Novice::DrawSprite(1165, 519, number[0], 1, 1, 0, WHITE);
	}
	if (downBlockLimit == 1) {
		Novice::DrawSprite(1165, 519, number[1], 1, 1, 0, WHITE);
	}
	if (downBlockLimit == 2) {
		Novice::DrawSprite(1165, 519, number[2], 1, 1, 0, WHITE);
	}
	if (downBlockLimit == 3) {
		Novice::DrawSprite(1165, 519, number[3], 1, 1, 0, WHITE);
	}
	if (downBlockLimit == 4) {
		Novice::DrawSprite(1165, 519, number[4], 1, 1, 0, WHITE);
	}
	if (downBlockLimit == 5) {
		Novice::DrawSprite(1165, 519, number[5], 1, 1, 0, WHITE);
	}
	if (downBlockLimit == 6) {
		Novice::DrawSprite(1165, 519, number[6], 1, 1, 0, WHITE);
	}
	if (downBlockLimit == 7) {
		Novice::DrawSprite(1165, 519, number[7], 1, 1, 0, WHITE);
	}
	if (downBlockLimit == 8) {
		Novice::DrawSprite(1165, 519, number[8], 1, 1, 0, WHITE);
	}
	if (downBlockLimit == 9) {
		Novice::DrawSprite(1165, 519, number[9], 1, 1, 0, WHITE);
	}

	//右ブロック
	if (rightBlockLimit == 0) {
		Novice::DrawSprite(1165, 364, number[0], 1, 1, 0, WHITE);
	}
	if (rightBlockLimit == 1) {
		Novice::DrawSprite(1165, 364, number[1], 1, 1, 0, WHITE);
	}
	if (rightBlockLimit == 2) {
		Novice::DrawSprite(1165, 364, number[2], 1, 1, 0, WHITE);
	}
	if (rightBlockLimit == 3) {
		Novice::DrawSprite(1165, 364, number[3], 1, 1, 0, WHITE);
	}
	if (rightBlockLimit == 4) {
		Novice::DrawSprite(1165, 364, number[4], 1, 1, 0, WHITE);
	}
	if (rightBlockLimit == 5) {
		Novice::DrawSprite(1165, 364, number[5], 1, 1, 0, WHITE);
	}
	if (rightBlockLimit == 6) {
		Novice::DrawSprite(1165, 364, number[6], 1, 1, 0, WHITE);
	}
	if (rightBlockLimit == 7) {
		Novice::DrawSprite(1165, 364, number[7], 1, 1, 0, WHITE);
	}
	if (rightBlockLimit == 8) {
		Novice::DrawSprite(1165, 364, number[8], 1, 1, 0, WHITE);
	}
	if (rightBlockLimit == 9) {
		Novice::DrawSprite(1165, 364, number[9], 1, 1, 0, WHITE);
	}
	//左ブロック
	if (leftBlockLimit == 0) {
		Novice::DrawSprite(1165, 199, number[0], 1, 1, 0, WHITE);
	}
	if (leftBlockLimit == 1) {
		Novice::DrawSprite(1165, 199, number[1], 1, 1, 0, WHITE);
	}
	if (leftBlockLimit == 2) {
		Novice::DrawSprite(1165, 199, number[2], 1, 1, 0, WHITE);
	}
	if (leftBlockLimit == 3) {
		Novice::DrawSprite(1165, 199, number[3], 1, 1, 0, WHITE);
	}
	if (leftBlockLimit == 4) {
		Novice::DrawSprite(1165, 199, number[4], 1, 1, 0, WHITE);
	}
	if (leftBlockLimit == 5) {
		Novice::DrawSprite(1165, 199, number[5], 1, 1, 0, WHITE);
	}
	if (leftBlockLimit == 6) {
		Novice::DrawSprite(1165, 199, number[6], 1, 1, 0, WHITE);
	}
	if (leftBlockLimit == 7) {
		Novice::DrawSprite(1165, 199, number[7], 1, 1, 0, WHITE);
	}
	if (leftBlockLimit == 8) {
		Novice::DrawSprite(1165, 199, number[7], 1, 1, 0, WHITE);
	}
	if (leftBlockLimit == 9) {
		Novice::DrawSprite(1165, 199, number[9], 1, 1, 0, WHITE);
	}
}
