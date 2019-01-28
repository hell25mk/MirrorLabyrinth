#include "Player.h"
#include "DxLib.h"
#include "../System/Position.h"
#include "../Manager/KeyboardManager.h"
#include "../System/GameInfo.h"
#include "../System/Animation.h"

const int AnimeChange_Time = 30;

Player::Player(Position<int> argPos):BaseCharacter(argPos){

	pos.SetPosition(argPos.GetX() * Block_Size, argPos.GetY() * Block_Size);
	dire = Dire_Up * Image_Width;
	imageNumber = 0;
	int animeOrder[4] = { 0,1,0,2 };
	int orderSize = sizeof(animeOrder) / sizeof(animeOrder[0]);
	animation = new Animation(animeOrder, orderSize, AnimeChange_Time, &imageNumber);

}

Player::~Player(){

	delete animation;

}

void Player::Update(){

	animation->Update();

}

void Player::Draw(){
	
	DrawRotaGraph(pos.GetDx() + 16, pos.GetDy() + 16, (Block_Size / (double)Image_Size), 0.0, image[dire + imageNumber], TRUE);

}

void Player::Move(int argMoveDire){

	int vy[4] = { Block_Size,0,0,-Block_Size };		//yˆÚ“®—Ê
	int vx[4] = { 0,Block_Size,-Block_Size,0 };		//xˆÚ“®—Ê

	pos.SetPosition(pos.GetX() + vx[argMoveDire], pos.GetY() + vy[argMoveDire]);

}

void Player::Direction(int argMoveDire){

	dire = argMoveDire * Image_Width;

}

Position<int> Player::GetPosition(){

	return pos;
}

int Player::GetDirection(){

	return dire;
}