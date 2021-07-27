#pragma once
#include "Animal.h"

class Dog : public Animal
{
public:
	Dog(const std::string& p_classification);
	virtual void speak() override;
};

