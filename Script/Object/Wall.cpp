#include "Wall.h"

C_Wall::C_Wall(C_Position argPos):C_BaseBlock(argPos){
}

C_Wall::~C_Wall(){
}

void C_Wall::Update(){



}

void C_Wall::Draw(){

	DrawGraph((pos.x * Block_Size), (pos.y * Block_Size), image[0], TRUE);

}
