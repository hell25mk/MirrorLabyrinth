#include "GameInfo.h"

void C_GameInfo::Create(){

	gameLevel = Level_Easy;
	imageType = Image_Type1;

}

void C_GameInfo::SetInfo(std::string argKey, int argValue){

	info[argKey] = argValue;

}

int C_GameInfo::GetInfo(std::string argKey) const{

	auto itr = info.find(argKey);
	if(info.end() == itr){
		return NULL;
	}

	return itr->second;
}

void C_GameInfo::UpGameLevel(){

	if(gameLevel == Level_Hard){
		return;
	}

	gameLevel = (e_GameLevel)(gameLevel + 1);

}

void C_GameInfo::DownGameLevel(){

	if(gameLevel == Level_Easy){
		return;
	}

	gameLevel = (e_GameLevel)(gameLevel - 1);

}

void C_GameInfo::ExpertGameLevel(){

	gameLevel = Level_Expert;

}

e_GameLevel C_GameInfo::GetGameLevel(){ 

	return gameLevel;
}

void C_GameInfo::UpImageType(){

	if(imageType == Image_Type3){
		return;
	}

	imageType = (e_ImageType)(imageType + 1);

}

void C_GameInfo::DownImageType(){

	if(imageType == Image_Type1){
		return;
	}

	imageType = (e_ImageType)(imageType - 1);

}

e_ImageType C_GameInfo::GetImageType(){ 

	return imageType;
}