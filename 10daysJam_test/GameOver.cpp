#include "GameOver.h"

void GameOver::Initialize()
{
	//テクスチャ
	gameOver_ = Novice::LoadTexture("./Resource/images/GameOver.png");
	retry_ = Novice::LoadTexture("./Resource/images/retry.png");
	backSelect_ = Novice::LoadTexture("./Resource/images/backSelect.png");
}

void GameOver::Update(bool flagIn)
{
	Novice::GetMousePosition(&mousePosX_, &mousePosY_);

	flagIn_ = flagIn;

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
		isOpen_ = true;
	}

	if (mousePosX_ >= menu_.pos.x + 125 && mousePosX_ <= menu_.pos.x + 125 + menuW_ - 725 && mousePosY_ >= menu_.pos.y + 250 && mousePosY_ <= menu_.pos.y + 250 + menuH_ - 400)
	{
		boxColorL_ = BLUE;
	}
	else
	{
		boxColorL_ = WHITE;
	}

	if (mousePosX_ >= menu_.pos.x + 605 && mousePosX_ <= menu_.pos.x + 605 + menuW_ - 725 && mousePosY_ >= menu_.pos.y + 250 && mousePosY_ <= menu_.pos.y + 250 + menuH_ - 400)
	{
		boxColorR_ = BLUE;
	}
	else
	{
		boxColorR_ = WHITE;
	}

	if (boxColorL_ == BLUE && Novice::IsPressMouse(0) && !selectR_ && flame_ >= 80)
	{
		selectL_ = true;
		flagOut_ = true;
	}
	if (boxColorR_ == BLUE && Novice::IsPressMouse(0) && !selectL_ && flame_ >= 80)
	{
		selectR_ = true;
		flagOut_ = true;
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
		isSceneChange_ = true;
		isClose_ = true;
	}
	if (sBoxR_ <= 0)
	{
		isOpen_ = false;
		isClose_ = false;
	}
}

void GameOver::Draw()
{
	Novice::DrawBox(int(menu_.pos.x), int(menu_.pos.y), int(menuW_ * scale), int(menuH_ * scale), 0.0f, WHITE, kFillModeSolid);
	Novice::DrawSprite(int(menu_.pos.x), int(menu_.pos.y), gameOver_, 0.782f, 0.84f, 0.0f, WHITE);

	//Novice::DrawBox(menu_.pos.x + 125, menu_.pos.y + 250, menuW_ - 725, menuH_ - 400, 0.0f, boxColorL_, kFillModeSolid);
	Novice::DrawSprite(int(menu_.pos.x + 125), int(menu_.pos.y + 250), retry_, 2.15f, 1.65f, 0.0f, boxColorL_);

	//Novice::DrawBox(menu_.pos.x + 605, menu_.pos.y + 250, menuW_ - 725, menuH_ - 400, 0.0f, boxColorR_, kFillModeSolid);
	Novice::DrawSprite(int(menu_.pos.x + 605), int(menu_.pos.y + 250), backSelect_, 2.15f, 1.65f, 0.0f, boxColorR_);

	if (isOpen_)
	{
		Novice::DrawEllipse(sBoxX_, sBoxY_, sBoxR_, sBoxR_, sBoxRotate_, BLACK, kFillModeSolid);
	}

	//Novice::ScreenPrintf(1000, 720, "flagOut : %d", flagOut_);
	//Novice::ScreenPrintf(1000, 740, "flagIn : %d", flagIn_);
	//Novice::ScreenPrintf(1000, 760, "isClose : %d", isClose_);
}