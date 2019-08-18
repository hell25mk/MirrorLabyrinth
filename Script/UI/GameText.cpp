#include "GameText.h"
#include "DxLib.h"
#include "../System/GameInfo.h"

const int Color_White = GetColor(255, 255, 255);

/// <summary>
/// �R���X�g���N�^
/// </summary>
GameText::GameText(){

	const char* levelName[3] = { "Easy","Normal","Hard" };

	//���݂̃Q�[�����x���ɉ����ĕ�������쐬����
	strcpy_s(strGameLevel, sizeof(strGameLevel), levelName[GameInfo::GetInstance().GetGameLevel()]);

}

/// <summary>
/// �f�X�g���N�^
/// </summary>
GameText::~GameText(){
}

/// <summary>
/// �`�揈�����s��
/// </summary>
void GameText::Draw(){

	SetFontSize(36);

	DrawString(720, 250, "Level", Color_White);
	DrawString(725, 300, strGameLevel, Color_White);

	SetFontSize(DEFAULT_FONT_SIZE);

}
