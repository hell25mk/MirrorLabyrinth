#include "BaseBlock.h"

const int BaseBlock::Image_Width = 5;
const int BaseBlock::Image_Height = 3;

int* BaseBlock::image;

/// <summary>
/// �����o������������
/// </summary>
BaseBlock::BaseBlock() : imageKind(){

	//NULL�Ȃ烁�����m��
	if(image == NULL){
		image = new int[Image_Width * Image_Height];
		LoadDivGraph("Image/Object/LabyBlockMaterial.png", Image_Width * Image_Height, Image_Width, Image_Height, Block_Size, Block_Size, image);
	}

	canMove = true;

}

/// <summary>
/// �����o������������
/// </summary>
/// <param name="argPos">���W</param>
BaseBlock::BaseBlock(Position<int> argPos):BaseObject(argPos), imageKind() {

	//NULL�Ȃ烁�����m��
	if(image == NULL){
		image = new int[Image_Width * Image_Height];
		LoadDivGraph("Image/Object/LabyBlockMaterial.png", Image_Width * Image_Height, Image_Width, Image_Height, Block_Size, Block_Size, image);
	}

	canMove = true;

}

/// <summary>
/// ���������m�ۂ��Ă����ꍇ�͉������
/// </summary>
BaseBlock::~BaseBlock(){

	//�m�ۂ������������������
	if(image != NULL){
		delete[] image;
		image = NULL;
	}

}