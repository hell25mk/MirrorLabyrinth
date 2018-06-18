#pragma once

#include "../Base/BaseObject.h"

class C_Road : public C_BaseObject{

public:
	C_Road(C_Position argPos);
	~C_Road();
	virtual void Draw() override;

};

