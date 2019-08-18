#include "BaseBlock.h"

const int BaseBlock::Image_Width = 5;
const int BaseBlock::Image_Height = 3;

int* BaseBlock::image;

/// <summary>
/// コンストラクタ
/// </summary>
BaseBlock::BaseBlock() : imageKind(){

	//NULLならメモリ確保
	if(image == NULL){
		image = new int[Image_Width * Image_Height];
		LoadDivGraph("Image/Object/LabyBlockMaterial.png", Image_Width * Image_Height, Image_Width, Image_Height, Block_Size, Block_Size, image);
	}

	canMove = true;

}

/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="argPos">座標</param>
BaseBlock::BaseBlock(Position<int> argPos):BaseObject(argPos), imageKind() {

	//NULLならメモリ確保
	if(image == NULL){
		image = new int[Image_Width * Image_Height];
		LoadDivGraph("Image/Object/LabyBlockMaterial.png", Image_Width * Image_Height, Image_Width, Image_Height, Block_Size, Block_Size, image);
	}

	canMove = true;

}

/// <summary>
/// デストラクタ
/// </summary>
BaseBlock::~BaseBlock(){

	//確保したメモリを解放する
	if(image != NULL){
		delete[] image;
		image = NULL;
	}

}