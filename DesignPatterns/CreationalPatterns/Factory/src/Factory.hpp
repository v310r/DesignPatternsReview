#pragma once

#include <cmath>

struct Point1
{
	float x, y;
	
	friend class PointFactory;

private:

	Point1(float x_, float y_) : x(x_), y(y_)
	{

	}
};

struct PointFactory
{
	static Point1 NewCartesian(float x, float y)
	{
		return Point1(x, y);
	}

	static Point1 NewPolar(float r, float theta)
	{
		return Point1(r * std::cos(theta), r * std::sin(theta));
	}
};