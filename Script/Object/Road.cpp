#include "Road.h"
#include "../System/Position.h"
#include "../Define/Enum.h"

C_Road::C_Road(C_Position<int> argPos):C_BaseBlock(argPos){

	imageKind = Laby_Wall;

}

C_Road::~C_Road(){
}

void C_Road::Update(){



}

void C_Road::Draw(){

	DrawGraph((pos.x * Block_Size), (pos.y * Block_Size), image[imageKind], TRUE);

}

void C_Road::HitAction(){



}