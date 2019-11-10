/*****************************************************************************************************
-----�t�@�C���T�v-----
�h���N���X���B��ł��邽�߂̃N���X
2�ȏ�I�u�W�F�N�g����������Ȃ��悤�ɂ��邽�߂̂���
******************************************************************************************************/

#pragma once

template <class Type> class Singleton{

public:
	/// <summary>
	/// �C���X�^���X���擾����
	/// </summary>
	/// <returns>�쐬����[Type]�N���X</returns>
	static Type& GetInstance(){

		static Type instance;

		return instance;
	}
	/// <summary>
	/// �������������s��
	/// </summary>
	virtual void Create(){ }
	/// <summary>
	///	�I���������s��
	/// </summary>
	virtual void Destroy(){ }

protected:
	//����ɐ����ł��Ȃ��悤��protected�C���q�ɂ��Ă���
	Singleton(){ }
	virtual ~Singleton(){ }

private:
	void operator=(const Singleton& obj){ }		//������Z�q���֎~����
	Singleton(const Singleton &obj){ }			//�R�s�[�����o��������������֎~����

};

