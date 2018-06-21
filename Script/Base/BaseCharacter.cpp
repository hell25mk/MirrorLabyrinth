#include "BaseCharacter.h"

const int C_BaseCharacter::Image_Size = 36;
const int C_BaseCharacter::Image_X_Num = 3;
const int C_BaseCharacter::Image_Y_Num = 4;
const int C_BaseCharacter::AnimeChange_Time = 30;

int* C_BaseCharacter::image;

C_BaseCharacter::C_BaseCharacter(C_Position argPos) : C_BaseObject(pos){

	if(image == NULL){
		image = new int[Image_X_Num * Image_Y_Num];
		LoadDivGraph("Image/Object/PlayerMaterial.png", Image_X_Num * Image_Y_Num, Image_X_Num, Image_Y_Num, Image_Size, Image_Size, image);
	}

}

C_BaseCharacter::~C_BaseCharacter(){

	image = NULL;

}
