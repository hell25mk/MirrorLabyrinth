#pragma once

#include "../System/Singleton.h"

class C_SceneManager;

class C_GameManager : public C_Singleton<C_GameManager>{

public:
	friend class C_Singleton<C_GameManager>;
	virtual void Create() override;
	virtual void Destroy() override;
	bool Update();
	void Draw();

protected:
	C_GameManager(){ }
	virtual ~C_GameManager(){ }

private:
	C_SceneManager *sceneManager;

};

