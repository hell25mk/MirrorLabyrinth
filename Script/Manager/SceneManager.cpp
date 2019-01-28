#include "SceneManager.h"
#include "../Scene/SceneList.h"
#include "../Base/BaseScene.h"
#include "KeyboardManager.h"

SceneManager::SceneManager(){

	nextScene = Scene_Nore;
	nowScene = (BaseScene*)new TitleScene(this);
	//stackName.push(new TitleScene(this,keyManager));

}

SceneManager::~SceneManager(){

	delete nowScene;

}

void SceneManager::Update(){

	//ŠÖ”•ª‚¯‚µ‚½‚Ù‚¤‚ª‚¢‚¢
	if(nextScene != Scene_Nore){
		delete nowScene;

		switch(nextScene){
			case Scene_Title:
				nowScene = new TitleScene(this);
				break;
			case Scene_Game:
				nowScene = new GameScene(this);
				break;
			case Scene_Config:
				nowScene = new ConfigScene(this);
				break;
			case Scene_Result:
				nowScene = new ResultScene(this);
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

void SceneManager::Draw(){

	nowScene->Draw();
	//stackName.top()->Draw();

}

void SceneManager::SceneChange(e_Scene argNextScene){

	nextScene = argNextScene;

}

int SceneManager::GetNextScene(){

	return nextScene;
}