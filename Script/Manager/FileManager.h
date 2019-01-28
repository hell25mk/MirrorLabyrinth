/*****************************************************************************************************
-----�t�@�C���T�v-----
�t�@�C���̊J���Ǘ�����N���X
******************************************************************************************************/

#pragma once

#include "../System/Singleton.h"

class FileManager : public Singleton<FileManager>{

public:
	friend class Singleton<FileManager>;
	virtual void Create() override;
	virtual void Destroy() override;
	int FileOpen(char* fileDirectory);
	void FileClose();
	
protected:
	FileManager(){ }
	virtual ~FileManager(){ }

private:
	int filePoint;

};

