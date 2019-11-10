#include "GameStart.h"
#include "DxLib.h"
#include "../../System/SoundPlayer.h"

/// <summary>
/// �����o������������
/// </summary>
/// <param name="argSceneChanger">SceneChanger�̃|�C���^</param>
GameStart::GameStart(GameScene* argGameScene):GameState(argGameScene){

	nowStageNum = gameScene->GetStageNum();
	SoundPlayer::GetInstance().PlayBGM("Stage");

	LoadDivGraph("Image/Share/Number.png", 10, 10, 1, 96, 96, numberImage);
	floorImage = LoadGraph("Image/Game/Floor.png");

}

/// <summary>
/// ���������m�ۂ��Ă����ꍇ�͉������
/// </summary>
GameStart::~GameStart(){
}

/// <summary>
/// 1���[�v���ŕK�v�ȍX�V�������s��
/// </summary>
void GameStart::Update(){

	if(KeyboardManager::GetInstance().Input(KEY_INPUT_SPACE) == 1){
		gameScene->SetGameState(gameScene->State_GamePlay);
	}

}

/// <summary>
/// 1���[�v���ŕK�v�ȕ`�揈�����s��
/// </summary>
void GameStart::Draw(){

	//�X�e�[�W��1����2�����ŏ�����؂�ւ���
	bool isDrawStageNum = nowStageNum < 10;
	if(isDrawStageNum){
		DrawRotaGraph(400, 150, 1.2, 0.0, numberImage[nowStageNum], TRUE);
	} else{
		DrawRotaGraph(340, 150, 1.2, 0.0, numberImage[nowStageNum / 10], TRUE);		//2����
		DrawRotaGraph(420, 150, 1.2, 0.0, numberImage[nowStageNum % 10], TRUE);		//1����
	}

	DrawGraph(0, 0, floorImage, TRUE);

}