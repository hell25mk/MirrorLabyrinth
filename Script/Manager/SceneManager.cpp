#include "SceneManager.h"
#include "../Scene/SceneList.h"
#include "../Base/BaseScene.h"
#include "KeyboardManager.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
SceneManager::SceneManager() : nextScene(Scene_None) {

	nowScene = (BaseScene*)new TitleScene(this);
	//stackName.push(new TitleScene(this,keyManager));

}

/// <summary>
/// �f�X�g���N�^
/// </summary>
SceneManager::~SceneManager() {

	delete nowScene;

}

/// <summary>
/// �X�V�������s��
/// </summary>
void SceneManager::Update() {

	if (!SceneChange()) {
		return;
	}

	nowScene->Update();
	//stackName.top()->Update();

}

/// <summary>
/// �`�揈�����s��
/// </summary>
void SceneManager::Draw() {

	nowScene->Draw();
	//stackName.top()->Draw();

}

/// <summary>
/// �V�[���ύX���K�v�ȏꍇ�A�w�肳�ꂽ�V�[���𐶐�����
/// </summary>
/// <returns>�ړ��悪Scene_End�ȊO�Ȃ�true</returns>
bool SceneManager::SceneChange() {

	//�V�[�����ړ�������K�v���Ȃ��ꍇ�͏������I������
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
/// ���Ɉړ�����V�[�����X�V����
/// </summary>
/// <param name="nextScene">�ړ���̃V�[���ԍ�</param>
void SceneManager::SetNextScene(eSceneType argNextScene) {

	nextScene = argNextScene;

}

/// <summary>
/// ���Ɉړ�����V�[�����擾����
/// </summary>
/// <returns></returns>
int SceneManager::GetNextScene() {

	return nextScene;
}