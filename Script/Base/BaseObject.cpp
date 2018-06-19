#include "BaseObject.h"

const int C_BaseObject::Block_Size = 32;

C_BaseObject::C_BaseObject(){
}

C_BaseObject::C_BaseObject(C_Position const argPos){

	pos = C_Position(argPos.x, argPos.y);

}


C_BaseObject::~C_BaseObject(){
}
