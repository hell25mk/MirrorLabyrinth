#pragma once

#include "../Base/BaseObject.h"

class C_Stairs : public C_BaseObject{

public:
	C_Stairs(C_Position argPos);
	virtual ~C_Stairs();
	virtual void Draw() override;

};

