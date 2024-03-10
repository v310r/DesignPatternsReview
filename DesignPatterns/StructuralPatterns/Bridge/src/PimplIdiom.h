#pragma once

struct Person
{
	Person();

	~Person();

	void greet();

private:
	class PersonImpl* impl;
};

