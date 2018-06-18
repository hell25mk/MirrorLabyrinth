#pragma once

typedef enum{
	Scene_Title,	//タイトルシーン
	Scene_Game,		//ゲームシーン
	Scene_Config,	//設定シーン
	Scene_Result,

	Scene_End,		//ゲーム終了
	Scene_Nore,		//無し
}e_Scene;

class C_SceneChanger{

public:
	virtual ~C_SceneChanger(){};
	virtual void SceneChange(e_Scene nextScene) = 0;

};