#include "BaseObject.h"

const int BaseObject::Block_Size = 32;

BaseObject::BaseObject(){
}

BaseObject::BaseObject(Position<int> const argPos){

	//ç¿ïWÇÃäiî[
	pos = argPos;

}

BaseObject::~BaseObject(){
}
