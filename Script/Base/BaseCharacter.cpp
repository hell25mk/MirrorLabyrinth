#include "BaseCharacter.h"

const int BaseCharacter::Image_Size = 36;
const int BaseCharacter::Image_Width = 3;
const int BaseCharacter::Image_Height = 4;
const int BaseCharacter::AnimeChange_Time = 30;

int* BaseCharacter::image;

BaseCharacter::BaseCharacter(){

	//NULL�Ȃ烁�����m��
	if(image == NULL){
		image = new int[Image_Width * Image_Height];
		LoadDivGraph("Image/Object/PlayerMaterial.png", Image_Width * Image_Height, Image_Width, Image_Height, Image_Size, Image_Size, image);
	}

	alivaFlag = true;

}

BaseCharacter::BaseCharacter(Position<int> argPos):BaseObject(pos){

	//NULL�Ȃ烁�����m��
	if(image == NULL){
		image = new int[Image_Width * Image_Height];
		LoadDivGraph("Image/Object/PlayerMaterial.png", Image_Width * Image_Height, Image_Width, Image_Height, Image_Size, Image_Size, image);
	}

	alivaFlag = true;

}

BaseCharacter::~BaseCharacter(){

	//�m�ۂ������������������
	if(image != NULL){
		delete[] image;
		image = NULL;
	}

}
