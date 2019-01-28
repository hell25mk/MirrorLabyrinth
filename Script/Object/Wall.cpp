#include "Wall.h"
#include "../Define/Enum.h"

const int Laby_Height = 15;
const int Laby_Width = 20;

Wall::Wall(Position<int> argPos):BaseBlock(argPos){

	imageKind = Laby_Wall;
	passFlag = false;

}

Wall::~Wall(){
}

void Wall::Update(){



}

void Wall::Draw(){

	DrawGraph((pos.GetDx() * Block_Size), (pos.GetDy() * Block_Size), image[Laby_Road], TRUE);

	//ŠO•Ç
	if(pos.GetY() == 0 || pos.GetY() == (Laby_Height - 1) || pos.GetX() == 0 || pos.GetX() == (Laby_Width - 1)){
		DrawGraph((pos.GetDx() * Block_Size), (pos.GetDy() * Block_Size), image[imageKind], TRUE);
		return;
	}

	//’†S‚©‚ç‰º‚©‚Ç‚¤‚©
	if((pos.GetY()) > (Laby_Height / 2)){
		DrawGraph((pos.GetDx() * Block_Size), (pos.GetDy() * Block_Size), image[Laby_Road], TRUE);
		return;
	}

	DrawGraph((pos.GetDx() * Block_Size), (pos.GetDy() * Block_Size), image[imageKind], TRUE);

}

bool Wall::HitAction(){

	return passFlag;
}
