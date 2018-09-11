#include "BaseObject.h"

const int C_BaseObject::Block_Size = 32;

C_BaseObject::C_BaseObject(){
}

C_BaseObject::C_BaseObject(C_Position<int> const argPos){

	//ç¿ïWÇÃäiî[
	pos = argPos;

}

C_BaseObject::~C_BaseObject(){
}
