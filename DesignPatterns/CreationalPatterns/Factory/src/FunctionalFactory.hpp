#pragma once
#include <map>
#include <functional>
#include <string>
#include <memory>


struct HotDrink
{
	virtual void prepare(int volume) = 0;
};

struct Tea : HotDrink
{
	void prepare(int volume) override
	{
		std::cout << "Take tea bag, boil water, pour " << volume <<
			"ml, add some lemon" << std::endl;
	}
};

struct Coffee : HotDrink
{
	void prepare(int volume) override
	{
		std::cout << "Take coffee bag, boil water, pour " << volume <<
			"ml, add some sugar" << std::endl;
	}
};


struct HotDrinkFactory
{
	virtual std::unique_ptr<HotDrink> make() const = 0;
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

class DrinkWithVolumeFactory
{
	std::map<std::string, std::function<std::unique_ptr<HotDrink>()>> factories;

public:

	DrinkWithVolumeFactory()
	{
		factories["tea"] = []
		{
			auto tea = std::make_unique<Tea>();
			tea->prepare(200);
			return tea;
		};
		factories["coffee"] = []
		{
			auto tea = std::make_unique<Coffee>();
			tea->prepare(200);
			return tea;
		};
	}

	std::unique_ptr<HotDrink> makeDrink(const std::string& name)
	{
		return factories[name]();
	}
};