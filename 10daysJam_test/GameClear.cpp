#include "GameClear.h"

void GameClear::Initialize()
{
	selectR_ = 0;
	selectL_ = 0;

	//テクスチャ
	gameClear_ = Novice::LoadTexture("./Resource/images/stageClear.png");
	retry_ = Novice::LoadTexture("./Resource/images/retry.png");
	backSelect_ = Novice::LoadTexture("./Resource/images/backSelect.png");
}

void GameClear::Update(bool flagIn)
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
		if (Novice::IsPlayingAudio(voiceHandle_[0]) == 0 || voiceHandle_[0] == -1)
		{
			voiceHandle_[0] = Novice::PlayAudio(audioHandle_[0], 0, 0.1f);
		}
	}
	else
	{
		boxColorL_ = WHITE;
		Novice::StopAudio(voiceHandle_[0]);
	}

	if (mousePosX_ >= menu_.pos.x + 605 && mousePosX_ <= menu_.pos.x + 605 + menuW_ - 725 && mousePosY_ >= menu_.pos.y + 250 && mousePosY_ <= menu_.pos.y + 250 + menuH_ - 400)
	{
		boxColorR_ = BLUE;
		if (Novice::IsPlayingAudio(voiceHandle_[1]) == 0 || voiceHandle_[1] == -1)
		{
			voiceHandle_[1] = Novice::PlayAudio(audioHandle_[1], 0, 0.1f);
		}
	}
	else
	{
		boxColorR_ = WHITE;
		Novice::StopAudio(voiceHandle_[1]);
	}

	if (boxColorL_ == BLUE && Novice::IsPressMouse(0) && !selectR_ && flame_ >= 80)
	{
		if (Novice::IsPlayingAudio(voiceHandle_[2]) == 0 || voiceHandle_[2] == -1)
		{
			voiceHandle_[2] = Novice::PlayAudio(audioHandle_[2], 0, 0.1f);
		}
		selectL_ = true;
		flagOut_ = true;
	}
	if (boxColorR_ == BLUE && Novice::IsPressMouse(0) && !selectL_ && flame_ >= 80)
	{
		if (Novice::IsPlayingAudio(voiceHandle_[2]) == 0 || voiceHandle_[2] == -1)
		{
			voiceHandle_[2] = Novice::PlayAudio(audioHandle_[2], 0, 0.1f);
		}
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

void GameClear::Draw()
{

	Novice::DrawBox(int(menu_.pos.x), int(menu_.pos.y), int(menuW_ * scale), int(menuH_ * scale), 0.0f, WHITE, kFillModeSolid);
	Novice::DrawSprite(int(menu_.pos.x), int(menu_.pos.y), gameClear_, 0.782f, 0.84f, 0.0f, WHITE);

	//Novice::DrawBox(menu_.pos.x + 125, menu_.pos.y + 250, menuW_ - 725, menuH_ - 400, 0.0f, boxColorL_, kFillModeSolid);
	Novice::DrawSprite(int(menu_.pos.x + 125), int(menu_.pos.y + 250), retry_, 2.15f, 1.65f, 0.0f, boxColorL_);

	//Novice::DrawBox(menu_.pos.x + 605, menu_.pos.y + 250, menuW_ - 725, menuH_ - 400, 0.0f, boxColorR_, kFillModeSolid);
	Novice::DrawSprite(int(menu_.pos.x + 605), int(menu_.pos.y + 250), backSelect_, 2.15f, 1.65f, 0.0f, boxColorR_);

	if (isOpen_)
	{
		Novice::DrawEllipse(sBoxX_, sBoxY_, sBoxR_, sBoxR_, sBoxRotate_, BLACK, kFillModeSolid);
	}

	//Novice::ScreenPrintf(1000, 760, "isClose : %d", isClose_);

}