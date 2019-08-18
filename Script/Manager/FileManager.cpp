#include "FileManager.h"
#include "DxLib.h"

/// <summary>
/// 初期化処理を行う
/// </summary>
void FileManager::Create(){
}

/// <summary>
/// 終了処理を行う
/// </summary>
void FileManager::Destroy(){
}

/// <summary>
/// ファイルを開く
/// </summary>
/// <param name="fileDirectory">開くファイルの階層</param>
/// <returns>開いたファイルポを格納した変数</returns>
int FileManager::FileOpen(char* fileDirectory){

	//ファイルを開く
	filePoint = FileRead_open(fileDirectory);

	//ファイルが開けなかったら
	if(filePoint == NULL){
		return NULL;
	}

	return filePoint;
}

/// <summary>
/// 開いたファイルを閉じる
/// </summary>
void FileManager::FileClose(){

	FileRead_close(filePoint);

}
