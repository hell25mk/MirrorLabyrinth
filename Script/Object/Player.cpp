#include "Player.h"
#include "DxLib.h"
#include "../System/Position.h"
#include "Mirror.h"
#include "../Manager/KeyboardManager.h"
#include "../System/GameInfo.h"

const int AnimeChange_Time = 30;

C_Player::C_Player(C_Position argPos):C_BaseCharacter(argPos){

	pos.x = argPos.x * Block_Size;
	pos.y = argPos.y * Block_Size;

	nowDire = Dire_Up;
	animeTime = 0;
	animeImage = 0;
	animeChangeFlag = true;
	moveFlag = false;
	
	mirror = new C_Mirror(pos,this);

}

C_Player::~C_Player(){

	delete mirror;

}

void C_Player::Update(){

	Animation();

	mirror->Update();

}

void C_Player::Draw(){
	
	DrawRotaGraph(pos.x + 16, pos.y + 16, (Block_Size / (double)Image_Size), 0.0, image[nowDire + animeImage], TRUE);

	mirror->Draw();

}

void C_Player::Move(int argMoveDire){

	switch(argMoveDire){
		case Dire_Up:
			pos.y -= Block_Size;
			nowDire = (e_Direction)(Dire_Up * 3);
			break;
		case Dire_Down:
			pos.y += Block_Size;
			nowDire = (e_Direction)(Dire_Down * 3);
			break;
		case Dire_Left:
			pos.x -= Block_Size;
			nowDire = (e_Direction)(Dire_Left * 3);
			break;
		case Dire_Right:
			pos.x += Block_Size;
			nowDire = (e_Direction)(Dire_Right * 3);
			break;
	}

	moveFlag = true;

}

void C_Player::Animation(){

	if(moveFlag){
		animeTime = 0;
		animeImage = 0;
		animeChangeFlag = true;
		moveFlag = false;
	}

	animeTime++;

	if(animeTime % AnimeChange_Time != 0){
		return;
	}

	if(animeChangeFlag){
		animeImage++;
	} else{
		animeImage--;
	}

	if(animeTime != AnimeChange_Time * 2){
		return;
	}

	animeChangeFlag = !animeChangeFlag;
	animeTime = 0;

}

C_Position C_Player::GetPosition(){

	return pos;
}

e_Direction C_Player::GetDirection(){

	return nowDire;
}