/*****************************************************************************************************
-----�t�@�C���T�v-----
���W���Ǘ�����N���X
******************************************************************************************************/

#pragma once

template <class Type> class Position{

public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	Position() : Position(0, 0) {
	}

	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="x">x�̒l</param>
	/// <param name="y">y�̒l</param>
	Position(Type x, Type y){

		this->x = x;
		this->y = y;

	}

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~Position(){}

	/// <summary>
	/// ���W�̒l���X�V����
	/// </summary>
	/// <param name="x">x�̒l</param>
	/// <param name="y">y�̒l</param>
	void SetPosition(Type x, Type y){

		this->x = x;
		this->y = y;

	}

	/// <summary>
	/// x�̒l���X�V����
	/// </summary>
	/// <param name="x">x�̒l</param>
	void SetX(Type x){

		this->x = x;

	}

	/// <summary>
	/// y�̒l���X�V����
	/// </summary>
	/// <param name="y">y�̒l</param>
	void SetY(Type y){

		this->y = y;

	}
	
	/// <summary>
	/// x�̒l���擾����
	/// </summary>
	/// <returns>x�̒l</returns>
	Type GetX(){

		return x;
	}

	/// <summary>
	/// y�̒l���擾����
	/// </summary>
	/// <returns>y�̒l</returns>
	Type GetY(){

		return y;
	}

	/// <summary>
	/// int�ɃL���X�g����x�l���擾����(DxLib��Draw�n�֐���int���g�����Ƃ���������)
	/// </summary>
	/// <returns>int�L���X�g����x�̒l</returns>
	int GetDx(){

		return (int)x;
	}

	/// <summary>
	/// int�ɃL���X�g����y�l���擾����
	/// </summary>
	/// <returns>int�L���X�g����y�̒l</returns>
	int GetDy(){

		return (int)y;
	}

private:
	Type x;
	Type y;

};