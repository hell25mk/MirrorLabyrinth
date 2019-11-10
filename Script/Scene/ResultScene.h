/*****************************************************************************************************
-----�t�@�C���T�v-----
���U���g�V�[��
******************************************************************************************************/

#pragma once

#include "../Base/BaseScene.h"

class ResultScene : public BaseScene{

public:
	/// <summary>
	/// �����o������������
	/// </summary>
	/// <param name="argSceneChanger">SceneChanger�̃|�C���^</param>
	ResultScene(SceneChanger* argSceneChanger);
	/// <summary>
	/// ���������m�ۂ��Ă����ꍇ�͉������
	/// </summary>
	virtual ~ResultScene();

	/// <summary>
	/// 1���[�v���ŕK�v�ȍX�V�������s��
	/// </summary>
	void Update() override;
	/// <summary>
	/// 1���[�v���ŕK�v�ȕ`�揈�����s��
	/// </summary>
	void Draw() override;

private:
	int resultImage;
	int pleaseKeyImage;
	int flashCount;
	bool willFlash;

};
