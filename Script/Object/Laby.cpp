#include "Laby.h"
#include "DxLib.h"
#include "../Manager/FileManager.h"
#include "../System/Position.h"
#include "../Base/BaseBlock.h"
#include "ObjectList.h"

const int Laby::Laby_Height = 15;
const int Laby::Laby_Width = 20;
const int Image_Width = 5;
const int Image_Height = 3;
const int Block_Size = 32;

//�ǂݍ��܂�Ȃ������ꍇ�̃e�X�g�}�b�v
//csv�t�@�C���ɕς����ق���������������Ȃ�
std::vector<int> LabySampleVector{
	 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	 1,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,
	 1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,0,1,
	 1,0,1,0,1,0,1,0,1,0,0,0,0,1,0,0,0,1,0,1,
	 1,0,1,0,1,0,1,0,1,0,1,1,0,1,0,1,0,1,0,1,
	 1,0,1,0,1,0,1,0,1,0,0,1,0,1,0,1,0,1,0,1,
	 1,0,0,0,1,0,0,0,1,1,0,1,0,0,0,1,0,0,0,1,
	 1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,
	 1,0,0,0,1,0,0,0,1,1,0,1,0,0,0,1,0,0,0,1,
	 1,0,1,0,1,0,1,0,1,0,0,1,0,1,0,1,0,1,0,1,
	 1,0,1,0,1,0,1,0,1,0,1,1,0,1,0,1,0,1,0,1,
	 1,0,1,0,1,0,1,0,1,0,0,0,0,1,0,0,0,1,0,1,
	 1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,0,1,
	 1,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,
	 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
};

/// <summary>
/// �R���X�g���N�^
/// </summary>
Laby::Laby(){

	labyVector.resize(Laby_Height * Laby_Width);
	blockVector.resize(Laby_Height * Laby_Width);
	maxKeyNum = 0;
	getKeyNum = 0;

}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Laby::~Laby(){
	
	std::vector<int>().swap(labyVector);

}

/// <summary>
/// �X�V�������s��
/// </summary>
void Laby::Update() {

	for (auto itr = blockVector.begin(); itr != blockVector.end();) {

		(*itr)->Update();
		itr++;

	}

}

/// <summary>
/// �`�揈�����s��
/// </summary>
void Laby::Draw() {

	for (auto itr = blockVector.begin(); itr != blockVector.end();) {

		(*itr)->Draw();
		itr++;

	}

}

/// <summary>
/// ���X�g�ɃI�u�W�F�N�g��ǉ�����
/// </summary>
/// <param name="argBlockKind">�I�u�W�F�N�g�̎��</param>
/// <param name="argPos">���W</param>
void Laby::PushBlockObject(int argBlockKind, Position<int> argPos){

	int pos = argPos.GetY() * Laby_Width + argPos.GetX();

	//�u���b�N��o�^
	labyVector[pos] = argBlockKind;

	//��ނ��������ꍇ���l���Č����I�ȕ��@��������K�v�L��
	switch(argBlockKind){
		case Laby_Player:
			blockVector[pos] = std::shared_ptr<BaseBlock>(new Road(argPos));
			break;
		case Laby_Wall:
			blockVector[pos] = std::shared_ptr<BaseBlock>(new Wall(argPos));
			break;
		case Laby_Road:
			blockVector[pos] = std::shared_ptr<BaseBlock>(new Road(argPos));
			break;
		case Laby_Stairs:
			blockVector[pos] = std::shared_ptr<BaseBlock>(new Stairs(argPos));
			break;
		case Laby_Door:
			blockVector[pos] = std::shared_ptr<BaseBlock>(new Door(argPos, &maxKeyNum, &getKeyNum));
			break;
		case Laby_Key:
			blockVector[pos] = std::shared_ptr<BaseBlock>(new Key(argPos, &getKeyNum));
			maxKeyNum++;
			break;
		case Laby_Block:
			blockVector[pos] = std::shared_ptr<BaseBlock>(new Block(argPos));
			break;
	}

}

/// <summary>
/// �v���C���[�̈ړ��悪�ړ��ł���ꏊ���m�F����
/// </summary>
/// <param name="argDire">�v���C���[�̈ړ�����</param>
/// <param name="argPos">�v���C���[�̍��W</param>
/// <returns>�ړ��ł���ꍇtrue</returns>
bool Laby::MoveCheck(int argDire, Position<int> argPos){

	bool checkFlag = false;
	Position<int> tempPos;			//�����W
	int vy[4] = { 1,0,0,-1 };		//y�ړ���
	int vx[4] = { 0,1,-1,0 };		//x�ړ���
	//int test[4] = { Laby_Height - 1,Laby_Width - 1,0,0 };		//�ړ��\�͈�

	tempPos.SetY(argPos.GetY() / Block_Size + vy[argDire]);
	tempPos.SetX(argPos.GetX() / Block_Size + vx[argDire]);

#pragma region �Q�ƃ`�F�b�N
	if(tempPos.GetX() < 0){
		return checkFlag;
	}
	if(tempPos.GetX() > Laby_Width - 1){
		return checkFlag;
	}
	if(tempPos.GetY() < 0){
		return checkFlag;
	}
	if(tempPos.GetY() > Laby_Height - 1){
		return checkFlag;
	}
#pragma endregion

	//�ړ��悪�ړ��s�̏ꍇfalse��Ԃ�
	int pos = tempPos.GetY() * Laby_Width + tempPos.GetX();
	if(!blockVector[pos]->HitAction()){
		return checkFlag;
	}

	checkFlag = true;

	return checkFlag;
}

/// <summary>
/// �v���C���[���K�i�ɓ��B�������m�F����
/// </summary>
/// <param name="argPos"></param>
/// <returns>�v���C���[�̍��W���K�i�Ɠ����Ȃ�true</returns>
bool Laby::ClearCheck(Position<int> const argPos){

	//�v���C���[�̌��݈ʒu��z��ԍ��ɒ���
	Position<int> tempPos;
	tempPos = argPos;
	int pos = (tempPos.GetY() / Block_Size) * Laby_Width + (tempPos.GetX() / Block_Size);
	//�v���C���[�̍��W���K�i�Ɠ����łȂ����false��Ԃ�
	if(labyVector[pos] != Laby_Stairs){
		return false;
	}

	return true;
}