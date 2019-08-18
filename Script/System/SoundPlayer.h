/*****************************************************************************************************
-----�t�@�C���T�v-----
Sound���Ǘ�����N���X
******************************************************************************************************/

#pragma once

#include "Singleton.h"
#include <map>
#include <string>

class SoundPlayer : public Singleton<SoundPlayer>{

public:
	friend class Singleton<SoundPlayer>;

	/// <summary>
	/// �������������s��
	/// </summary>
	virtual void Create() override;

	/// <summary>
	/// BGM���Đ�����
	/// </summary>
	/// <param name="argKey">�Đ�����BGM�̃L�[���[�h</param>
	void PlayBGM(std::string argKey);
	/// <summary>
	/// BGM���~����
	/// </summary>
	void StopBGM();
	/// <summary>
	/// SE���Đ�����
	/// </summary>
	/// <param name="argKey">�Đ�����SE�̃L�[���[�h</param>
	void PlaySE(std::string argKey);

protected:
	SoundPlayer(){}
	virtual ~SoundPlayer(){}

private:
	std::map<std::string, int> sound;
	std::string nowPlaySound;

};

