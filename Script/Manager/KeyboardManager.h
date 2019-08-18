/*****************************************************************************************************
-----�t�@�C���T�v-----
�L�[�{�[�h�̓��͂��Ǘ�����N���X
******************************************************************************************************/

#pragma once

#include "../System/Singleton.h"

class KeyboardManager : public Singleton<KeyboardManager>{

public:
	friend class Singleton<KeyboardManager>;
	/// <summary>
	/// �������������s��
	/// </summary>
	virtual void Create() override;
	/// <summary>
	/// �I���������s��
	/// </summary>
	virtual void Destroy() override;

	/// <summary>
	/// �X�V�������s��
	/// </summary>
	void Update();

	/// <summary>
	/// ���̃L�[�����݂ǂ̂��炢������Ă��邩��Ԃ�
	/// </summary>
	/// <param name="argKeyCode">�L�[�R�[�h</param>
	/// <returns>������Ă���t���[����</returns>
	int Input(int argKeyCode);

protected:
	KeyboardManager() : arrKeyFrame(){ }
	virtual ~KeyboardManager(){ }

private:
	static const int Key_Type_Num;
	int* arrKeyFrame;

};