/*****************************************************************************************************
-----�t�@�C���T�v-----
�Q�[���S�̂̏����Ǘ�����N���X
��������ŏ�����
******************************************************************************************************/

#pragma once

#include "Singleton.h"
#include "../Define/Enum.h"
#include <map>
#include <string>

//�Q�[���̃��x��
enum eGameLevel{
	Level_Easy,
	Level_Normal,
	Level_Hard,

	Level_Num,
};

class GameInfo : public Singleton<GameInfo>{

public:
	friend class Singleton<GameInfo>;
	
	/// <summary>
	/// �������������s��
	/// </summary>
	virtual void Create() override;

	/// <summary>
	/// �Q�[���ɕK�v�ȏ����X�V����
	/// </summary>
	/// <param name="argKey">���̏����i�[���邽�߂̃L�[���[�h</param>
	/// <param name="argValue">���̏��̒l</param>
	void SetInfo(std::string argKey, int argValue);
	/// <summary>
	/// �Q�[���ɕK�v�ȏ����擾����
	/// </summary>
	/// <param name="argKey">���̏������o�����߂̃L�[���[�h</param>
	/// <returns>���o������񂪂���ꍇitr->second�̒l��Ԃ�</returns>
	int GetInfo(std::string argKey) const;
	/// <summary>
	/// �Q�[���̃��x�����グ��
	/// </summary>
	void UpGameLevel();
	/// <summary>
	/// �Q�[���̃��x����������
	/// </summary>
	void DownGameLevel();
	/// <summary>
	/// ���݂̃Q�[�����x�����擾����
	/// </summary>
	/// <returns>���݂̃Q�[�����x��</returns>
	eGameLevel GetGameLevel();

protected:
	GameInfo() : gameLevel(){}
	virtual ~GameInfo(){}

private:
	std::map<std::string, int> gameInfo;
	eGameLevel gameLevel;

};