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
	void operator=(const C_Singleton& obj){ }	//代入演算子禁止
	C_Singleton(const C_Singleton &obj){ }		//コピーコンストラクタ禁止

};

