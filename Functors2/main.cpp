#include <iostream>
#include <string>

struct Test
{
	virtual bool operator()(std::string p_barry) = 0;
};

struct barryMatch : public Test
{
	virtual bool operator()(std::string p_barry) override
	{
		return p_barry == "Barry";
	}
};

void test(std::string p_toTest, Test& p_check)
{
	if (p_check(p_toTest))
	{
		std::cout << p_toTest << " matches \"Barry\"" << std::endl;
	}
	else
	{
		std::cout << "Does not match!" << std::endl;
	}
}

int main()
{
	std::cout << std::boolalpha;
	barryMatch barry;
	std::cout << barry("Barry") << std::endl;
	test("Barry", barry);
	test("Barryy", barry);
	return 0;
}