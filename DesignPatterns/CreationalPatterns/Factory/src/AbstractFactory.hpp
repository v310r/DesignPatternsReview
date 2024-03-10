#pragma once
#include <iostream>
#include <memory>
#include <string>
#include <map>


struct HotDrink
{
	virtual void prepare(int volume) = 0;
};

struct Tea : HotDrink
{
	virtual void prepare(int volume) override
	{
		std::cout << "Take tea bag, boil water, pour " << volume <<
			"ml, add some lemon" << std::endl;
	}
};

struct Coffee : HotDrink
{
	virtual void prepare(int volume) override
	{
		std::cout << "Take coffee bag, boil water, pour " << volume <<
			"ml, add some sugar" << std::endl;
	}
};

std::unique_ptr<HotDrink> makeDrink(std::string type)
{
	std::unique_ptr<HotDrink> drink;
	if (type == "tea")
	{
		drink = std::make_unique<Tea>();
		drink->prepare(200);
	}
	else
	{
		drink = std::make_unique<Coffee>();
		drink->prepare(200);
	}
	return drink;
}

struct HotDrinkFactory
{
	virtual virtual std::unique_ptr<HotDrink> make() const = 0;
};

struct CoffeeFactory : HotDrinkFactory
{
	std::unique_ptr<HotDrink> make() const override
	{
		return std::make_unique<Coffee>();
	}
};

struct TeaFactory : HotDrinkFactory
{
	std::unique_ptr<HotDrink> make() const override
	{
		return std::make_unique<Tea>();
	}
};

class DrinkFactory
{
	std::map<std::string, std::unique_ptr<HotDrinkFactory>> hotFactories;

public:

	DrinkFactory()
	{
		hotFactories["coffee"] = std::make_unique<CoffeeFactory>();
		hotFactories["tea"] = std::make_unique<TeaFactory>();
	}

	std::unique_ptr<HotDrink> makeDrink(const std::string& name)
	{
		auto drink = hotFactories[name]->make();
		drink->prepare(200);
		return drink;
	}
};