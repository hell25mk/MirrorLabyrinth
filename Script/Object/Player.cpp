#include "Player.h"
#include "DxLib.h"
#include "../System/Position.h"
#include "Mirror.h"
#include "../Manager/KeyboardManager.h"
#include "../System/GameInfo.h"
#include "../System/Animation.h"

const int AnimeChange_Time = 30;

C_Player::C_Player(C_Position argPos):C_BaseCharacter(argPos){

	pos.x = argPos.x * Block_Size;
	pos.y = argPos.y * Block_Size;
	nowDire = (e_Direction)(Dire_Up * Image_X_Num);
	mirror = new C_Mirror(pos,this);
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
	
	DrawRotaGraph(pos.x + 16, pos.y + 16, (Block_Size / (double)Image_Size), 0.0, image[nowDire + imageNumber], TRUE);

	mirror->Draw();

}

void C_Player::Move(int argMoveDire){

	switch(argMoveDire){
		case Dire_Up:
			pos.y -= Block_Size;
			break;
		case Dire_Down:
			pos.y += Block_Size;
			break;
		case Dire_Left:
			pos.x -= Block_Size;
			break;
		case Dire_Right:
			pos.x += Block_Size;
			break;
	}

	nowDire = (e_Direction)(argMoveDire * Image_X_Num);

	animation->Change();

}

C_Position C_Player::GetPosition(){

	return pos;
}

e_Direction C_Player::GetDirection(){

	return nowDire;
}