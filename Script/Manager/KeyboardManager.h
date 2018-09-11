/*****************************************************************************************************
-----ファイル概要-----
キーボードの入力を管理するクラス
館のそのまま
******************************************************************************************************/

#pragma once

#include "../System/Singleton.h"

class C_KeyboardManager : public C_Singleton<C_KeyboardManager>{

public:
	friend class C_Singleton<C_KeyboardManager>;
	virtual void Create() override;
	virtual void Destroy() override;
	void Update();
	int Input(int argKeyCode);

protected:
	C_KeyboardManager(){ }
	virtual ~C_KeyboardManager(){ }

private:
	static const int Key_Type_Num;
	int *arrKeyFrame;

};