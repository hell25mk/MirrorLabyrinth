#include "FileManager.h"
#include "DxLib.h"

void FileManager::Create(){



}

void FileManager::Destroy(){



}

int FileManager::FileOpen(char* fileDirectory){

	//ファイルを開く
	filePoint = FileRead_open(fileDirectory);

	//ファイルが開けなかったら
	if(filePoint == NULL){
		return NULL;
	}

	return filePoint;
}


void FileManager::FileClose(){

	FileRead_close(filePoint);

}
