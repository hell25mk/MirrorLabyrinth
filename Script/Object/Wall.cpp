#include "Wall.h"

C_Wall::C_Wall(C_Position<int> argPos):C_BaseBlock(argPos){
}

C_Wall::~C_Wall(){
}

void C_Wall::Update(){



}

void C_Wall::Draw(){

	DrawGraph((pos.x * Block_Size), (pos.y * Block_Size), image[0], TRUE);
	DrawGraph((pos.x * Block_Size), (pos.y * Block_Size), image[1], TRUE);

}

void C_Wall::HitAction(){



}
