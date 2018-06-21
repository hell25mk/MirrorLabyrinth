#include "Mirror.h"
#include "DxLib.h"
#include "../System/Position.h"
#include "Player.h"

const int Reflect_Space = 14;
const int FlashLoopTime = 180;
const int AnimeChange_Time = 30;

C_Mirror::C_Mirror(C_Position argPos,C_Player *player):C_BaseCharacter(argPos){

	this->player = player;
	nowDire = Dire_Down;

	flashTime = 0;
	flashFlag = true;

	animeTime = 0;
	animeImage = 0;
	animeChangeFlag = true;
	moveFlag = false;

}

C_Mirror::~C_Mirror(){
}

void C_Mirror::Update(){

	pos.x = player->GetPosition().x;
	pos.y = (Reflect_Space - (player->GetPosition().y / Block_Size)) * Block_Size;

	switch(player->GetDirection()){
		case Dire_Up:
			nowDire = (e_Direction)(Dire_Down * 3);
			break;
		case Dire_Down:
			nowDire = (e_Direction)(Dire_Up * 3);
			break;
		case Dire_Left:
			nowDire = (e_Direction)(Dire_Left * 3);
			break;
		case Dire_Right:
			nowDire = (e_Direction)(Dire_Right * 3);
			break;
	}

	Animation();
	Fhashing();

}

void C_Mirror::Draw(){

	if(flashFlag){
		DrawRotaGraph((pos.x + 16), (pos.y + 16), (Block_Size / (double)Image_Size), 0.0, image[nowDire + animeImage], TRUE);
	}

}

void C_Mirror::Animation(){

	if(moveFlag){
		animeTime = 0;
		animeImage = 0;
		animeChangeFlag = true;
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

void C_Mirror::Fhashing(){

	flashTime++;

	flashFlag = flashTime < FlashLoopTime / 3;

	flashTime = flashTime % FlashLoopTime;

#ifdef _DEBUG
	flashFlag = true;
#endif //“_–Å–³‚µ

}