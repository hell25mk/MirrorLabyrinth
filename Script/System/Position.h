#pragma once

template <class Type> class C_Position{

public:
	Type x;
	Type y;

	//DrawŒnŠÖ”—p
	int dx;
	int dy;

public:
	C_Position(){}
	C_Position(Type x, Type y){

		this->x = x;
		this->y = y;
		dx = (int)x;
		dy = (int)y;

	}
	~C_Position(){}
	void SetPosition(Type x, Type y){

		this->x = x;
		this->y = y;
		dx = (int)x;
		dy = (int)y;

	}

};