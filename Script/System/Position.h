#pragma once

class C_Position{

public:
	C_Position();
	C_Position(int x,int y);
	~C_Position();

public:
	int x;
	int y;

};

//çlÇ¶íÜ
/*template <class Type> class C_TPosition{

public:
	C_TPosition(){}
	C_TPosition(Type x, Type y){
		this->x = x;
		this->y = y;
	}
	~C_TPosition(){ }

public:
	Type x;
	Type y;

};*/