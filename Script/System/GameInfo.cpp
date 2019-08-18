#include "GameInfo.h"

/// <summary>
/// 初期化処理を行う
/// </summary>
void GameInfo::Create(){

	gameLevel = Level_Easy;

}

/// <summary>
/// ゲームに必要な情報を更新する
/// </summary>
/// <param name="argKey">その情報を格納するためのキーワード</param>
/// <param name="argValue">その情報の値</param>
void GameInfo::SetInfo(std::string argKey, int argValue){

	gameInfo[argKey] = argValue;

}

/// <summary>
/// ゲームに必要な情報を取得する
/// </summary>
/// <param name="argKey">その情報を取り出すためのキーワード</param>
/// <returns>取り出した情報がある場合itr->secondの値を返す</returns>
int GameInfo::GetInfo(std::string argKey) const{

	auto itr = gameInfo.find(argKey);

	//キーワードの情報が存在しなかった場合NULLを返す
	if(gameInfo.end() == itr){
		return NULL;
	}

	return itr->second;
}

/// <summary>
/// ゲームのレベルを上げる
/// </summary>
void GameInfo::UpGameLevel(){

	if(gameLevel == Level_Hard){
		return;
	}

	gameLevel = (eGameLevel)(gameLevel + 1);

}

/// <summary>
/// ゲームのレベルを下げる
/// </summary>
void GameInfo::DownGameLevel(){

	if(gameLevel == Level_Easy){
		return;
	}

	gameLevel = (eGameLevel)(gameLevel - 1);

}

/// <summary>
/// 現在のゲームレベルを取得する
/// </summary>
/// <returns>現在のゲームレベル</returns>
eGameLevel GameInfo::GetGameLevel(){ 

	return gameLevel;
}