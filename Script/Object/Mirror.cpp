#include "Mirror.h"
#include "DxLib.h"
#include "../System/Position.h"
#include "../System/Animation.h"
#include "Player.h"

const int Reflect_Space = 14;
const int FlashLoopTime = 180;
const int AnimeChange_Time = 30;

C_Mirror::C_Mirror(C_Position<int> argPos,C_Player *player):C_BaseCharacter(argPos){

	this->player = player;
	pos.x = player->GetPosition().x;
	pos.y = (Reflect_Space - (player->GetPosition().y / Block_Size)) * Block_Size;
	nowDire = (e_Direction)(Dire_Down * Image_X_Num);
	flashTime = 0;
	flashFlag = true;
	int animeOrder[4] = { 0,1,0,2 };
	int orderSize = sizeof(animeOrder) / sizeof(animeOrder[0]);
	animation = new C_Animation(animeOrder, orderSize, AnimeChange_Time, &imageNumber);

}

C_Mirror::~C_Mirror(){

	delete animation;

}

void C_Mirror::Update(){

	animation->Update();
	Fhashing();

}

void C_Mirror::Draw(){

	if(flashFlag){
		DrawRotaGraph((pos.x + 16), (pos.y + 16), (Block_Size / (double)Image_Size), 0.0, image[nowDire + imageNumber], TRUE);
	}

}

void C_Mirror::Move(){

	pos.x = player->GetPosition().x;
	pos.y = (Reflect_Space - (player->GetPosition().y / Block_Size)) * Block_Size;

	int dire = player->GetDirection();

	switch(dire){
		case Dire_Up:
			nowDire = (e_Direction)(Dire_Down * Image_X_Num);
			break;
		case Dire_Down:
			nowDire = (e_Direction)(Dire_Up * Image_X_Num);
			break;
		case Dire_Left:
			nowDire = (e_Direction)(Dire_Left * Image_X_Num);
			break;
		case Dire_Right:
			nowDire = (e_Direction)(Dire_Right * Image_X_Num);
			break;
	}

	animation->Change();

}

void C_Mirror::Fhashing(){

	flashTime++;

	flashFlag = flashTime < FlashLoopTime / 3;

	flashTime = flashTime % FlashLoopTime;

#ifdef _DEBUG
	flashFlag = true;
#endif //“_–Å–³‚µ

}