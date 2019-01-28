#include "BaseBlock.h"

const int BaseBlock::Image_Width = 5;
const int BaseBlock::Image_Height = 3;

int* BaseBlock::image;

BaseBlock::BaseBlock(){

	//NULL�Ȃ烁�����m��
	if(image == NULL){
		image = new int[Image_Width * Image_Height];
		LoadDivGraph("Image/Object/LabyBlockMaterial.png", Image_Width * Image_Height, Image_Width, Image_Height, Block_Size, Block_Size, image);
	}

	passFlag = true;

}

BaseBlock::BaseBlock(Position<int> argPos):BaseObject(argPos){

	//NULL�Ȃ烁�����m��
	if(image == NULL){
		image = new int[Image_Width * Image_Height];
		LoadDivGraph("Image/Object/LabyBlockMaterial.png", Image_Width * Image_Height, Image_Width, Image_Height, Block_Size, Block_Size, image);
	}

	passFlag = true;

}

BaseBlock::~BaseBlock(){

	//�m�ۂ������������������
	if(image != NULL){
		delete[] image;
		image = NULL;
	}

}