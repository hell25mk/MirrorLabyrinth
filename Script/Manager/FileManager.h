/*****************************************************************************************************
-----ファイル概要-----
ファイルの開閉を管理するクラス
******************************************************************************************************/

#pragma once

#include "../System/Singleton.h"

class FileManager : public Singleton<FileManager>{

public:
	friend class Singleton<FileManager>;
	/// <summary>
	/// 初期化処理を行う
	/// </summary>
	virtual void Create() override;
	/// <summary>
	/// 終了処理を行う
	/// </summary>
	virtual void Destroy() override;

	/// <summary>
	/// ファイルを開く
	/// </summary>
	/// <param name="fileDirectory">開くファイルの階層</param>
	/// <returns>開いたファイルを格納した変数</returns>
	int FileOpen(char* fileDirectory);
	/// <summary>
	/// 開いたファイルを閉じる
	/// </summary>
	void FileClose();
	
protected:
	FileManager() : filePoint(){ }
	virtual ~FileManager(){ }

private:
	int filePoint;

};

