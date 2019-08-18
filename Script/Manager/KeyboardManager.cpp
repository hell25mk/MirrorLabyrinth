#include "KeyboardManager.h"
#include "DxLib.h"

const int KeyboardManager::Key_Type_Num = 256;

/// <summary>
/// 初期化処理を行う
/// </summary>
void KeyboardManager::Create(){

	arrKeyFrame = new int[Key_Type_Num];

}

/// <summary>
/// 終了処理を行う
/// </summary>
void KeyboardManager::Destroy(){

	delete[] arrKeyFrame;

}

/// <summary>
/// 更新処理を行う
/// </summary>
void KeyboardManager::Update(){

	char tmpKey[Key_Type_Num];

	GetHitKeyStateAll(tmpKey);
	
	for(int i = 0; i < Key_Type_Num; i++){

		if(tmpKey[i] != 0){
			arrKeyFrame[i]++;
		} else{
			arrKeyFrame[i] = 0;
		}

	}

}

/// <summary>
/// そのキーが現在どのくらい押されているかを返す
/// </summary>
/// <param name="argKeyCode">キーコード</param>
/// <returns>押されているフレーム数</returns>
int KeyboardManager::Input(int argKeyCode){

	return arrKeyFrame[argKeyCode];
}