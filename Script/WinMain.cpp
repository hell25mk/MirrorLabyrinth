/*--------------------------------------------------------------------------------------------------------------------*
*<file>WinMain.cpp</file>
*<summary>
*DXライブラリ関連の初期化やメインループを行う
*</summary>
*---------------------------------------------------------------------------------------------------------------------*/

#include "DxLib.h"
#include <ctime>
#include "Manager/GameManager.h"

void WindowInit();			//ウィンドウ初期化関数
bool ProcessLoop();			//DxLibループ処理関数

const int Window_Width = 896;
const int Window_Height = 480;
const int Color_Bit = 32;
const char *Game_Title = "Mirror Labyrinth";
const int Window_IconID = 25;

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPTSTR lpszCmdLine, _In_ int nCmdShow){

	SRand((int)time(NULL));

	WindowInit();
	//DxLib初期化
	if(DxLib_Init() == -1){
		return -1;
	}
	SetDrawScreen(DX_SCREEN_BACK);

	GameManager::GetInstance().Create();

	while(ProcessLoop()){

		//falseが返ってくるまでゲームを続ける
		if(!(GameManager::GetInstance().Update())){
			break;
		}

		GameManager::GetInstance().Draw();

	}

	GameManager::GetInstance().Destroy();

	DxLib_End();		//DxLib終了

	return 0;
}

/// <summary>
/// ウィンドウ生成前に行う初期化処理
/// </summary>
void WindowInit(){

	ChangeWindowMode(TRUE);										//ウィンドウモードに変更
	SetGraphMode(Window_Width, Window_Height, Color_Bit);		//ウィンドウのサイズを変更
	SetWaitVSyncFlag(FALSE);									//垂直同期を取らない(FPS調整に必要)
	SetMainWindowText(Game_Title);								//ウィンドウタイトルを設定
	SetWindowIconID(Window_IconID);								//ウィンドウアイコン用ID
	ChangeFont("PixelMplus12", DX_CHARSET_DEFAULT);				//フォントの変更

}

/// <summary>
/// DxLibのループに必要な処理
/// </summary>
/// <returns>1つでも失敗した場合falseを返す</returns>
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