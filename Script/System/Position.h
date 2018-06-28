#pragma once

template <class Type> class C_Position{

public:
	C_Position(){

		x = 0;
		y = 0;
		dx = 0;
		dy = 0;
	
	}
	C_Position(Type x, Type y){

		this->x = x;
		this->y = y;
		dx = (int)x;
		dy = (int)y;

	}
	~C_Position(){}
	//setter
	void SetPosition(Type x, Type y){

		this->x = x;
		this->y = y;
		dx = (int)x;
		dy = (int)y;

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
	Type GetDx(){

		dx = (int)x;

		return dx;
	}
	Type GetDy(){

		dy = (int)y;

		return dy;
	}

private:
	Type x;
	Type y;
	//DrawŒnŠÖ”—p
	int dx;
	int dy;

};