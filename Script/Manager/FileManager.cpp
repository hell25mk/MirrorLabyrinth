#include "FileManager.h"
#include "DxLib.h"

void FileManager::Create(){



}

void FileManager::Destroy(){



}

int FileManager::FileOpen(char* fileDirectory){

	//�t�@�C�����J��
	filePoint = FileRead_open(fileDirectory);

	//�t�@�C�����J���Ȃ�������
	if(filePoint == NULL){
		return NULL;
	}

	return filePoint;
}


void FileManager::FileClose(){

	FileRead_close(filePoint);

}
