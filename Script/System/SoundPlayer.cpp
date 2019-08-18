#include "SoundPlayer.h"
#include "DxLib.h"

//�Đ�����Ƃ��̃{�����[��(0�`255)
const int Sound_Volume = 50;

/// <summary>
/// �������������s��
/// </summary>
void SoundPlayer::Create(){

	//BGM Load
	sound["Title"] = LoadSoundMem("Music/BGM_TitleSnece.ogg");
	sound["Stage"] = LoadSoundMem("Music/BGM_GameSnece.ogg");

	//SE Load
	sound["Menu1"] = LoadSoundMem("Music/SE_MenuArror.ogg");
	sound["Menu2"] = LoadSoundMem("Music/SE_MenuSpace.ogg");
	sound["WallCollide"] = LoadSoundMem("Music/SE_WallCollide.ogg");
	sound["Stairs"] = LoadSoundMem("Music/SE_Stairs.ogg");
	sound["Block1"] = LoadSoundMem("Music/SE_Block1.ogg");
	sound["Block2"] = LoadSoundMem("Music/SE_Block2.ogg");
	sound["Key"] = LoadSoundMem("Music/SE_KeyGet.ogg");

	//Volume�̒���
	for(auto itr = sound.begin(); itr != sound.end(); itr++){

		ChangeVolumeSoundMem(Sound_Volume, sound[itr->first]);

	}

}

/// <summary>
/// BGM���Đ�����
/// </summary>
/// <param name="argKey">�Đ�����BGM�̃L�[���[�h</param>
void SoundPlayer::PlayBGM(std::string argKey){

	//�L�[���[�h�Ō������A������Ȃ������珈�����I������
	if(sound.find(argKey) == sound.end()){
		return;
	}

	//�Đ����̏ꍇ�͏������I������
	if(CheckSoundMem(sound[argKey])){
		return;
	}

	//DX_PLAYTYPE_LOOP���w�肵�A���[�v�Đ�����悤�ɂ��Ă���
	PlaySoundMem(sound[argKey], DX_PLAYTYPE_LOOP);

	//���ݍĐ����Ă���BGM�̃L�[���[�h���L��
	nowPlaySound = argKey;

}

/// <summary>
/// BGM���~����
/// </summary>
void SoundPlayer::StopBGM(){

	//����BGM���Đ����Ă���ꍇ�A����BGM���~����
	if(CheckSoundMem(sound[nowPlaySound]) == 1){
		StopSoundMem(sound[nowPlaySound]);
	}

}

/// <summary>
/// SE���Đ�����
/// </summary>
/// <param name="argKey">�Đ�����SE�̃L�[���[�h</param>
void SoundPlayer::PlaySE(std::string argKey){

	//�L�[���[�h�Ō�����������Ȃ������珈�����~����
	if(sound.count(argKey) == 0){
		return;
	}

	PlaySoundMem(sound[argKey], DX_PLAYTYPE_BACK);

}