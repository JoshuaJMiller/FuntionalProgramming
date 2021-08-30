#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <string>

bool isSizeEven(std::string& p_string)
{
	return p_string.size() % 2 == 0;
}

class IsStringSizeEven
{
public:
	bool operator()(const std::string& p_s)
	{
		return p_s.size() % 2 == 0;
	}
} test;

class Checker
{
public:
	Checker(const std::string& p_s, std::function<bool(const std::string&)> p_stringCheck)
		: stringCheck(p_stringCheck), m_string(p_s)
	{
		s = true;
	}
	Checker(const int& p_j, std::function<bool(const int&)> p_intCheck)
		: intCheck(p_intCheck), j(p_j)
	{
		i = true;
	}
	Checker(const double& p_dub, std::function<bool(const double&)> p_doubleCheck)
		: doubleCheck(p_doubleCheck), dub(p_dub)
	{
		d = true;
	}
	bool run()
	{
		if (s == true)
		{
			return stringCheck(m_string);
		}
		else if (i == true)
		{
			return intCheck(j);
		}
		else if (d == true)
		{
			return doubleCheck(dub);
		}
	}
private:
	bool s{ false };
	bool i{ false };
	bool d{ false };
	std::string m_string;
	int j;
	double dub;
	std::function<bool(const std::string&)> stringCheck;
	std::function<bool(const int&)> intCheck;
	std::function<bool(const double&)> doubleCheck;

};

int main()
{
	int even{ 0 };
	int odd{ 1 };
	std::vector<std::string> sVec{ "one", "two", "three", "four"};

	int count = std::count_if(sVec.begin(), sVec.end(), [even, odd](std::string s) { return s.size() % 2 == even; });

	std::cout << count << std::endl;

	count = std::count_if(sVec.begin(), sVec.end(), isSizeEven);

	std::cout << count << std::endl;

	count = std::count_if(sVec.begin(), sVec.end(), test);

	std::cout << count << std::endl;

	std::function<bool(std::string)> isStringSizeEven2 = [](std::string s) { return s.size() % 2 == 0; };

	count = std::count_if(sVec.begin(), sVec.end(), isStringSizeEven2);

	std::cout << count << std::endl;

	Checker c1("Sandwich", [](std::string s) { return s.size() % 2 != 0; });
	Checker c2("chuckle", test);
	Checker c3(2, [](const int& i) { return i % 2 == 0; });

	std::cout << c1.run() << std::endl;
	std::cout << c2.run() << std::endl;
	std::cout << c3.run() << std::endl;

	std::cout << std::boolalpha << isStringSizeEven2("grubby");

	return 0;
}