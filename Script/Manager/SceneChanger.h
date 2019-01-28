/*****************************************************************************************************
-----ファイル概要-----
シーン切り替え行うクラス
******************************************************************************************************/

#pragma once

typedef enum{
	Scene_Title,	//タイトルシーン
	Scene_Game,		//ゲームシーン
	Scene_Config,	//設定シーン
	Scene_Result,

	Scene_End,		//ゲーム終了
	Scene_Nore,		//無し
}e_Scene;

class SceneChanger{

public:
	virtual ~SceneChanger(){};
	virtual void SceneChange(e_Scene nextScene) = 0;

};