#pragma once
#include <string>

class PersonAddressBuilder;
class PersonJobBuilder;


class Person
{
public:

	Person() {}

	// address
	std::string streetAddress, postcode, city;

	// employment
	std::string companyName, position;

	size_t annualIncome;
};

class PersonBuilderBase
{

protected:
	Person& person;

	explicit PersonBuilderBase(Person& person_) : person(person_)
	{

	}

public:

	operator Person()
	{
		return std::move(person);
	}

	PersonAddressBuilder lives() const;

	PersonJobBuilder works() const;
};

class PersonAddressBuilder : public PersonBuilderBase
{
	typedef PersonAddressBuilder self;

public:

	explicit PersonAddressBuilder(Person& person)
		: PersonBuilderBase(person)
	{

	}

	self& at(const std::string& streetAddress)
	{
		person.streetAddress = streetAddress;
		return *this;
	}

	self& withPostcode(const std::string& postcode)
	{
		person.postcode = postcode;
		return *this;
	}

	self& in(const std::string& city)
	{
		person.city = city;
		return *this;
	}
};

class PersonJobBuilder : public PersonBuilderBase
{
	typedef PersonJobBuilder self;

public:

	explicit PersonJobBuilder(Person& person)
		: PersonBuilderBase(person)
	{

	}

	self& at(const std::string& companyName)
	{
		person.companyName = companyName;
		return *this;
	}

	self& asA(const std::string& position)
	{
		person.position = position;
		return *this;
	}

	self& earning(const size_t annualIncome)
	{
		person.annualIncome = annualIncome;
		return *this;
	}
};

class PersonBuilder : public PersonBuilderBase
{
public:

	PersonBuilder() : PersonBuilderBase(p)
	{

	}

	static PersonBuilder create()
	{
		return PersonBuilder();
	}

private:

	Person p;
};

PersonAddressBuilder PersonBuilderBase::lives() const
{
	return PersonAddressBuilder(person);
}

PersonJobBuilder PersonBuilderBase::works() const
{
	return PersonJobBuilder(person);
}
