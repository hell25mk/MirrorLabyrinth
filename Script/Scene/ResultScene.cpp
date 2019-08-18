#include "ResultScene.h"

const int Flash_Time = 30;

/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="argSceneChanger">SceneChangerのポインタ</param>
ResultScene::ResultScene(SceneChanger* argSceneChanger) : BaseScene(argSceneChanger){

	resultImage = LoadGraph("Image/Result/Result.png");
	pleaseKeyImage = LoadGraph("Image/Result/PleaseSpaseKey.png");
	flashCount = 0;
	willFlash = true;

}

/// <summary>
/// デストラクタ
/// </summary>
ResultScene::~ResultScene(){
}

/// <summary>
/// 更新処理を行う
/// </summary>
void ResultScene::Update(){

#ifdef _DEBUG
	if(KeyboardManager::GetInstance().Input(KEY_INPUT_ESCAPE) == 1){
		sceneChanger->SetNextScene(Scene_Title);
	}
#endif //ESCでタイトルに戻る

	//SPACEでタイトルへ戻る
	if(KeyboardManager::GetInstance().Input(KEY_INPUT_SPACE) == 1){
		sceneChanger->SetNextScene(Scene_Title);
	}

	//点滅のための処理
	flashCount++;
	if(flashCount > Flash_Time){
		willFlash = !willFlash;
		flashCount = 0;
	}

}

/// <summary>
/// 描画処理を行う
/// </summary>
void ResultScene::Draw(){

	DrawGraph(0, 0, resultImage, TRUE);

	//画像を点滅させる
	if(willFlash){
		DrawGraph(0, 0, pleaseKeyImage, TRUE);
	}

}