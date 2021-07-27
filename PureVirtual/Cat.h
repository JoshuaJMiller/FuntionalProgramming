#pragma once
#include "Animal.h"

class Cat :public Animal
{
public:
	Cat(const std::string& p_classification);
	virtual void speak() override;

protected:
private:
};

