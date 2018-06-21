#pragma once

class C_Animation{

public:
	C_Animation(int animeOrder[],int orderSize,int animeChangeTime,int *imageNumber);
	~C_Animation();
	void Update();
	void Change();

private:
	int *animeOrder;
	int animeOrderSize;
	int animeChangeTime;
	int animeCount;
	int animeNumber;
	int *imageNumber;

};

