#include "GameInfo.h"

/// <summary>
/// �������������s��
/// </summary>
void GameInfo::Create(){

	gameLevel = Level_Easy;

}

/// <summary>
/// �Q�[���ɕK�v�ȏ����X�V����
/// </summary>
/// <param name="argKey">���̏����i�[���邽�߂̃L�[���[�h</param>
/// <param name="argValue">���̏��̒l</param>
void GameInfo::SetInfo(std::string argKey, int argValue){

	gameInfo[argKey] = argValue;

}

/// <summary>
/// �Q�[���ɕK�v�ȏ����擾����
/// </summary>
/// <param name="argKey">���̏������o�����߂̃L�[���[�h</param>
/// <returns>���o������񂪂���ꍇitr->second�̒l��Ԃ�</returns>
int GameInfo::GetInfo(std::string argKey) const{

	auto itr = gameInfo.find(argKey);

	//�L�[���[�h�̏�񂪑��݂��Ȃ������ꍇNULL��Ԃ�
	if(gameInfo.end() == itr){
		return NULL;
	}

	return itr->second;
}

/// <summary>
/// �Q�[���̃��x�����グ��
/// </summary>
void GameInfo::UpGameLevel(){

	if(gameLevel == Level_Hard){
		return;
	}

	gameLevel = (eGameLevel)(gameLevel + 1);

}

/// <summary>
/// �Q�[���̃��x����������
/// </summary>
void GameInfo::DownGameLevel(){

	if(gameLevel == Level_Easy){
		return;
	}

	gameLevel = (eGameLevel)(gameLevel - 1);

}

/// <summary>
/// ���݂̃Q�[�����x�����擾����
/// </summary>
/// <returns>���݂̃Q�[�����x��</returns>
eGameLevel GameInfo::GetGameLevel(){ 

	return gameLevel;
}