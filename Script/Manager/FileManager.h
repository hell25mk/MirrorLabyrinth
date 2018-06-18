#pragma once

#include "../System/Singleton.h"

class C_FileManager : public C_Singleton<C_FileManager>{

public:
	friend class C_Singleton<C_FileManager>;
	virtual void Create() override;
	virtual void Destroy() override;
	int FileOpen(char *fileDirectory);
	void FileClose();
	
protected:
	C_FileManager(){ }
	virtual ~C_FileManager(){ }

private:
	int filePoint;

};

