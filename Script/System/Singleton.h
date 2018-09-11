/*****************************************************************************************************
-----�t�@�C���T�v-----
�h���N���X���B��ł��邽�߂̃N���X
2�ȏ�I�u�W�F�N�g����������Ȃ��悤�ɂ��邽�߂̂���
******************************************************************************************************/

#pragma once

template <class Type> class C_Singleton{

public:
	static Type& GetInstance(){

		static Type instance;
		return instance;
	}
	virtual void Create(){ }
	virtual void Destroy(){ }

protected:
	C_Singleton(){ }
	virtual ~C_Singleton(){ }

private:
	void operator=(const C_Singleton& obj){ }	//������Z�q�֎~
	C_Singleton(const C_Singleton &obj){ }		//�R�s�[�R���X�g���N�^�֎~

};

