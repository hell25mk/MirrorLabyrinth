/*****************************************************************************************************
-----ファイル概要-----
シーン切り替え行うクラス
******************************************************************************************************/

#pragma once

typedef enum{
	Scene_Title,	//タイトルシーン
	Scene_Game,		//ゲームシーン
	Scene_Config,	//設定シーン
	Scene_Result,	//リザルトシーン

	Scene_End,		//ゲーム終了
	Scene_None,		//無し
}eSceneType;

class SceneChanger{

public:
	virtual ~SceneChanger(){};

	/// <summary>
	/// 次に移動するシーンを更新する
	/// </summary>
	/// <param name="nextScene">移動先のシーン番号</param>
	virtual void SetNextScene(eSceneType nextScene) = 0;

};