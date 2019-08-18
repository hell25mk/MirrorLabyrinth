#include "Stairs.h"
#include "../System/SoundPlayer.h"
#include "../Define/Enum.h"

const int Laby_Height = 15;

/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="argPos">���W</param>
Stairs::Stairs(Position<int> argPos):BaseBlock(argPos){

	imageKind = Laby_Stairs;

}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Stairs::~Stairs(){
}

/// <summary>
/// �X�V�������s��
/// </summary>
void Stairs::Update(){
}

/// <summary>
/// �`�揈�����s��
/// </summary>
void Stairs::Draw(){

	DrawGraph((pos.GetDx() * Block_Size), (pos.GetDy() * Block_Size), image[Laby_Road], TRUE);
	DrawGraph((pos.GetDx() * Block_Size), (pos.GetDy() * Block_Size), image[imageKind], TRUE);

}

/// <summary>
/// �I�u�W�F�N�g�ɓ����������̃A�N�V��������
/// </summary>
/// <returns>���̃I�u�W�F�N�g���ʉ߂ł���ꍇtrue</returns>
bool Stairs::HitAction(){

	return canMove;
}
