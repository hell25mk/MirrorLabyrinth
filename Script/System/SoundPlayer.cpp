#include "SoundPlayer.h"
#include "DxLib.h"

const int Sound_Volume = 50;

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

	//std::map<std::string, int>::iterator itr;		¦auto‚Å‘ã—p
	//Volume‚Ì’²®
	for(auto itr = sound.begin(); itr != sound.end(); itr++){

		ChangeVolumeSoundMem(Sound_Volume, sound[itr->first]);

	}

}

void SoundPlayer::PlayBGM(std::string argKey){

	/*if(!sound.count(argKey)){
		return;
	}*/

	if(sound.find(argKey) == sound.end()){
		return;
	}

	if(CheckSoundMem(sound[argKey])){
		return;
	}

	PlaySoundMem(sound[argKey], DX_PLAYTYPE_LOOP);

	nowPlaySound = argKey;

}

void SoundPlayer::StopBGM(){

	if(CheckSoundMem(sound[nowPlaySound]) == 1){
		StopSoundMem(sound[nowPlaySound]);
	}

}

void SoundPlayer::PlaySE(std::string argKey){

	if(sound.count(argKey) == 0){
		return;
	}

	PlaySoundMem(sound[argKey], DX_PLAYTYPE_BACK);

}