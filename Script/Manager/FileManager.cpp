#include "FileManager.h"
#include "DxLib.h"

/// <summary>
/// �������������s��
/// </summary>
void FileManager::Create(){
}

/// <summary>
/// �I���������s��
/// </summary>
void FileManager::Destroy(){
}

/// <summary>
/// �t�@�C�����J��
/// </summary>
/// <param name="fileDirectory">�J���t�@�C���̊K�w</param>
/// <returns>�J�����t�@�C���|���i�[�����ϐ�</returns>
int FileManager::FileOpen(char* fileDirectory){

	//�t�@�C�����J��
	filePoint = FileRead_open(fileDirectory);

	//�t�@�C�����J���Ȃ�������
	if(filePoint == NULL){
		return NULL;
	}

	return filePoint;
}

/// <summary>
/// �J�����t�@�C�������
/// </summary>
void FileManager::FileClose(){

	FileRead_close(filePoint);

}
