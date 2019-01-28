/*****************************************************************************************************
-----�t�@�C���T�v-----
�Q�[���S�̂��Ǘ�����N���X
Main�ł͂��̃N���X�݂̂𐶐�����
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

