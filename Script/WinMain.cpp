/*--------------------------------------------------------------------------------------------------------------------*
*<file>WinMain.cpp</file>
*<summary>
*DX���C�u�����֘A�̏������⃁�C�����[�v���s��
*</summary>
*---------------------------------------------------------------------------------------------------------------------*/

#include "DxLib.h"
#include <ctime>
#include "Manager/GameManager.h"

void WindowInit();			//�E�B���h�E�������֐�
bool ProcessLoop();			//DxLib���[�v�����֐�

const int Window_Width = 896;
const int Window_Height = 480;
const int Color_Bit = 32;
const char *Game_Title = "Mirror Labyrinth";
const int Window_IconID = 25;

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPTSTR lpszCmdLine, _In_ int nCmdShow){

	SRand((int)time(NULL));

	WindowInit();
	//DxLib������
	if(DxLib_Init() == -1){
		return -1;
	}
	SetDrawScreen(DX_SCREEN_BACK);

	GameManager::GetInstance().Create();

	while(ProcessLoop()){

		//false���Ԃ��Ă���܂ŃQ�[���𑱂���
		if(!(GameManager::GetInstance().Update())){
			break;
		}

		GameManager::GetInstance().Draw();

	}

	GameManager::GetInstance().Destroy();

	DxLib_End();		//DxLib�I��

	return 0;
}

/// <summary>
/// �E�B���h�E�����O�ɍs������������
/// </summary>
void WindowInit(){

	ChangeWindowMode(TRUE);										//�E�B���h�E���[�h�ɕύX
	SetGraphMode(Window_Width, Window_Height, Color_Bit);		//�E�B���h�E�̃T�C�Y��ύX
	SetWaitVSyncFlag(FALSE);									//�������������Ȃ�(FPS�����ɕK�v)
	SetMainWindowText(Game_Title);								//�E�B���h�E�^�C�g����ݒ�
	SetWindowIconID(Window_IconID);								//�E�B���h�E�A�C�R���pID
	ChangeFont("PixelMplus12", DX_CHARSET_DEFAULT);				//�t�H���g�̕ύX

}

/// <summary>
/// DxLib�̃��[�v�ɕK�v�ȏ���
/// </summary>
/// <returns>1�ł����s�����ꍇfalse��Ԃ�</returns>
bool ProcessLoop(){

	if(ScreenFlip() != 0){
		return false;
	}
	
	if(ProcessMessage() != 0){
		return false;
	}

	if(ClearDrawScreen() != 0){
		return false;
	}

	return true;
}