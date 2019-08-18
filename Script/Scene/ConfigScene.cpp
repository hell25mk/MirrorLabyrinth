#include "ConfigScene.h"
#include "../System/GameInfo.h"
#include "../System/SoundPlayer.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
/// <param name="argSceneChanger">SceneChanger�̃|�C���^</param>
ConfigScene::ConfigScene(SceneChanger* argSceneChanger) : BaseScene(argSceneChanger),selectMenu(){
	
	//�w�i�摜
	backGroundImage = LoadGraph("Image/Share/BackGround.png");

	//���j���[��ʂ̉摜
	menuImage = new int[Config_Num];
	menuImage[Config_GameLevel] = LoadGraph("Image/Config/ConfigMenuGameLevel.png");
	menuImage[Config_Exit] = LoadGraph("Image/Config/ConfigMenuBack.png");

	//��Փx�̉摜
	levelImage = new int[Level_Num];
	levelImage[Level_Easy] = LoadGraph("Image/Config/EasyLevel.png");
	levelImage[Level_Normal] = LoadGraph("Image/Config/NormalLevel.png");
	levelImage[Level_Hard] = LoadGraph("Image/Config/HardLevel.png");

	//��Փx�̐����摜
	contentImage = new int[Level_Num];
	contentImage[Level_Easy] = LoadGraph("Image/Config/EasyLevelContent.png");
	contentImage[Level_Normal] = LoadGraph("Image/Config/NormalLevelContent.png");
	contentImage[Level_Hard] = LoadGraph("Image/Config/HardLevelContent.png");

}

/// <summary>
/// �f�X�g���N�^
/// </summary>
ConfigScene::~ConfigScene(){

	delete[] contentImage;
	delete[] levelImage;
	delete[] menuImage;

}

/// <summary>
/// �X�V�������s��
/// </summary>
void ConfigScene::Update(){

#ifdef _DEBUG
	if(KeyboardManager::GetInstance().Input(KEY_INPUT_ESCAPE) == 1){
		sceneChanger->SetNextScene(Scene_Title);
	}
#endif //ESC�Ń^�C�g���֖߂�

	UpdateMenuSelect();

	//�Q�[�����x����I�����Ă��Ȃ��Ȃ珈�����I����
	if (selectMenu != Config_GameLevel) {
		return;
	}

	UpdateGameLevel();
	
}

/// <summary>
///	�`�揈�����s��
/// </summary>
void ConfigScene::Draw(){

	DrawGraph(0, 0, backGroundImage, TRUE);		//�q�[�̕`��
	DrawMenu();
	DrawGameLevel();

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

}

/// <summary>
/// �I������Ă��郁�j���[���X�V����
/// </summary>
void ConfigScene::UpdateMenuSelect() {

	//���j���[�̏㉺
	if (KeyboardManager::GetInstance().Input(KEY_INPUT_DOWN) == 1) {
		SoundPlayer::GetInstance().PlaySE("Menu1");
		selectMenu = (eConfigMenu)((selectMenu + 1) % Config_Num);
	}
	if (KeyboardManager::GetInstance().Input(KEY_INPUT_UP) == 1) {
		SoundPlayer::GetInstance().PlaySE("Menu1");
		selectMenu = (eConfigMenu)((selectMenu + (Config_Num - 1)) % Config_Num);
	}

	//���j���[�̑I��
	if (KeyboardManager::GetInstance().Input(KEY_INPUT_SPACE) == 1) {
		if (selectMenu == Config_Exit) {
			SoundPlayer::GetInstance().PlaySE("Menu2");
			sceneChanger->SetNextScene(Scene_Title);
		}
	}

}

/// <summary>
/// �Q�[�����x�����X�V����
/// </summary>
void ConfigScene::UpdateGameLevel() {

	//�Q�[�����x���̑I��
	if (KeyboardManager::GetInstance().Input(KEY_INPUT_LEFT) == 1) {
		SoundPlayer::GetInstance().PlaySE("Menu1");
		GameInfo::GetInstance().DownGameLevel();
	}
	if (KeyboardManager::GetInstance().Input(KEY_INPUT_RIGHT) == 1) {
		SoundPlayer::GetInstance().PlaySE("Menu1");
		GameInfo::GetInstance().UpGameLevel();
	}

	/*switch(selectMenu){
		case Config_GameLevel:
			if(KeyboardManager::GetInstance().Input(KEY_INPUT_LEFT) == 1){
				SoundPlayer::GetInstance().PlaySE("Menu1");
				GameInfo::GetInstance().DownGameLevel();
			}
			if(KeyboardManager::GetInstance().Input(KEY_INPUT_RIGHT) == 1){
				SoundPlayer::GetInstance().PlaySE("Menu1");
				GameInfo::GetInstance().UpGameLevel();
			}
			break;
	}*/

}

/// <summary>
/// ���j���[�֘A��\������
/// </summary>
void ConfigScene::DrawMenu(){

	int drawAlpha[2] = { 128,128 };

	drawAlpha[selectMenu] = 255;

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, drawAlpha[Config_GameLevel]);
	DrawGraph(0, 0, menuImage[Config_GameLevel], TRUE);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, drawAlpha[Config_Exit]);
	DrawGraph(0, 0, menuImage[Config_Exit], TRUE);

}

/// <summary>
/// �Q�[�����x���֘A��`�悷��
/// </summary>
void ConfigScene::DrawGameLevel(){

	int drawAlpha[3] = { 128,128,128 };
	eGameLevel gameLevel = GameInfo::GetInstance().GetGameLevel();

	//���ݑI������Ă���Q�[�����x���̓����x���ő�ɂ���(���߂����Ȃ�)
	drawAlpha[gameLevel] = 255;

	//�e���x���̉摜��\������(�I������Ă��郌�x���ȊO�͔����\�������)
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, drawAlpha[Level_Easy]);
	DrawGraph(0, 0, levelImage[Level_Easy], TRUE);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, drawAlpha[Level_Normal]);
	DrawGraph(0, 0, levelImage[Level_Normal], TRUE);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, drawAlpha[Level_Hard]);
	DrawGraph(0, 0, levelImage[Level_Hard], TRUE);

	//���x���̐����e�L�X�g��\������
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
	DrawGraph(0, 0, contentImage[gameLevel], TRUE);

}