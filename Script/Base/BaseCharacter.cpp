#include "BaseCharacter.h"

const int BaseCharacter::Image_Size = 36;
const int BaseCharacter::Image_Width = 3;
const int BaseCharacter::Image_Height = 4;
const int BaseCharacter::AnimeChange_Time = 30;

int* BaseCharacter::image;

/// <summary>
/// メンバを初期化する
/// </summary>
BaseCharacter::BaseCharacter() : animation(), dire(), imageNumber() {

	//NULLならメモリ確保
	if (image == NULL) {
		image = new int[Image_Width * Image_Height];
		LoadDivGraph("Image/Object/PlayerMaterial.png", Image_Width * Image_Height, Image_Width, Image_Height, Image_Size, Image_Size, image);
	}

}

/// <summary>
/// メンバを初期化する
/// </summary>
/// <param name="argPos">座標</param>
BaseCharacter::BaseCharacter(Position<int> argPos):
	BaseObject(pos), animation(), dire(), imageNumber() {

	//NULLならメモリ確保
	if(image == NULL){
		image = new int[Image_Width * Image_Height];
		LoadDivGraph("Image/Object/PlayerMaterial.png", Image_Width * Image_Height, Image_Width, Image_Height, Image_Size, Image_Size, image);
	}

}

/// <summary>
/// メモリを確保していた場合は解放する
/// </summary>
BaseCharacter::~BaseCharacter(){

	//確保したメモリを解放する
	if(image != NULL){
		delete[] image;
		image = NULL;
	}

}
