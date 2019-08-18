#include "Mirror.h"
#include "DxLib.h"
#include "../System/Position.h"
#include "../System/Animation.h"
#include "Player.h"
#include "../Define/Enum.h"

const int Reflect_Space = 14;
const int FlashLoopTime = 180;
const int AnimeChange_Time = 30;

/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="player">プレイヤーの変数を格納したポインタ</param>
Mirror::Mirror(Player* player):BaseCharacter(){

	this->player = player;
	pos.SetPosition(player->GetPosition().GetX(), (Reflect_Space - (player->GetPosition().GetY() / Block_Size)) * Block_Size);
	dire = Dire_Down * Image_Width;
	flashTime = 0;
	willFlash = true;
	int animeOrder[4] = { 0,1,0,2 };
	int orderSize = sizeof(animeOrder) / sizeof(animeOrder[0]);
	animation = new Animation(animeOrder, orderSize, AnimeChange_Time, &imageNumber);

}

/// <summary>
/// デストラクタ
/// </summary>
Mirror::~Mirror(){

	delete animation;

}

/// <summary>
/// 更新処理を行う
/// </summary>
void Mirror::Update(){

	animation->Update();
	Fhashing();

}

/// <summary>
/// 描画処理を行う
/// </summary>
void Mirror::Draw(){

	//点滅していないときだけ表示する
	if(willFlash){
		DrawRotaGraph((pos.GetDx() + 16), (pos.GetDy() + 16), (Block_Size / (double)Image_Size), 0.0, image[dire + imageNumber], TRUE);
	}

}

/// <summary>
/// プレイヤーの座標に対する場所に移動する
/// </summary>
void Mirror::Move(){

	pos.SetPosition(player->GetPosition().GetX(), (Reflect_Space - (player->GetPosition().GetY() / Block_Size)) * Block_Size);

}

/// <summary>
/// プレイヤーの向きに対する向きに変更する
/// </summary>
void Mirror::Direction(){

	int arrDire[4]{ Dire_Up ,Dire_Right ,Dire_Left ,Dire_Down };
	dire = arrDire[player->GetDirection() / Image_Width] * Image_Width;

}

/// <summary>
/// 点滅しているかどうかを切り替える
/// </summary>
void Mirror::Fhashing(){

	flashTime++;
	willFlash = flashTime < FlashLoopTime / 3;
	flashTime = flashTime % FlashLoopTime;

#ifdef _DEBUG
	//willFlash = true;
#endif //点滅無し

}