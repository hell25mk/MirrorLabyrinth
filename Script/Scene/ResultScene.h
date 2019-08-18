/*****************************************************************************************************
-----�t�@�C���T�v-----
���U���g�V�[��
******************************************************************************************************/

#pragma once

#include "../Base/BaseScene.h"

class ResultScene : public BaseScene{

public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="argSceneChanger">SceneChanger�̃|�C���^</param>
	ResultScene(SceneChanger* argSceneChanger);
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~ResultScene();

	/// <summary>
	/// �X�V�������s��
	/// </summary>
	void Update() override;
	/// <summary>
	/// �`�揈�����s��
	/// </summary>
	void Draw() override;

private:
	int resultImage;
	int pleaseKeyImage;
	int flashCount;
	bool willFlash;

};
