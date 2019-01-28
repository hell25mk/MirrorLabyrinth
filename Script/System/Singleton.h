/*****************************************************************************************************
-----ファイル概要-----
派生クラスが唯一であるためのクラス
2つ以上オブジェクトが生成されないようにするためのもの
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
	void operator=(const Singleton& obj){ }	//代入演算子禁止
	Singleton(const Singleton &obj){ }		//コピーコンストラクタ禁止

};

