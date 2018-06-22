/*-----------------------------------------------------------------------
����		�F����
�Q�[��		�F���H
�Q�[���T�v	�F�㉺�ɋ��ʂ��ɂȂ��Ă���v���C���[���S�[���܂œ���
�Q�[����	�FMirrorLabyrinth (���̖��{)
------------------------------------------------------------------------*/
#include "DxLib.h"
#include "Manager/GameManager.h"

void WindowInit();			//�E�B���h�E�������֐�
bool ProcessLoop();			//DxLib���[�v�����֐�

const int Window_Width = 896;
const int Window_Height = 480;
const int Color_Bit = 32;
const char *Game_Title = "Mirror Labyrinth";

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){

	WindowInit();

	//DxLib������
	if(DxLib_Init() == -1){
		return -1;
	}
	SetDrawScreen(DX_SCREEN_BACK);

	C_GameManager::GetInstance().Create();

	while(ProcessLoop()){

		if(!(C_GameManager::GetInstance().Update())){
			break;
		}

		C_GameManager::GetInstance().Draw();

	}

	C_GameManager::GetInstance().Destroy();

	DxLib_End();		//DxLib�I��

	return 0;
}

void WindowInit(){

	ChangeWindowMode(TRUE);										//�E�B���h�E���[�h�ɕύX
	SetGraphMode(Window_Width, Window_Height, Color_Bit);		//�E�B���h�E�̃T�C�Y��ύX
	SetWaitVSyncFlag(FALSE);									//�������������Ȃ�(FPS�����ɕK�v)
	SetMainWindowText(Game_Title);								//�E�B���h�E�^�C�g����ݒ�
	SetWindowIconID(25);										//�E�B���h�E�A�C�R���pID
	ChangeFont("PixelMplus12", DX_CHARSET_DEFAULT);				//�t�H���g�̕ύX

}

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