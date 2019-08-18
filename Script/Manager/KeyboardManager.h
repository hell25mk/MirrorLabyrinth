/*****************************************************************************************************
-----ファイル概要-----
キーボードの入力を管理するクラス
******************************************************************************************************/

#pragma once

#include "../System/Singleton.h"

class KeyboardManager : public Singleton<KeyboardManager>{

public:
	friend class Singleton<KeyboardManager>;
	/// <summary>
	/// 初期化処理を行う
	/// </summary>
	virtual void Create() override;
	/// <summary>
	/// 終了処理を行う
	/// </summary>
	virtual void Destroy() override;

	/// <summary>
	/// 更新処理を行う
	/// </summary>
	void Update();

	/// <summary>
	/// そのキーが現在どのくらい押されているかを返す
	/// </summary>
	/// <param name="argKeyCode">キーコード</param>
	/// <returns>押されているフレーム数</returns>
	int Input(int argKeyCode);

protected:
	KeyboardManager() : arrKeyFrame(){ }
	virtual ~KeyboardManager(){ }

private:
	static const int Key_Type_Num;
	int* arrKeyFrame;

};