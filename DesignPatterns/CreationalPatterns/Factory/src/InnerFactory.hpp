#pragma once

#include <cmath>

struct Point2
{
private:

	Point2(float x_, float y_) : x(x_), y(y_)
	{

	}

	struct Point2Factory
	{
	private:
		Point2Factory(){}

	public:

		static Point2 NewCartesian(float x, float y)
		{
			return { x, y };
		}

		static Point2 NewPolar(float r, float theta)
		{
			return { r * std::cos(theta), r * std::sin(theta) };
		}
	};

public:

	float x, y;

	static Point2Factory Factory;
};