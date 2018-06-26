#include "Wall.h"
#include "../Define/Enum.h"

const int Laby_Height = 15;
const int Laby_Width = 20;

C_Wall::C_Wall(C_Position<int> argPos):C_BaseBlock(argPos){

	imageKind = Laby_Wall;
	passFlag = false;

}

C_Wall::~C_Wall(){
}

void C_Wall::Update(){



}

void C_Wall::Draw(){

	DrawGraph((pos.x * Block_Size), (pos.y * Block_Size), image[Laby_Road], TRUE);

	//ŠO•Ç
	if(pos.y == 0 || pos.y == (Laby_Height - 1) || pos.x == 0 || pos.x == (Laby_Width - 1)){
		DrawGraph((pos.x * Block_Size), (pos.y * Block_Size), image[imageKind], TRUE);
		return;
	}

	//’†S‚©‚ç‰º‚©‚Ç‚¤‚©
	if((pos.y) > (Laby_Height / 2)){
		DrawGraph((pos.x * Block_Size), (pos.y * Block_Size), image[Laby_Road], TRUE);
		return;
	}

	DrawGraph((pos.x * Block_Size), (pos.y * Block_Size), image[imageKind], TRUE);

}

bool C_Wall::HitAction(){

	return passFlag;
}
