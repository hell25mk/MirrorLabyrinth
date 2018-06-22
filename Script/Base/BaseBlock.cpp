#include "BaseBlock.h"

const int C_BaseBlock::Image_Width = 5;
const int C_BaseBlock::Image_Height = 3;

int* C_BaseBlock::image;

C_BaseBlock::C_BaseBlock(){



}

C_BaseBlock::C_BaseBlock(C_Position<int> argPos):C_BaseObject(argPos){

	if(image == NULL){
		image = new int[Image_Width * Image_Height];
		LoadDivGraph("Image/Object/LabyBlockMaterial.png", Image_Width * Image_Height, Image_Width, Image_Height, Block_Size, Block_Size, image);
	}

}

C_BaseBlock::~C_BaseBlock(){

	image = NULL;

}