/*****************************************************************************************************
-----ファイル概要-----
座標を管理するクラス
******************************************************************************************************/

#pragma once

template <class Type> class C_Position{

public:
	C_Position(){

		x = 0;
		y = 0;
	
	}
	C_Position(Type x, Type y){

		this->x = x;
		this->y = y;

	}
	~C_Position(){}
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

	//描画関数用(DxLibのDraw系)
	//x,yをintにキャストした値を返す
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