#include "ResultScene.h"

const int Flash_Time = 30;

ResultScene::ResultScene(SceneChanger *argSceneChanger) : BaseScene(argSceneChanger){

	resultImage = LoadGraph("Image/Result/Result.png");
	pleaseKeyImage = LoadGraph("Image/Result/PleaseSpaseKey.png");
	flashCount = 0;
	flashFlag = true;

}

ResultScene::~ResultScene(){
}

void ResultScene::Update(){

#ifdef _DEBUG
	if(KeyboardManager::GetInstance().Input(KEY_INPUT_ESCAPE) == 1){
		sceneChanger->SceneChange(Scene_Title);
	}
#endif // _DEBUG

	if(KeyboardManager::GetInstance().Input(KEY_INPUT_SPACE) == 1){
		sceneChanger->SceneChange(Scene_Title);
	}

	flashCount++;

	if(flashCount > Flash_Time){
		flashFlag = !flashFlag;
		flashCount = 0;
	}

}

void ResultScene::Draw(){

	DrawGraph(0, 0, resultImage, TRUE);

	if(flashFlag){
		DrawGraph(0, 0, pleaseKeyImage, TRUE);
	}

}