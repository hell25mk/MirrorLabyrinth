#pragma once

#include "../Base/BaseObject.h"

class C_Wall : public C_BaseObject{

public:
	C_Wall(C_Position argPos);
	virtual ~C_Wall();
	virtual void Draw() override;

};

