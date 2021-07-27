#include "Cat.h"

#include <iostream>

Cat::Cat(const std::string& p_classification)
	: Animal(p_classification)
{
}


void Cat::speak()
{
	std::cout << "Meow" << std::endl;
}
