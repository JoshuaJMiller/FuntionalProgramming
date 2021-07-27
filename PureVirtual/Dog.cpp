#include "Dog.h"

#include <iostream>

void Dog::speak()
{
	std::cout << "Woof" << std::endl;
}

Dog::Dog(const std::string& p_classification)
	: Animal(p_classification)
{
}
