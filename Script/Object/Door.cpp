#include "Door.h"
#include "DxLib.h"
#include "../System/Position.h"
#include "../Define/Enum.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
/// <param name="argPos">���W</param>
/// <param name="maxKeyNum">���̍ő吔���i�[�����|�C���^</param>
/// <param name="getKeyNum">�擾�������̐����i�[�����|�C���^</param>
Door::Door(Position<int> argPos, const int *maxKeyNum, int *getKeyNum):BaseBlock(argPos){

	this->maxKeyNum = maxKeyNum;
	this->getKeyNum = getKeyNum;
	imageKind = Laby_CloseDoor;
	canMove = false;

}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Door::~Door(){
}

/// <summary>
/// �X�V�������s��
/// </summary>
void Door::Update(){

	//�擾�������̐������̍ő吔�ɂȂ����ꍇ�ƒʂ��悤�ɂ���
	if(*maxKeyNum == *getKeyNum){
		canMove = true;
		imageKind = Laby_OpenDoor;
	}

}

/// <summary>
/// �`�揈�����s��
/// </summary>
void Door::Draw(){

	DrawGraph((pos.GetDx() * Block_Size), (pos.GetDy() * Block_Size), image[Laby_Road], TRUE);
	DrawGraph((pos.GetDx() * Block_Size), (pos.GetDy() * Block_Size), image[imageKind], TRUE);
	
}

/// <summary>
/// �I�u�W�F�N�g�ɓ����������̃A�N�V��������
/// </summary>
/// <returns>���̃I�u�W�F�N�g���ʉ߂ł���ꍇtrue</returns>
bool Door::HitAction(){

	return canMove;
}