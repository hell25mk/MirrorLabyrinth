/*****************************************************************************************************
-----�t�@�C���T�v-----
���W���Ǘ�����N���X
******************************************************************************************************/

#pragma once

template <class Type> class Position{

public:
	Position(){

		x = 0;
		y = 0;
	
	}
	Position(Type x, Type y){

		this->x = x;
		this->y = y;

	}
	~Position(){}
	//setter
	void SetPosition(Type x, Type y){

		this->x = x;
		this->y = y;

	}
	void SetX(Type x){

		this->x = x;

	}
	void SetY(Type y){

		this->y = y;

	}
	//getter
	Type GetX(){

		return x;
	}
	Type GetY(){

		return y;
	}

	//�`��֐��p(DxLib��Draw�n)
	//x,y��int�ɃL���X�g�����l��Ԃ�
	int GetDx(){

		return (int)x;
	}
	int GetDy(){

		return (int)y;
	}

private:
	Type x;
	Type y;

};