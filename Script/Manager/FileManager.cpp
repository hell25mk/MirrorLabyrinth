#include "FileManager.h"
#include "DxLib.h"

void C_FileManager::Create(){



}

void C_FileManager::Destroy(){



}

int C_FileManager::FileOpen(char *fileDirectory){

	//�t�@�C�����J��
	filePoint = FileRead_open(fileDirectory);

	//�t�@�C�����J���Ȃ�������
	if(filePoint == NULL){
		return NULL;
	}

	return filePoint;
}


void C_FileManager::FileClose(){

	FileRead_close(filePoint);

}
