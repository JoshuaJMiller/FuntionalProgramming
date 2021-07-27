#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int Count_If(std::vector<std::string>::iterator p_begin, std::vector<std::string>::iterator p_end, bool (*pFunc)(std::string s))
{
	int count{0};
	while (p_begin != p_end)
	{
		if (pFunc(*p_begin))
		{
			count++;
		}
		p_begin++;
	}
	return count;
}

int main()
{
	std::vector<std::string> names{ "Barry", "Larry", "Henry", "barry", "BARRY", "Bernie", "Bernie", "BeRnIe", "BERNIE"};

	std::cout << std::count_if(names.begin(), names.end(), [](std::string s) {return s == "Barry"; }) << std::endl;

	auto isAnyBernie = [](std::string s) {std::for_each(s.begin(), s.end(), [](char& c) {c = std::tolower(c); }); return s == "bernie"; };

	std::cout << Count_If(names.begin(), names.end(), isAnyBernie) << std::endl;

	return 0;
}