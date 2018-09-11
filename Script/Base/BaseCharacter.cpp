#include "BaseCharacter.h"

const int C_BaseCharacter::Image_Size = 36;
const int C_BaseCharacter::Image_Width = 3;
const int C_BaseCharacter::Image_Height = 4;
const int C_BaseCharacter::AnimeChange_Time = 30;

int* C_BaseCharacter::image;

C_BaseCharacter::C_BaseCharacter(){

	//NULL�Ȃ烁�����m��
	if(image == NULL){
		image = new int[Image_Width * Image_Height];
		LoadDivGraph("Image/Object/PlayerMaterial.png", Image_Width * Image_Height, Image_Width, Image_Height, Image_Size, Image_Size, image);
	}

	alivaFlag = true;

}

C_BaseCharacter::C_BaseCharacter(C_Position<int> argPos):C_BaseObject(pos){

	//NULL�Ȃ烁�����m��
	if(image == NULL){
		image = new int[Image_Width * Image_Height];
		LoadDivGraph("Image/Object/PlayerMaterial.png", Image_Width * Image_Height, Image_Width, Image_Height, Image_Size, Image_Size, image);
	}

	alivaFlag = true;

}

C_BaseCharacter::~C_BaseCharacter(){

	//�m�ۂ������������������
	if(image != NULL){
		delete[] image;
		image = NULL;
	}

}
