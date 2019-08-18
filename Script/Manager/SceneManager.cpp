#include "SceneManager.h"
#include "../Scene/SceneList.h"
#include "../Base/BaseScene.h"
#include "KeyboardManager.h"

/// <summary>
/// コンストラクタ
/// </summary>
SceneManager::SceneManager() : nextScene(Scene_None) {

	nowScene = (BaseScene*)new TitleScene(this);
	//stackName.push(new TitleScene(this,keyManager));

}

/// <summary>
/// デストラクタ
/// </summary>
SceneManager::~SceneManager() {

	delete nowScene;

}

/// <summary>
/// 更新処理を行う
/// </summary>
void SceneManager::Update() {

	if (!SceneChange()) {
		return;
	}

	nowScene->Update();
	//stackName.top()->Update();

}

/// <summary>
/// 描画処理を行う
/// </summary>
void SceneManager::Draw() {

	nowScene->Draw();
	//stackName.top()->Draw();

}

/// <summary>
/// シーン変更が必要な場合、指定されたシーンを生成する
/// </summary>
/// <returns>移動先がScene_End以外ならtrue</returns>
bool SceneManager::SceneChange() {

	//シーンを移動させる必要がない場合は処理を終了する
	if (nextScene == Scene_None) {
		return true;
	}

	delete nowScene;

	switch (nextScene) {
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
		return false;
		break;
	}

	nextScene = Scene_None;

	return true;
}

/// </summary>
/// 次に移動するシーンを更新する
/// </summary>
/// <param name="nextScene">移動先のシーン番号</param>
void SceneManager::SetNextScene(eSceneType argNextScene) {

	nextScene = argNextScene;

}

/// <summary>
/// 次に移動するシーンを取得する
/// </summary>
/// <returns></returns>
int SceneManager::GetNextScene() {

	return nextScene;
}