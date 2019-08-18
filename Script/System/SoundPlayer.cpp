#include "SoundPlayer.h"
#include "DxLib.h"

//再生するときのボリューム(0～255)
const int Sound_Volume = 50;

/// <summary>
/// 初期化処理を行う
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

	//Volumeの調整
	for(auto itr = sound.begin(); itr != sound.end(); itr++){

		ChangeVolumeSoundMem(Sound_Volume, sound[itr->first]);

	}

}

/// <summary>
/// BGMを再生する
/// </summary>
/// <param name="argKey">再生するBGMのキーワード</param>
void SoundPlayer::PlayBGM(std::string argKey){

	//キーワードで検索し、見つからなかったら処理を終了する
	if(sound.find(argKey) == sound.end()){
		return;
	}

	//再生中の場合は処理を終了する
	if(CheckSoundMem(sound[argKey])){
		return;
	}

	//DX_PLAYTYPE_LOOPを指定し、ループ再生するようにしている
	PlaySoundMem(sound[argKey], DX_PLAYTYPE_LOOP);

	//現在再生しているBGMのキーワードを記憶
	nowPlaySound = argKey;

}

/// <summary>
/// BGMを停止する
/// </summary>
void SoundPlayer::StopBGM(){

	//現在BGMを再生している場合、そのBGMを停止する
	if(CheckSoundMem(sound[nowPlaySound]) == 1){
		StopSoundMem(sound[nowPlaySound]);
	}

}

/// <summary>
/// SEを再生する
/// </summary>
/// <param name="argKey">再生するSEのキーワード</param>
void SoundPlayer::PlaySE(std::string argKey){

	//キーワードで検索し見つからなかったら処理を停止する
	if(sound.count(argKey) == 0){
		return;
	}

	PlaySoundMem(sound[argKey], DX_PLAYTYPE_BACK);

}