/*****************************************************************************************************
-----ファイル概要-----
派生クラスが唯一であるためのクラス
2つ以上オブジェクトが生成されないようにするためのもの
******************************************************************************************************/

#pragma once

template <class Type> class Singleton{

public:
	/// <summary>
	/// インスタンスを取得する
	/// </summary>
	/// <returns>作成した[Type]クラス</returns>
	static Type& GetInstance(){

		static Type instance;

		return instance;
	}
	/// <summary>
	/// 初期化処理を行う
	/// </summary>
	virtual void Create(){ }
	/// <summary>
	///	終了処理を行う
	/// </summary>
	virtual void Destroy(){ }

protected:
	//勝手に生成できないようにprotected修飾子にしている
	Singleton(){ }
	virtual ~Singleton(){ }

private:
	void operator=(const Singleton& obj){ }		//代入演算子を禁止する
	Singleton(const Singleton &obj){ }			//コピーメンバを初期化するを禁止する

};

