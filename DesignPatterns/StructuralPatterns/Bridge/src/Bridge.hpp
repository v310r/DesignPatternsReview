#pragma once

#include <iostream>

struct Renderer
{
	virtual void render_circle(float x, float y, float radius) = 0;
};

struct VectorRenderer : Renderer
{
	virtual void render_circle(float x, float y, float radius) override
	{
		std::cout << "render vector circle";
	}
};

struct RasterRenderer : Renderer
{
	virtual void render_circle(float x, float y, float radius) override
	{
		std::cout << "render raster circle";
	}
};

struct Shape
{
	virtual void draw() = 0;

	virtual void resize(float factor) = 0;

protected:
	Renderer& m_renderer;

	Shape(Renderer& renderer) : m_renderer(renderer) {}
};

struct Circle : Shape
{
	Circle(Renderer& renderer, float x, float y, float radius)
		: Shape(renderer), m_x(x), m_y(y), m_radius(radius)
	{

	}

	virtual void draw() override
	{
		m_renderer.render_circle(m_x, m_y, m_radius);
	}

	virtual void resize(float factor) override
	{
		m_radius *= factor;
	}

	float m_x, m_y, m_radius;
};