#include "Key.h"
#include "DxLib.h"
#include "../System/Position.h"
#include "../System/SoundPlayer.h"
#include "../Define/Enum.h"

/// �R���X�g���N�^
/// </summary>
/// <param name="argPos">���W</param>
/// <param name="getKeyNum">�擾�������̐����i�[�����|�C���^</param>
Key::Key(Position<int> argPos, int *getKeyNum):BaseBlock(argPos){

	this->getKeyNum = getKeyNum;

	//�����_���ŃL�[�̐F��ύX����(�Q�[�����̂ɉe���͂Ȃ�)
	int rand = GetRand(9);
	if(rand % 2){
		imageKind = Laby_RubyKey;
	} else{
		imageKind = Laby_DiaKey;
	}

	isGet = false;

}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Key::~Key(){
}

/// <summary>
/// �X�V�������s��
/// </summary>
void Key::Update(){
}

/// <summary>
/// �`�揈�����s��
/// </summary>
void Key::Draw(){

	DrawGraph((pos.GetDx() * Block_Size), (pos.GetDy() * Block_Size), image[Laby_Road], TRUE);

	//��������ς݂łȂ��Ȃ�`�悷��
	if(!isGet){
		DrawGraph((pos.GetDx() * Block_Size), (pos.GetDy() * Block_Size), image[imageKind], TRUE);
	}

}
/// <summary>
/// �I�u�W�F�N�g�ɓ����������̃A�N�V��������
/// </summary>
/// <returns>���̃I�u�W�F�N�g���ʉ߂ł���ꍇtrue</returns>
bool Key::HitAction(){

	if(isGet){
		return canMove;
	}

	//�擾�������̐��𑝂₷
	*getKeyNum += 1;
	SoundPlayer::GetInstance().PlaySE("Key");

	isGet = true;

	return canMove;
}