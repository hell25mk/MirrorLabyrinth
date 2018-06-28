#include "Road.h"
#include "../System/Position.h"
#include "../Define/Enum.h"

C_Road::C_Road(C_Position<int> argPos):C_BaseBlock(argPos){

	imageKind = Laby_Road;

}

C_Road::~C_Road(){
}

void C_Road::Update(){



}

void C_Road::Draw(){

	DrawGraph((pos.GetDx() * Block_Size), (pos.GetDy() * Block_Size), image[imageKind], TRUE);

}

bool C_Road::HitAction(){

	return passFlag;
}