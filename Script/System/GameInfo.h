/*****************************************************************************************************
-----ファイル概要-----
ゲーム全体の情報を管理するクラス
作り方次第で消せる
******************************************************************************************************/

#pragma once

#include "Singleton.h"
#include "../Define/Enum.h"
#include <map>
#include <string>

//ゲームのレベル
enum eGameLevel{
	Level_Easy,
	Level_Normal,
	Level_Hard,

	Level_Num,
};

class GameInfo : public Singleton<GameInfo>{

public:
	friend class Singleton<GameInfo>;
	
	/// <summary>
	/// 初期化処理を行う
	/// </summary>
	virtual void Create() override;

	/// <summary>
	/// ゲームに必要な情報を更新する
	/// </summary>
	/// <param name="argKey">その情報を格納するためのキーワード</param>
	/// <param name="argValue">その情報の値</param>
	void SetInfo(std::string argKey, int argValue);
	/// <summary>
	/// ゲームに必要な情報を取得する
	/// </summary>
	/// <param name="argKey">その情報を取り出すためのキーワード</param>
	/// <returns>取り出した情報がある場合itr->secondの値を返す</returns>
	int GetInfo(std::string argKey) const;
	/// <summary>
	/// ゲームのレベルを上げる
	/// </summary>
	void UpGameLevel();
	/// <summary>
	/// ゲームのレベルを下げる
	/// </summary>
	void DownGameLevel();
	/// <summary>
	/// 現在のゲームレベルを取得する
	/// </summary>
	/// <returns>現在のゲームレベル</returns>
	eGameLevel GetGameLevel();

protected:
	GameInfo() : gameLevel(){}
	virtual ~GameInfo(){}

private:
	std::map<std::string, int> gameInfo;
	eGameLevel gameLevel;

};