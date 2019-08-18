#include "Timer.h"
#include "DxLib.h"
#include "../System/GameInfo.h"

const int Color_White = GetColor(255, 255, 255);
const int Color_Red = GetColor(255, 0, 0);

//1ステージの最大持ち時間
const int Timer::BasisTime = 60;

/// <summary>
/// コンストラクタ
/// </summary>
Timer::Timer() : startTime(0),second(0),minute(0){

	nowGameTime = BasisTime  / (GameInfo::GetInstance().GetGameLevel() + 1);		//ゲーム難易度によって制限時間の変更

}

/// <summary>
/// デストラクタ
/// </summary>
Timer::~Timer(){
}

/// <summary>
/// 更新処理を行う
/// </summary>
void Timer::Update(){

	if(startTime == 0){
		startTime = GetNowCount();
	}

	//1秒を計測
	bool oneSecondFlag = GetNowCount() - startTime >= 1000;
	if(oneSecondFlag){
		nowGameTime = nowGameTime - 1;
		startTime = GetNowCount();
	}

	//分と秒に変換
	minute = nowGameTime / 60;
	second = nowGameTime % 60;

}

/// <summary>
/// 描画処理を行う
/// </summary>
void Timer::Draw(){

	SetFontSize(36);

	DrawFormatString(720, 100, Color_White, "Limit");

	//残り時間が10秒を切ったら赤色で表示する
	bool drawTimeFlag = nowGameTime < 10;
	if(drawTimeFlag){
		DrawFormatString(700, 150, Color_Red, "%02d : %02d", minute, second);
	} else{
		DrawFormatString(700, 150, Color_White, "%02d : %02d", minute, second);
	}

	SetFontSize(DEFAULT_FONT_SIZE);

}

/// <summary>
/// 現在の進行時間を取得
/// </summary>
/// <returns>進行後の時間</returns>
int Timer::GetGameTimer(){

	return nowGameTime;
}