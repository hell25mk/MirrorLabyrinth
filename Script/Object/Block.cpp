#include "Block.h"
#include "DxLib.h"
#include "../System/Position.h"
#include "../System/SoundPlayer.h"
#include "../Define/Enum.h"

const int Reflect_Space = 14;

/// <summary>
/// �R���X�g���N�^
/// </summary>
/// <param name="argPos">���W</param>
Block::Block(Position<int> argPos):BaseBlock(argPos){

	imageKind = Laby_Block1;
	endurance = Laby_Block4 - Laby_Block1;
	damage = 0;
	canMove = false;

}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Block::~Block(){
}

/// <summary>
/// �X�V�������s��
/// </summary>
void Block::Update(){
}

/// <summary>
/// �`�揈�����s��
/// </summary>
void Block::Draw(){

	DrawGraph((pos.GetDx() * Block_Size), (pos.GetDy() * Block_Size), image[Laby_Road], TRUE);
	DrawGraph((pos.GetDx() * Block_Size), ((Reflect_Space - pos.GetDy()) * Block_Size), image[imageKind + damage], TRUE);

}

/// <summary>
/// �I�u�W�F�N�g�ɓ����������̃A�N�V��������
/// </summary>
/// <returns>���̃I�u�W�F�N�g���ʉ߂ł���ꍇtrue</returns>
bool Block::HitAction(){

	if(canMove){
		return canMove;
	}

	damage++;
	SoundPlayer::GetInstance().PlaySE("Block1");

	//�_���[�W���ϋv�l���������ꍇ�ʂ��悤�ɂ���
	canMove = damage > (endurance);
	if(canMove){
		SoundPlayer::GetInstance().PlaySE("Block2");
	}

	return canMove;
}