#include "Player.h"
#include "DxLib.h"
#include "../System/Position.h"
#include "Mirror.h"
#include "../Manager/KeyboardManager.h"
#include "../System/GameInfo.h"

const int Image_Size = 48;
const int PlayerImage_X_Num = 12;
const int PlayerImage_Y_Num = 3;
const int AnimeChange_Time = 30;

C_Player::C_Player(C_Position argPos):C_BaseObject(argPos){

	playerImage = new int[PlayerImage_X_Num * PlayerImage_Y_Num];
	LoadDivGraph("Image/Object/PlayerMaterial.png", PlayerImage_X_Num * PlayerImage_Y_Num, PlayerImage_X_Num, PlayerImage_Y_Num, (Image_Size - 12), Image_Size, playerImage);

	pos.x = pos.x * Block_Size;
	pos.y = pos.y * Block_Size;

	imageType = C_GameInfo::GetInstance().GetImageType() * PlayerImage_X_Num;
	nowDire = Dire_Up;
	
	animeTime = 0;
	animeImage = 0;
	animeChangeFlag = true;
	moveFlag = false;
	
	mirror = new C_Mirror(pos ,imageType);

}

C_Player::~C_Player(){

	delete mirror;
	delete[] playerImage;

}

void C_Player::Update(){

	Animation();

	mirror->Update(pos, (e_Direction)(nowDire / 3));

}

void C_Player::Draw(){
	
	DrawRotaGraph(pos.x + 16, pos.y + 16, (Block_Size / (double)Image_Size), 0.0, playerImage[imageType + nowDire + animeImage], TRUE);

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