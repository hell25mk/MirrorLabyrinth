#include "BaseCharacter.h"

const int BaseCharacter::Image_Size = 36;
const int BaseCharacter::Image_Width = 3;
const int BaseCharacter::Image_Height = 4;
const int BaseCharacter::AnimeChange_Time = 30;

int* BaseCharacter::image;

/// <summary>
/// �R���X�g���N�^
/// </summary>
BaseCharacter::BaseCharacter() : animation(), alivaFlag(true),dire(), imageNumber() {

	//NULL�Ȃ烁�����m��
	if (image == NULL) {
		image = new int[Image_Width * Image_Height];
		LoadDivGraph("Image/Object/PlayerMaterial.png", Image_Width * Image_Height, Image_Width, Image_Height, Image_Size, Image_Size, image);
	}

}

/// <summary>
/// �R���X�g���N�^
/// </summary>
/// <param name="argPos">���W</param>
BaseCharacter::BaseCharacter(Position<int> argPos):
	BaseObject(pos), animation(), alivaFlag(true), dire(), imageNumber() {

	//NULL�Ȃ烁�����m��
	if(image == NULL){
		image = new int[Image_Width * Image_Height];
		LoadDivGraph("Image/Object/PlayerMaterial.png", Image_Width * Image_Height, Image_Width, Image_Height, Image_Size, Image_Size, image);
	}

	alivaFlag = true;

}

/// <summary>
/// �f�X�g���N�^
/// </summary>
BaseCharacter::~BaseCharacter(){

	//�m�ۂ������������������
	if(image != NULL){
		delete[] image;
		image = NULL;
	}

}
