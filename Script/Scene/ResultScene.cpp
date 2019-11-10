#include "ResultScene.h"

const int Flash_Time = 30;

/// <summary>
/// �����o������������
/// </summary>
/// <param name="argSceneChanger">SceneChanger�̃|�C���^</param>
ResultScene::ResultScene(SceneChanger* argSceneChanger) : BaseScene(argSceneChanger){

	resultImage = LoadGraph("Image/Result/Result.png");
	pleaseKeyImage = LoadGraph("Image/Result/PleaseSpaseKey.png");
	flashCount = 0;
	willFlash = true;

}

/// <summary>
/// ���������m�ۂ��Ă����ꍇ�͉������
/// </summary>
ResultScene::~ResultScene(){
}

/// <summary>
/// 1���[�v���ŕK�v�ȍX�V�������s��
/// </summary>
void ResultScene::Update(){

#ifdef _DEBUG
	if(KeyboardManager::GetInstance().Input(KEY_INPUT_ESCAPE) == 1){
		sceneChanger->SetNextScene(Scene_Title);
	}
#endif //ESC�Ń^�C�g���ɖ߂�

	//SPACE�Ń^�C�g���֖߂�
	if(KeyboardManager::GetInstance().Input(KEY_INPUT_SPACE) == 1){
		sceneChanger->SetNextScene(Scene_Title);
	}

	//�_�ł̂��߂̏���
	flashCount++;
	if(flashCount > Flash_Time){
		willFlash = !willFlash;
		flashCount = 0;
	}

}

/// <summary>
/// 1���[�v���ŕK�v�ȕ`�揈�����s��
/// </summary>
void ResultScene::Draw(){

	DrawGraph(0, 0, resultImage, TRUE);

	//�摜��_�ł�����
	if(willFlash){
		DrawGraph(0, 0, pleaseKeyImage, TRUE);
	}

}