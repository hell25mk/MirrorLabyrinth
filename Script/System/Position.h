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

/*template <class Type> class C_Position{

public:
	Type x;
	Type y;

	//DrawŒnŠÖ”—p•Ï”
	int dx;
	int dy;

public:
	C_Position(){ }
	~C_Position(){ }
	void SetPosition(Type x, Type y){

		this->x = x;
		this->y = y;
		dx = (int)x;
		dy = (int)y;

	}

};*/