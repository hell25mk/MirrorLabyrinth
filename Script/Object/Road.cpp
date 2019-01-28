#include "Road.h"
#include "../System/Position.h"
#include "../Define/Enum.h"

Road::Road(Position<int> argPos):BaseBlock(argPos){

	imageKind = Laby_Road;

}

Road::~Road(){
}

void Road::Update(){



}

void Road::Draw(){

	DrawGraph((pos.GetDx() * Block_Size), (pos.GetDy() * Block_Size), image[imageKind], TRUE);

}

bool Road::HitAction(){

	return passFlag;
}