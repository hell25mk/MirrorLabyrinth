#include "Road.h"
#include "../System/Position.h"


C_Road::C_Road(C_Position argPos):C_BaseBlock(argPos){
}


C_Road::~C_Road(){
}

void C_Road::Update(){



}

void C_Road::Draw(){

	DrawGraph((pos.x * Block_Size), (pos.y * Block_Size), image[0], TRUE);

}