#pragma once

#include <vector>
#include "KeyAndVector.h"

class UpdateableObject
{
protected:
	std::vector<KeyAndVector> vectorList;
public:
	virtual void update() = 0;
	void addKeyAndStore(KeyAndVector key);
};

