#include "Wall.h"

C_Wall::C_Wall(C_Position argPos):C_BaseObject(argPos){
}

C_Wall::~C_Wall(){
}

void C_Wall::Draw(){

	DrawGraph((pos.x * Block_Size), (pos.y * Block_Size), image[0], TRUE);

}
