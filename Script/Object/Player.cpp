#include "Player.h"
#include "DxLib.h"
#include "../System/Position.h"
#include "../Manager/KeyboardManager.h"
#include "../System/GameInfo.h"
#include "../System/Animation.h"

const int AnimeChange_Time = 30;

/// <summary>
/// メンバを初期化する
/// </summary>
/// <param name="argPos">座標</param>
Player::Player(Position<int> argPos):BaseCharacter(argPos){

	pos.SetPosition(argPos.GetX() * Block_Size, argPos.GetY() * Block_Size);
	dire = Dire_Up * Image_Width;
	imageNumber = 0;
	int animeOrder[4] = { 0,1,0,2 };
	int orderSize = sizeof(animeOrder) / sizeof(animeOrder[0]);
	animation = new Animation(animeOrder, orderSize, AnimeChange_Time, &imageNumber);

}

/// <summary>
/// メモリを確保していた場合は解放する
/// </summary>
Player::~Player(){

	delete animation;

}

/// <summary>
/// 1ループ内で必要な更新処理を行う
/// </summary>
void Player::Update(){

	animation->Update();

}

/// <summary>
/// 1ループ内で必要な描画処理を行う
/// </summary>
void Player::Draw(){
	
	DrawRotaGraph(pos.GetDx() + 16, pos.GetDy() + 16, (Block_Size / (double)Image_Size), 0.0, image[dire + imageNumber], TRUE);

}

/// <summary>
/// 座標を更新する
/// </summary>
/// <param name="argMoveDire">移動する方向</param>
void Player::Move(int argMoveDire){

	int vy[4] = { Block_Size,0,0,-Block_Size };		//y移動量
	int vx[4] = { 0,Block_Size,-Block_Size,0 };		//x移動量

	pos.SetPosition(pos.GetX() + vx[argMoveDire], pos.GetY() + vy[argMoveDire]);

}

/// <summary>
/// 向きを更新する
/// </summary>
/// <param name="argMoveDire">移動する方向</param>
void Player::Direction(int argMoveDire){

	dire = argMoveDire * Image_Width;

}

/// <summary>
/// 座標を取得する
/// </summary>
/// <returns>プレイヤーの座標</returns>
Position<int> Player::GetPosition(){

	return pos;
}

/// <summary>
/// 向きを取得する
/// </summary>
/// <returns>プレイヤーの向き</returns>
int Player::GetDirection(){

	return dire;
}