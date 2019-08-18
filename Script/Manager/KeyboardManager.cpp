#include "KeyboardManager.h"
#include "DxLib.h"

const int KeyboardManager::Key_Type_Num = 256;

/// <summary>
/// �������������s��
/// </summary>
void KeyboardManager::Create(){

	arrKeyFrame = new int[Key_Type_Num];

}

/// <summary>
/// �I���������s��
/// </summary>
void KeyboardManager::Destroy(){

	delete[] arrKeyFrame;

}

/// <summary>
/// �X�V�������s��
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
/// ���̃L�[�����݂ǂ̂��炢������Ă��邩��Ԃ�
/// </summary>
/// <param name="argKeyCode">�L�[�R�[�h</param>
/// <returns>������Ă���t���[����</returns>
int KeyboardManager::Input(int argKeyCode){

	return arrKeyFrame[argKeyCode];
}