#include "BaseScene.h"

/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="argSceneChanger">SceneChangerのポインタ</param>
BaseScene::BaseScene(SceneChanger *argSceneChanger){

	sceneChanger = argSceneChanger;

};

/// <summary>
/// デストラクタ
/// </summary>
BaseScene::~BaseScene(){



}