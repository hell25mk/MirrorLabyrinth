#pragma once

#include "BaseObject.h"

class C_Animation;

class C_BaseCharacter : public C_BaseObject{

public:
	C_BaseCharacter();
	C_BaseCharacter(C_Position<int> argPos);
	virtual ~C_BaseCharacter();
	virtual void Update() = 0;
	virtual void Draw() = 0;

protected:
	static const int Image_Size;
	static const int Image_Width;
	static const int Image_Height;
	static const int AnimeChange_Time;
	/*typedef enum{
		Dire_Up,
		Dire_Down,
		Dire_Left,
		Dire_Right,

		Dire_Nore,
	}e_Direction;*/

	static int *image;
	int dire;
	int imageNumber;
	C_Animation *animation;

};

