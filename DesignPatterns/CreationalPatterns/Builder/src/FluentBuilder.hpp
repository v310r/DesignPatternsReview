#pragma once

#include <string>
#include <vector>
#include <memory>

struct HtmlBuilder;

struct HtmlElement
{
private:

	HtmlElement()
	{

	}

	HtmlElement(const std::string& name_, const std::string& text_)
		: name(name_), text(text_)
	{

	}

public:

	std::string str(const size_t indent = 0) const
	{
		// pretty-print the contents
		return "HtmlElement";
	}

	friend HtmlBuilder;

	std::string name;
	std::string text;
	std::vector<HtmlElement> elements;
};

struct HtmlBuilder
{
	HtmlBuilder(std::string rootName)
	{
		root.name = rootName;
	}

	HtmlBuilder& addChild(std::string childName, std::string childText)
	{
		HtmlElement e(childName, childText);
		root.elements.emplace_back(e);
		return *this;
	}

	static std::unique_ptr<HtmlBuilder> build(const std::string& rootName)
	{
		return std::make_unique<HtmlBuilder>(rootName);
	}

	operator HtmlElement() const
	{
		return root;
	}

	std::string str()
	{
		return root.str();
	}

	HtmlElement root;
};
