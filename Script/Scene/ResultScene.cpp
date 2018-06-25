#include "ResultScene.h"

const int Flash_Time = 30;

C_ResultScene::C_ResultScene(C_SceneChanger *argSceneChanger) : C_BaseScene(argSceneChanger){

	resultImage = LoadGraph("Image/Result/Result.png");
	pleaseKeyImage = LoadGraph("Image/Result/PleaseSpaseKey.png");
	flashCount = 0;
	flashFlag = true;

}


C_ResultScene::~C_ResultScene(){
}

void C_ResultScene::Update(){

#ifdef _DEBUG
	if(C_KeyboardManager::GetInstance().Input(KEY_INPUT_ESCAPE) == 1){
		sceneChanger->SceneChange(Scene_Title);
	}
#endif // _DEBUG

	if(C_KeyboardManager::GetInstance().Input(KEY_INPUT_SPACE) == 1){
		sceneChanger->SceneChange(Scene_Title);
	}

	flashCount++;

	if(flashCount > Flash_Time){
		flashFlag = !flashFlag;
		flashCount = 0;
	}

}

void C_ResultScene::Draw(){

	DrawGraph(0, 0, resultImage, TRUE);

	if(flashFlag){
		DrawGraph(0, 0, pleaseKeyImage, TRUE);
	}

}