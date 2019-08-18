/*****************************************************************************************************
-----�t�@�C���T�v-----
�t�@�C���̊J���Ǘ�����N���X
******************************************************************************************************/

#pragma once

#include "../System/Singleton.h"

class FileManager : public Singleton<FileManager>{

public:
	friend class Singleton<FileManager>;
	/// <summary>
	/// �������������s��
	/// </summary>
	virtual void Create() override;
	/// <summary>
	/// �I���������s��
	/// </summary>
	virtual void Destroy() override;

	/// <summary>
	/// �t�@�C�����J��
	/// </summary>
	/// <param name="fileDirectory">�J���t�@�C���̊K�w</param>
	/// <returns>�J�����t�@�C�����i�[�����ϐ�</returns>
	int FileOpen(char* fileDirectory);
	/// <summary>
	/// �J�����t�@�C�������
	/// </summary>
	void FileClose();
	
protected:
	FileManager() : filePoint(){ }
	virtual ~FileManager(){ }

private:
	int filePoint;

};

