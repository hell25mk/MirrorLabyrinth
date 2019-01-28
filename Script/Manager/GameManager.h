/*****************************************************************************************************
-----ファイル概要-----
ゲーム全体を管理するクラス
Mainではこのクラスのみを生成する
******************************************************************************************************/

#pragma once

#include "../System/Singleton.h"

class SceneManager;

class GameManager : public Singleton<GameManager>{

public:
	friend class Singleton<GameManager>;
	virtual void Create() override;
	virtual void Destroy() override;
	bool Update();
	void Draw();

protected:
	GameManager(){ }
	virtual ~GameManager(){ }

private:
	SceneManager* sceneManager;

};

