#include "StageClear.h"
#include "DxLib.h"

/// <summary>
/// �����o������������
/// </summary>
/// <param name="argSceneChanger">SceneChanger�̃|�C���^</param>
StageClear::StageClear(GameScene *argGameScene):GameState(argGameScene){

	nowStageNum = gameScene->GetStageNum();
	LoadDivGraph("Image/Share/Number.png", 10, 10, 1, 96, 96, numberImage);
	stageClearImage = LoadGraph("Image/Game/StageClear.png");

}

/// <summary>
/// ���������m�ۂ��Ă����ꍇ�͉������
/// </summary>
StageClear::~StageClear(){
}

/// <summary>
/// 1���[�v���ŕK�v�ȍX�V�������s��
/// </summary>
void StageClear::Update(){

	if(KeyboardManager::GetInstance().Input(KEY_INPUT_SPACE) == 1){
		int nextStageNum = nowStageNum + 1;
		bool stageCheckFlag = nextStageNum > gameScene->Max_Stage_Num;

		if(!stageCheckFlag){
			gameScene->SetStageNum(nextStageNum);
			gameScene->SetGameState(gameScene->State_GameStart);
			return;
		}

		gameScene->SetGameState(gameScene->State_GameClear);
	}

}

/// <summary>
/// 1���[�v���ŕK�v�ȕ`�揈�����s��
/// </summary>
void StageClear::Draw(){

	//�X�e�[�W����1����2�����ɂ���ď�����ς���
	bool drawStageNumFlag = nowStageNum < 10;
	if(drawStageNumFlag){
		DrawRotaGraph(400, 150, 1.2, 0.0, numberImage[nowStageNum], TRUE);
	} else{
		DrawRotaGraph(340, 150, 1.2, 0.0, numberImage[nowStageNum / 10], TRUE);		//2����
		DrawRotaGraph(420, 150, 1.2, 0.0, numberImage[nowStageNum % 10], TRUE);		//1����
	}

	DrawGraph(0, 0, stageClearImage, TRUE);
	
}