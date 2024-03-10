#include "PimplIdiom.h"
#include <string>
#include <iostream>

struct PersonImpl
{
	void greet()
	{
		std::cout << "Hello, " << name << "!";
	}

private:
	std::string name;
};

Person::Person() : impl(new PersonImpl)
{

}

void Person::greet()
{
	impl->greet();
}
