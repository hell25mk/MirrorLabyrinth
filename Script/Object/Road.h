#pragma once

#include "../Base/BaseBlock.h"

class C_Road : public C_BaseBlock{

public:
	C_Road(C_Position argPos);
	~C_Road();
	virtual void Update() override;
	virtual void Draw() override;

};

