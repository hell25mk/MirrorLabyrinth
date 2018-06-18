#include "BaseObject.h"

const int C_BaseObject::Block_Size = 32;
const int C_BaseObject::BlockImage_X_Num = 5;
const int C_BaseObject::BlockImage_Y_Num = 3;

C_BaseObject::C_BaseObject(){
}

C_BaseObject::C_BaseObject(C_Position const argPos){

	pos = C_Position(argPos.x, argPos.y);

}


C_BaseObject::~C_BaseObject(){
}
