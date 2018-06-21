#pragma once

#include "BaseObject.h"

class C_BaseCharacter : public C_BaseObject{

public:
	C_BaseCharacter(C_Position argPos);
	virtual ~C_BaseCharacter();
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Animation(){ }

protected:
	static const int Image_Size;
	static const int Image_X_Num;
	static const int Image_Y_Num;
	static const int AnimeChange_Time;

	static int *image;
	int animeTime;
	int animeImage;
	bool animeChangeFlag;

};

