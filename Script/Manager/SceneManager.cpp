#include "SceneManager.h"
#include "../Scene/SceneList.h"
#include "../Base/BaseScene.h"
#include "KeyboardManager.h"

C_SceneManager::C_SceneManager(){

	nextScene = Scene_Nore;

	nowScene = (C_BaseScene*)new C_TitleScene(this);

	//stackName.push(new C_TitleScene(this,keyManager));

}

C_SceneManager::~C_SceneManager(){

	delete nowScene;

}

void C_SceneManager::Update(){

	if(nextScene != Scene_Nore){
		delete nowScene;

		switch(nextScene){
			case Scene_Title:
				nowScene = (C_BaseScene*)new C_TitleScene(this);
				break;
			case Scene_Game:
				nowScene = (C_BaseScene*)new C_GameScene(this);
				break;
			case Scene_Config:
				nowScene = (C_BaseScene*)new C_ConfigScene(this);
				break;
			case Scene_Result:
				nowScene = (C_BaseScene*)new C_ResultScene(this);
				break;
			case Scene_End:
				return;
				break;
		}

		nextScene = Scene_Nore;
	}

	nowScene->Update();
	//stackName.top()->Update();

}

void C_SceneManager::Draw(){

	nowScene->Draw();
	//stackName.top()->Draw();

}

void C_SceneManager::SceneChange(e_Scene argNextScene){

	nextScene = argNextScene;

}

int C_SceneManager::GetNextScene(){

	return nextScene;
}