#include "BaseObject.h"

const int BaseObject::Block_Size = 32;

BaseObject::BaseObject(){
}

BaseObject::BaseObject(Position<int> const argPos){

	//���W�̊i�[
	pos = argPos;

}

BaseObject::~BaseObject(){
}
