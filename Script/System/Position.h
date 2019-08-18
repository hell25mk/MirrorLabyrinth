/*****************************************************************************************************
-----ファイル概要-----
座標を管理するクラス
******************************************************************************************************/

#pragma once

template <class Type> class Position{

public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	Position() : Position(0, 0) {
	}

	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="x">xの値</param>
	/// <param name="y">yの値</param>
	Position(Type x, Type y){

		this->x = x;
		this->y = y;

	}

	/// <summary>
	/// デストラクタ
	/// </summary>
	~Position(){}

	/// <summary>
	/// 座標の値を更新する
	/// </summary>
	/// <param name="x">xの値</param>
	/// <param name="y">yの値</param>
	void SetPosition(Type x, Type y){

		this->x = x;
		this->y = y;

	}

	/// <summary>
	/// xの値を更新する
	/// </summary>
	/// <param name="x">xの値</param>
	void SetX(Type x){

		this->x = x;

	}

	/// <summary>
	/// yの値を更新する
	/// </summary>
	/// <param name="y">yの値</param>
	void SetY(Type y){

		this->y = y;

	}
	
	/// <summary>
	/// xの値を取得する
	/// </summary>
	/// <returns>xの値</returns>
	Type GetX(){

		return x;
	}

	/// <summary>
	/// yの値を取得する
	/// </summary>
	/// <returns>yの値</returns>
	Type GetY(){

		return y;
	}

	/// <summary>
	/// intにキャストしたx値を取得する(DxLibのDraw系関数でintを使うことが多いため)
	/// </summary>
	/// <returns>intキャストしたxの値</returns>
	int GetDx(){

		return (int)x;
	}

	/// <summary>
	/// intにキャストしたy値を取得する
	/// </summary>
	/// <returns>intキャストしたyの値</returns>
	int GetDy(){

		return (int)y;
	}

private:
	Type x;
	Type y;

};