#include "Wall.h"
#include "../Define/Enum.h"

const int Laby_Height = 15;
const int Laby_Width = 20;

/// <summary>
/// �R���X�g���N�^
/// </summary>
/// <param name="argPos">���W</param>
Wall::Wall(Position<int> argPos):BaseBlock(argPos){

	imageKind = Laby_Wall;
	canMove = false;

}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Wall::~Wall(){
}

/// <summary>
/// �X�V�������s��
/// </summary>
void Wall::Update(){
}

/// <summary>
/// �`�揈�����s��
/// </summary>
void Wall::Draw(){

	DrawGraph((pos.GetDx() * Block_Size), (pos.GetDy() * Block_Size), image[Laby_Road], TRUE);

	//�O��
	if(pos.GetY() == 0 || pos.GetY() == (Laby_Height - 1) || pos.GetX() == 0 || pos.GetX() == (Laby_Width - 1)){
		DrawGraph((pos.GetDx() * Block_Size), (pos.GetDy() * Block_Size), image[imageKind], TRUE);
		return;
	}

	//���S���牺���ǂ���
	if((pos.GetY()) > (Laby_Height / 2)){
		DrawGraph((pos.GetDx() * Block_Size), (pos.GetDy() * Block_Size), image[Laby_Road], TRUE);
		return;
	}

	DrawGraph((pos.GetDx() * Block_Size), (pos.GetDy() * Block_Size), image[imageKind], TRUE);

}
/// <summary>
/// �I�u�W�F�N�g�ɓ����������̃A�N�V��������
/// </summary>
/// <returns>���̃I�u�W�F�N�g���ʉ߂ł���ꍇtrue</returns>
bool Wall::HitAction(){

	return canMove;
}
