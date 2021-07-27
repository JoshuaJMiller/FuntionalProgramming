#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void sayHello()
{
	std::cout << "Hello" << std::endl;
}

void sayGoodbye()
{
	std::cout << "Goodbye" << std::endl;
}

int addInts(int a, int b)
{
	return a + b;
}

double subDoubles(double a, double b)
{
	return a - b;
}

bool match(std::string p_string)
{
	return p_string.size() == 3;
}

int count_strings(std::vector<std::string> p_strings, bool (*match)(std::string p_string))
{
	int count{ 0 };
	for (auto i : p_strings)
	{
		if (match(i)) count++;
	}
	return count;
}

int main()
{
	sayHello();

	std::cout << "-------- using function pointer --------" << std::endl;

	void(*test)() = sayHello;

	test();

	test = sayGoodbye;

	test();

	int(*test2)(int, int) = addInts;

	std::cout << test2(1, 2) << std::endl;

	double(*test3)(double, double) = subDoubles;

	std::cout << test3(2.2, 1.1) << std::endl;

	std::cout << "-------- count_if --------" << std::endl;

	std::vector<std::string> strings{ "one", "two", "three", "four", "five", "six" };

	std::cout << std::count_if(strings.begin(), strings.end(), match) << std::endl;

	std::cout << "-------- count_strings --------" << std::endl;

	std::cout << count_strings(strings, match) << std::endl;

	return 0;
}