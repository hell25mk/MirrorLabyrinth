/*****************************************************************************************************
-----�t�@�C���T�v-----
���H�I�u�W�F�N�g
******************************************************************************************************/

#pragma once

#include "../System/Position.h"
#include <memory>
#include <vector>

class BaseBlock;
class Player;
class Mirror;

class Laby {

public:
	/// <summary>
	/// �����o������������
	/// </summary>
	Laby();
	/// <summary>
	/// ���������m�ۂ��Ă����ꍇ�͉������
	/// </summary>
	~Laby();

	/// <summary>
	/// 1���[�v���ŕK�v�ȍX�V�������s��
	/// </summary>
	void Update();
	/// <summary>
	/// 1���[�v���ŕK�v�ȕ`�揈�����s��
	/// </summary>
	void Draw();

	/// <summary>
	/// ���X�g�ɃI�u�W�F�N�g��ǉ�����
	/// </summary>
	/// <param name="argBlockKind">�I�u�W�F�N�g�̎��</param>
	/// <param name="argPos">���W</param>
	void PushBlockObject(int argBlockKind, Position<int> argPos);
	/// <summary>
	/// �v���C���[�̈ړ��悪�ړ��ł���ꏊ���m�F����
	/// </summary>
	/// <param name="argDire">�v���C���[�̈ړ�����</param>
	/// <param name="argPos">�v���C���[�̍��W</param>
	/// <returns>�ړ��ł���ꍇtrue</returns>
	bool MoveCheck(int argDire, Position<int> argPos);
	/// <summary>
	/// <summary>
	/// �v���C���[���K�i�ɓ��B�������m�F����
	/// </summary>
	/// <param name="argPos"></param>
	/// <returns>�v���C���[�̍��W���K�i�Ɠ����Ȃ�true</returns>
	bool ClearCheck(Position<int> argPos);

private:
	static const int Laby_Height;		//���H�̏c�̃}�X�ڐ�
	static const int Laby_Width;		//���H�̉��̃}�X�ڐ�

	//�I�u�W�F�N�g�̎�ނ̗�
	typedef enum {
		Laby_Player,
		Laby_Wall,
		Laby_Road,
		Laby_Stairs,
		Laby_Door,
		Laby_Key,
		Laby_Block,

		Laby_Nore,
	}eObjectKind;

private:
	Position<int> pos;
	std::vector<int> labyVector;
	std::vector<std::shared_ptr<BaseBlock>> blockVector;
	int maxKeyNum;
	int getKeyNum;

};

