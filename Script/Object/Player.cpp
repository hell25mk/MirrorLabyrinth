#include "Player.h"
#include "DxLib.h"
#include "../System/Position.h"
#include "Mirror.h"
#include "../Manager/KeyboardManager.h"
#include "../System/GameInfo.h"
#include "../System/Animation.h"

const int AnimeChange_Time = 30;

C_Player::C_Player(C_Position<int> argPos):C_BaseCharacter(argPos){

	pos.x = argPos.x * Block_Size;
	pos.y = argPos.y * Block_Size;
	dire = Dire_Up * Image_Width;
	mirror = new C_Mirror(this);
	imageNumber = 0;
	int animeOrder[4] = { 0,1,0,2 };
	int orderSize = sizeof(animeOrder) / sizeof(animeOrder[0]);
	animation = new C_Animation(animeOrder, orderSize, AnimeChange_Time, &imageNumber);

}

C_Player::~C_Player(){

	delete animation;
	delete mirror;

}

void C_Player::Update(){

	animation->Update();

	mirror->Update();

}

void C_Player::Draw(){
	
	DrawRotaGraph(pos.x + 16, pos.y + 16, (Block_Size / (double)Image_Size), 0.0, image[dire + imageNumber], TRUE);

	mirror->Draw();

}

void C_Player::Move(int argMoveDire){

	int vy[4] = { Block_Size,0,0,-Block_Size };		//yˆÚ“®—Ê
	int vx[4] = { 0,Block_Size,-Block_Size,0 };		//xˆÚ“®—Ê

	pos.y += vy[argMoveDire];
	pos.x += vx[argMoveDire];
	dire = argMoveDire * Image_Width;
	mirror->Move();

}

C_Position<int> C_Player::GetPosition(){

	return pos;
}

int C_Player::GetDirection(){

	return dire;
}