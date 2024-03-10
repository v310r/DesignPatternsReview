#pragma once
#include <memory>
#include <string>


struct EmployeeFactory;

class Contact
{
public:
	Contact()
	{

	}

protected:

	std::string name;
	std::string address;

};

class NewEmployee : public Contact
{

protected:

	NewEmployee()
	{

	}

	NewEmployee(const std::string& name_, const int suite, const Contact& role)
	{

	}

	friend struct EmployeeFactory;
};

struct EmployeeFactory
{
	static Contact main;
	static Contact aux;

	static Contact* NewMainOfficeEmployee(const std::string& name_, const int suite)
	{
		return new NewEmployee(name_, suite, main);
	}

	static Contact* NewAuxOfficeEmployee(const std::string& name, int suite)
	{
		 return new NewEmployee(name, suite, aux);
	}
};

Contact EmployeeFactory::aux{};
Contact EmployeeFactory::main{};