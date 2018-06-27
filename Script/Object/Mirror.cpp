#include "Mirror.h"
#include "DxLib.h"
#include "../System/Position.h"
#include "../System/Animation.h"
#include "Player.h"
#include "../Define/Enum.h"

const int Reflect_Space = 14;
const int FlashLoopTime = 180;
const int AnimeChange_Time = 30;

C_Mirror::C_Mirror(C_Player *player):C_BaseCharacter(){

	this->player = player;
	pos.x = player->GetPosition().x;
	pos.y = (Reflect_Space - (player->GetPosition().y / Block_Size)) * Block_Size;
	dire = Dire_Down * Image_Width;
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
		DrawRotaGraph((pos.x + 16), (pos.y + 16), (Block_Size / (double)Image_Size), 0.0, image[dire + imageNumber], TRUE);
	}

}

bool C_Mirror::HitAction(){

	return true;
}

void C_Mirror::Move(){

	pos.x = player->GetPosition().x;
	pos.y = (Reflect_Space - (player->GetPosition().y / Block_Size)) * Block_Size;

	int arrDire[4]{ Dire_Up ,Dire_Right ,Dire_Left ,Dire_Down };
	dire = arrDire[player->GetDirection() / Image_Width] * Image_Width;

}

void C_Mirror::Fhashing(){

	flashTime++;

	flashFlag = flashTime < FlashLoopTime / 3;

	flashTime = flashTime % FlashLoopTime;

#ifdef _DEBUG
	flashFlag = true;
#endif //“_–Å–³‚µ

}