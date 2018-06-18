#include "BaseCharacter.h"

const int C_BaseCharacter::Image_Size = 36;
const int C_BaseCharacter::Image_X_Num = 4;
const int C_BaseCharacter::Image_Y_Num = 1;
const int C_BaseCharacter::AnimeChange_Time = 30;

C_BaseCharacter::C_BaseCharacter() : C_BaseObject(pos){

	image = new int[PlayerImage_X_Num * PlayerImage_Y_Num];
	LoadDivGraph("Image/Object/PlayerMaterial.png", Image_X_Num * Image_Y_Num, Image_X_Num, Image_Y_Num, Image_Size, Image_Size, image);

}

C_BaseCharacter::~C_BaseCharacter(){

	delete[] image;

}
