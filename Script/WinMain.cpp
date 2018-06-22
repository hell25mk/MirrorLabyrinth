/*-----------------------------------------------------------------------
お題		：うつす
ゲーム		：迷路
ゲーム概要	：上下に鏡写しになっているプレイヤーをゴールまで導く
ゲーム名	：MirrorLabyrinth (鏡の迷宮)
------------------------------------------------------------------------*/
#include "DxLib.h"
#include "Manager/GameManager.h"

void WindowInit();			//ウィンドウ初期化関数
bool ProcessLoop();			//DxLibループ処理関数

const int Window_Width = 896;
const int Window_Height = 480;
const int Color_Bit = 32;
const char *Game_Title = "Mirror Labyrinth";

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){

	WindowInit();

	//DxLib初期化
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

	DxLib_End();		//DxLib終了

	return 0;
}

void WindowInit(){

	ChangeWindowMode(TRUE);										//ウィンドウモードに変更
	SetGraphMode(Window_Width, Window_Height, Color_Bit);		//ウィンドウのサイズを変更
	SetWaitVSyncFlag(FALSE);									//垂直同期を取らない(FPS調整に必要)
	SetMainWindowText(Game_Title);								//ウィンドウタイトルを設定
	SetWindowIconID(25);										//ウィンドウアイコン用ID
	ChangeFont("PixelMplus12", DX_CHARSET_DEFAULT);				//フォントの変更

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