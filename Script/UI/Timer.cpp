#include "Timer.h"
#include "DxLib.h"
#include "../System/GameInfo.h"

const int Color_White = GetColor(255, 255, 255);
const int Color_Red = GetColor(255, 0, 0);

//1�X�e�[�W�̍ő厝������
const int Timer::Basis_Time = 60;

/// <summary>
/// �����o������������
/// </summary>
Timer::Timer() : startTime(0),second(0),minute(0){

	nowGameTime = Basis_Time  / (GameInfo::GetInstance().GetGameLevel() + 1);		//�Q�[����Փx�ɂ���Đ������Ԃ̕ύX

}

/// <summary>
/// ���������m�ۂ��Ă����ꍇ�͉������
/// </summary>
Timer::~Timer(){
}

/// <summary>
/// 1���[�v���ŕK�v�ȍX�V�������s��
/// </summary>
void Timer::Update(){

	if(startTime == 0){
		startTime = GetNowCount();
	}

	//1�b���v��
	bool oneSecondFlag = GetNowCount() - startTime >= 1000;
	if(oneSecondFlag){
		nowGameTime = nowGameTime - 1;
		startTime = GetNowCount();
	}

	//���ƕb�ɕϊ�
	minute = nowGameTime / 60;
	second = nowGameTime % 60;

}

/// <summary>
/// 1���[�v���ŕK�v�ȕ`�揈�����s��
/// </summary>
void Timer::Draw(){

	SetFontSize(36);

	DrawFormatString(720, 100, Color_White, "Limit");

	//�c�莞�Ԃ�10�b��؂�����ԐF�ŕ\������
	bool drawTimeFlag = nowGameTime < 10;
	if(drawTimeFlag){
		DrawFormatString(700, 150, Color_Red, "%02d : %02d", minute, second);
	} else{
		DrawFormatString(700, 150, Color_White, "%02d : %02d", minute, second);
	}

	SetFontSize(DEFAULT_FONT_SIZE);

}

/// <summary>
/// ���݂̐i�s���Ԃ��擾
/// </summary>
/// <returns>�i�s��̎���</returns>
int Timer::GetGameTimer(){

	return nowGameTime;
}