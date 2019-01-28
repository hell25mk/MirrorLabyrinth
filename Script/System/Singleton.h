/*****************************************************************************************************
-----�t�@�C���T�v-----
�h���N���X���B��ł��邽�߂̃N���X
2�ȏ�I�u�W�F�N�g����������Ȃ��悤�ɂ��邽�߂̂���
******************************************************************************************************/

#pragma once

template <class Type> class Singleton{

public:
	static Type& GetInstance(){

		static Type instance;
		return instance;
	}
	virtual void Create(){ }
	virtual void Destroy(){ }

protected:
	Singleton(){ }
	virtual ~Singleton(){ }

private:
	void operator=(const Singleton& obj){ }	//������Z�q�֎~
	Singleton(const Singleton &obj){ }		//�R�s�[�R���X�g���N�^�֎~

};

