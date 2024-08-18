#pragma once
#include "MoveBehavior.h"
class SmartMove : public MoveBehavior
{
public:
	SmartMove() = default;
	~SmartMove() = default;
	virtual void moveObject(MovingObject&) override;
private:

};

