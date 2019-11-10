#include "BaseScene.h"

/// <summary>
/// メンバを初期化する
/// </summary>
/// <param name="argSceneChanger">SceneChangerのポインタ</param>
BaseScene::BaseScene(SceneChanger *argSceneChanger){

	sceneChanger = argSceneChanger;

};

/// <summary>
/// メモリを確保していた場合は解放する
/// </summary>
BaseScene::~BaseScene(){



}