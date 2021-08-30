#include <iostream>

class Buggy
{
public:
	Buggy()
		: maxSize(1000), size(0)
	{
		auto lambda = [this]() {std::cout << "constructed instance of Buggy. Max size: " << maxSize << std::endl; };
		lambda();
	}

	Buggy(const Buggy& p_bug)
	{
		std::cout << "copy constructor called!" << std::endl;
		size = p_bug.size;
		maxSize = p_bug.size;
	}

	Buggy& operator=(const Buggy& p_bug)
	{
		std::cout << "non-default operator= called" << std::endl;
		if (p_bug.size <= this->maxSize)
		{
			this->size = p_bug.size + 1;
		}
		else
		{
			this->size = p_bug.size;
		}
		
		return *this;
	}

	void setSize(int p_size)
	{
		if (p_size <= maxSize)
		{
			size = p_size;
		}
		else
		{
			std::cerr << "size exceeds maxSize: " << maxSize << "!" << std::endl;
		}
	}
	int getSize()
	{
		return size;
	}
	void grow(int p_amount)
	{
		if (this->size + p_amount <= maxSize)
		{
			this->size += p_amount;
		}
		else
		{
			std::cerr << "size will exceed maxSize!" << std::endl;
		}
	}
private:
	int size;
	int maxSize;
protected:
};

int main()
{
	Buggy b1, b2, b3;
	b1.setSize(900);
	b2.setSize(9000);
	b3.setSize(10);

	[&]() {std::cout << b1.getSize() << "\n" << b2.getSize() << "\n" << b3.getSize() << std::endl; }();
	[&b2]() {b2.setSize(90);}();
	[&]() {std::cout << b2.getSize() << std::endl; }();

	Buggy b4 = b3;
	b2 = b3;
	b1.grow(100);
	b3 = b2;
	std::cout << b2.getSize();
	std::cout << b3.getSize();
	return 0;
}