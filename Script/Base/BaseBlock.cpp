#include "BaseBlock.h"

const int BaseBlock::Image_Width = 5;
const int BaseBlock::Image_Height = 3;

int* BaseBlock::image;

BaseBlock::BaseBlock(){

	//NULL‚È‚çƒƒ‚ƒŠŠm•Û
	if(image == NULL){
		image = new int[Image_Width * Image_Height];
		LoadDivGraph("Image/Object/LabyBlockMaterial.png", Image_Width * Image_Height, Image_Width, Image_Height, Block_Size, Block_Size, image);
	}

	passFlag = true;

}

BaseBlock::BaseBlock(Position<int> argPos):BaseObject(argPos){

	//NULL‚È‚çƒƒ‚ƒŠŠm•Û
	if(image == NULL){
		image = new int[Image_Width * Image_Height];
		LoadDivGraph("Image/Object/LabyBlockMaterial.png", Image_Width * Image_Height, Image_Width, Image_Height, Block_Size, Block_Size, image);
	}

	passFlag = true;

}

BaseBlock::~BaseBlock(){

	//Šm•Û‚µ‚½ƒƒ‚ƒŠ‚ğ‰ğ•ú‚·‚é
	if(image != NULL){
		delete[] image;
		image = NULL;
	}

}