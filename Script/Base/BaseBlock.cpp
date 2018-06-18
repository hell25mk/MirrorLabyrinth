#include "BaseBlock.h"

const int C_BaseBlock::Block_Size = 32;
const int C_BaseBlock::Image_X_Num = 5;
const int C_BaseBlock::Image_Y_Num = 3;

C_BaseBlock::C_BaseBlock() : C_BaseObject(pos){

	image = new int[BlockImage_X_Num * BlockImage_Y_Num];
	LoadDivGraph("Image/Object/LabyBlockMaterial.png", Image_X_Num * Image_Y_Num, Image_X_Num, Image_Y_Num, Block_Size, Block_Size, image);

}


C_BaseBlock::~C_BaseBlock(){

	delete image;

}
