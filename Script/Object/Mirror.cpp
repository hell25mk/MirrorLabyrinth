#include "Mirror.h"
#include "DxLib.h"
#include "../System/Position.h"

const int Image_Size = 48;
const int Reflect_Space = 14;
const int FlashLoopTime = 180;
const int AnimeChange_Time = 30;
const int PlayerImage_X_Num = 12;
const int PlayerImage_Y_Num = 3;

C_Mirror::C_Mirror(C_Position argPos,int argImageType):C_BaseObject(argPos){

	mirrorImage = new int[PlayerImage_X_Num * PlayerImage_Y_Num];
	LoadDivGraph("Image/Object/PlayerMaterial.png", PlayerImage_X_Num * PlayerImage_Y_Num, PlayerImage_X_Num, PlayerImage_Y_Num, (Image_Size - 12), Image_Size, mirrorImage);
	imageType = argImageType;
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

void C_Mirror::Update(C_Position const argPos, e_Direction argDire){

	pos.x = argPos.x;
	pos.y = (Reflect_Space - (argPos.y / Block_Size)) * Block_Size;

	switch(argDire){
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
		DrawRotaGraph((pos.x + 16), (pos.y + 16), (Block_Size / (double)Image_Size), 0.0, mirrorImage[imageType + nowDire + animeImage], TRUE);
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