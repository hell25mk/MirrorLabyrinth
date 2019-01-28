#include "GameInfo.h"

void GameInfo::Create(){

	gameLevel = Level_Easy;

}

void GameInfo::SetInfo(std::string argKey, int argValue){

	info[argKey] = argValue;

}

int GameInfo::GetInfo(std::string argKey) const{

	auto itr = info.find(argKey);
	if(info.end() == itr){
		return NULL;
	}

	return itr->second;
}

void GameInfo::UpGameLevel(){

	if(gameLevel == Level_Hard){
		return;
	}

	gameLevel = (e_GameLevel)(gameLevel + 1);

}

void GameInfo::DownGameLevel(){

	if(gameLevel == Level_Easy){
		return;
	}

	gameLevel = (e_GameLevel)(gameLevel - 1);

}

e_GameLevel GameInfo::GetGameLevel(){ 

	return gameLevel;
}