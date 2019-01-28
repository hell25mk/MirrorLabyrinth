#include "KeyboardManager.h"
#include "DxLib.h"

const int KeyboardManager::Key_Type_Num = 256;

void KeyboardManager::Create(){

	arrKeyFrame = new int[Key_Type_Num];

}

void KeyboardManager::Destroy(){

	delete[] arrKeyFrame;

}

void KeyboardManager::Update(){

	char tmpKey[256];

	GetHitKeyStateAll(tmpKey);
	
	for(int i = 0; i < Key_Type_Num; i++){

		if(tmpKey[i] != 0){
			arrKeyFrame[i]++;
		} else{
			arrKeyFrame[i] = 0;
		}

	}

}

int KeyboardManager::Input(int argKeyCode){

	return arrKeyFrame[argKeyCode];
}