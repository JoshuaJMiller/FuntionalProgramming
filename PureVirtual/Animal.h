#pragma once
#include <string>


class Animal
{
public:
	Animal(const std::string& p_classification);
	virtual void speak() = 0;
protected:
	std::string classification;
};

