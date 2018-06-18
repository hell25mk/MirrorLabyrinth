#include "KeyboardManager.h"
#include "DxLib.h"

const int C_KeyboardManager::Key_Type_Num = 256;

void C_KeyboardManager::Create(){

	arrKeyFrame = new int[Key_Type_Num];

}

void C_KeyboardManager::Destroy(){

	delete[] arrKeyFrame;

}

void C_KeyboardManager::Update(){

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

int C_KeyboardManager::Input(int argKeyCode){

	return arrKeyFrame[argKeyCode];
}