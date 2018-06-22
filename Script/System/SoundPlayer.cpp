#include "SoundPlayer.h"
#include "DxLib.h"

const int Sound_Volume = 70;

void C_SoundPlayer::Create(){

	//BGM Load
	sound["Title"] = LoadSoundMem("Music/BGM_TitleSnece.ogg");
	sound["Stage"] = LoadSoundMem("Music/BGM_GameSnece.ogg");

	//SE Load
	sound["WallCollide"] = LoadSoundMem("Music/SE_WallCollide.ogg");
	sound["Stairs"] = LoadSoundMem("Music/SE_Stairs.ogg");
	sound["BreakWall1"] = LoadSoundMem("Music/SE_BreakWallCollide.ogg");
	sound["BreakWall2"] = LoadSoundMem("Music/SE_BreakWallBreak.ogg");
	sound["Key"] = LoadSoundMem("Music/SE_KeyGet.ogg");

	//std::map<std::string, int>::iterator itr;		¦auto‚Å‘ã—p
	//Volume‚Ì’²®
	for(auto itr = sound.begin(); itr != sound.end(); itr++){

		ChangeVolumeSoundMem(Sound_Volume, sound[itr->first]);

	}

}

void C_SoundPlayer::PlayBGM(std::string argKey){

	if(sound.count(argKey) == 0){
		return;
	}

	if(CheckSoundMem(sound[argKey]) == 1){
		return;
	}

	PlaySoundMem(sound[argKey], DX_PLAYTYPE_LOOP);

	nowPlaySound = argKey;

}

void C_SoundPlayer::StopBGM(){

	if(CheckSoundMem(sound[nowPlaySound]) == 1){
		StopSoundMem(sound[nowPlaySound]);
	}

}

void C_SoundPlayer::PlaySE(std::string argKey){

	if(sound.count(argKey) == 0){
		return;
	}

	PlaySoundMem(sound[argKey], DX_PLAYTYPE_BACK);

}