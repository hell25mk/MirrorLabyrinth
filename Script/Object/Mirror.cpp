#include "Mirror.h"
#include "DxLib.h"
#include "../System/Position.h"
#include "../System/Animation.h"
#include "Player.h"
#include "../Define/Enum.h"

const int Reflect_Space = 14;
const int FlashLoopTime = 180;
const int AnimeChange_Time = 30;

Mirror::Mirror(Player *player):BaseCharacter(){

	this->player = player;
	pos.SetPosition(player->GetPosition().GetX(), (Reflect_Space - (player->GetPosition().GetY() / Block_Size)) * Block_Size);
	dire = Dire_Down * Image_Width;
	flashTime = 0;
	flashFlag = true;
	int animeOrder[4] = { 0,1,0,2 };
	int orderSize = sizeof(animeOrder) / sizeof(animeOrder[0]);
	animation = new Animation(animeOrder, orderSize, AnimeChange_Time, &imageNumber);

}

Mirror::~Mirror(){

	delete animation;

}

void Mirror::Update(){

	animation->Update();
	Fhashing();

}

void Mirror::Draw(){

	if(flashFlag){
		DrawRotaGraph((pos.GetDx() + 16), (pos.GetDy() + 16), (Block_Size / (double)Image_Size), 0.0, image[dire + imageNumber], TRUE);
	}

}

void Mirror::Move(){

	pos.SetPosition(player->GetPosition().GetX(), (Reflect_Space - (player->GetPosition().GetY() / Block_Size)) * Block_Size);

}

void Mirror::Direction(){

	int arrDire[4]{ Dire_Up ,Dire_Right ,Dire_Left ,Dire_Down };
	dire = arrDire[player->GetDirection() / Image_Width] * Image_Width;

}

void Mirror::Fhashing(){

	flashTime++;
	flashFlag = flashTime < FlashLoopTime / 3;
	flashTime = flashTime % FlashLoopTime;

#ifdef _DEBUG
	//flashFlag = true;
#endif //“_–Å–³‚µ

}