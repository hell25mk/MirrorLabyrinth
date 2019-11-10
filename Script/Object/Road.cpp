#include "Road.h"
#include "../System/Position.h"
#include "../Define/Enum.h"

/// <summary>
/// �����o������������
/// </summary>
/// <param name="argPos">���W</param>
Road::Road(Position<int> argPos):BaseBlock(argPos){

	imageKind = Laby_Road;

}

/// <summary>
/// ���������m�ۂ��Ă����ꍇ�͉������
/// </summary>
Road::~Road(){
}

/// <summary>
/// 1���[�v���ŕK�v�ȍX�V�������s��
/// </summary>
void Road::Update(){
}

/// <summary>
/// 1���[�v���ŕK�v�ȕ`�揈�����s��
/// </summary>
void Road::Draw(){

	DrawGraph((pos.GetDx() * Block_Size), (pos.GetDy() * Block_Size), image[imageKind], TRUE);

}

/// <summary>
/// �I�u�W�F�N�g�ɓ����������̃A�N�V��������
/// </summary>
/// <returns>���̃I�u�W�F�N�g���ʉ߂ł���ꍇtrue</returns>
bool Road::HitAction(){

	return canMove;
}