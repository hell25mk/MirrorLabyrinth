/*****************************************************************************************************
-----ファイル概要-----
キーボードの入力を管理するクラス
館のそのまま
******************************************************************************************************/

#pragma once

#include "../System/Singleton.h"

class KeyboardManager : public Singleton<KeyboardManager>{

public:
	friend class Singleton<KeyboardManager>;
	virtual void Create() override;
	virtual void Destroy() override;
	void Update();
	int Input(int argKeyCode);

protected:
	KeyboardManager(){ }
	virtual ~KeyboardManager(){ }

private:
	static const int Key_Type_Num;
	int* arrKeyFrame;

};