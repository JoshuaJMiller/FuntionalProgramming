//no idea why pure vitual classes are a part of this section

#include <iostream>
#include <memory>
#include <vector>

#include "Dog.h"
#include "Cat.h"

int main()
{
	Dog dog1("Mammal");
	dog1.speak();
	Cat cat1("Mammal");
	cat1.speak();

	auto dog1Ptr = std::make_unique<Dog>("M");
	auto cat1Ptr = std::make_unique<Cat>("M2");

	dog1Ptr->speak();
	cat1Ptr->speak();

	std::vector<std::unique_ptr<Animal>> animals;

	animals.push_back(std::move(dog1Ptr));
	animals.push_back(std::move(cat1Ptr));

	//dog1Ptr and cat1Ptr are nullptr

	for (size_t i{ 0 }; i < animals.size(); ++i)
	{
		animals.at(i)->speak();
	}

	for (const auto& i : animals)
	{
		i->speak();
	}

	return 0;
}