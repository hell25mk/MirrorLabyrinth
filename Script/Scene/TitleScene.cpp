#include "TitleScene.h"
#include "../System/SoundPlayer.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
/// <param name="argSceneChanger">SceneChanger�̃|�C���^</param>
TitleScene::TitleScene(SceneChanger *argSceneChanger):BaseScene(argSceneChanger){

	SoundPlayer::GetInstance().PlayBGM("Title");

	backGroundImage = LoadGraph("Image/Share/BackGround.png");
	titleImage = LoadGraph("Image/Title/Title.png");

	menuImage = new int[Title_Num];
	menuImage[Title_Start] = LoadGraph("Image/Title/TitleMenuStart.png");
	menuImage[Title_Config] = LoadGraph("Image/Title/TitleMenuConfig.png");
	menuImage[Title_Exit] = LoadGraph("Image/Title/TitleMenuExit.png");

	selectMenu = Title_Start;

}

/// <summary>
/// �f�X�g���N�^
/// </summary>
TitleScene::~TitleScene(){

	delete[] menuImage;

}

/// <summary>
/// �X�V�������s��
/// </summary>
void TitleScene::Update(){

#ifdef _DEBUG
	if(KeyboardManager::GetInstance().Input(KEY_INPUT_ESCAPE) == 1){
		sceneChanger->SetNextScene(Scene_End);
	}

	if(KeyboardManager::GetInstance().Input(KEY_INPUT_A) == 1){
		sceneChanger->SetNextScene(Scene_Game);
	}
#endif //ESC�ŃQ�[���I���AA�ŃQ�[���V�[���ֈړ�

	//���j���[�̏㉺
	if(KeyboardManager::GetInstance().Input(KEY_INPUT_DOWN) == 1){
		SoundPlayer::GetInstance().PlaySE("Menu1");
		selectMenu = (eTitleMenu)((selectMenu + 1) % Title_Num);
	}
	if(KeyboardManager::GetInstance().Input(KEY_INPUT_UP) == 1){
		SoundPlayer::GetInstance().PlaySE("Menu1");
		selectMenu = (eTitleMenu)((selectMenu + (Title_Num - 1)) % Title_Num);
	}

	//���j���[�̑I��
	if(KeyboardManager::GetInstance().Input(KEY_INPUT_SPACE) == 1){
		SoundPlayer::GetInstance().PlaySE("Menu2");
		//�I�����ꂽ���j���[�ɂ���ăV�[����؂�ւ���
		switch(selectMenu){
			case Title_Start:
				sceneChanger->SetNextScene(Scene_Game);
				break;
			case Title_Config:
				sceneChanger->SetNextScene(Scene_Config);
				break;
			case Title_Exit:
				sceneChanger->SetNextScene(Scene_End);
				break;
		}
	}

}

/// <summary>
/// �`�揈�����s��
/// </summary>
void TitleScene::Draw(){

	//�w�i
	DrawGraph(0, 0, backGroundImage, TRUE);
	//�^�C�g��
	DrawGraph(0, 0, titleImage,TRUE);

	int drawAlpha[Title_Num] = { 128,128,128 };

	//�I������Ă��郁�j���[�ȊO�͔����\������
	drawAlpha[selectMenu] = 255;
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, drawAlpha[Title_Start]);
	DrawGraph(0, 0, menuImage[Title_Start], TRUE);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, drawAlpha[Title_Config]);
	DrawGraph(0, 0, menuImage[Title_Config], TRUE);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, drawAlpha[Title_Exit]);
	DrawGraph(0, 0, menuImage[Title_Exit], TRUE);

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

}