#pragma once
#include <string>
#include <vector>
#include <utility>


struct Tag
{
protected:

	Tag(const std::string& name, const std::string& text)
	{
		this->name = name;
		this->text = text;
	}

	Tag(const std::string& name, const std::vector<Tag>& children)
	{
		this->name = name;
		this->children = children;
	}

public:

	friend std::ostream& operator<<(std::ostream& os, const Tag& tag)
	{
		os << "Tag(s)";
		return os;
	}

	std::vector<std::pair<std::string, std::string>> attributes;
	std::vector<Tag> children;
	std::string text;
	std::string name;
};

struct P : Tag
{
	explicit P(const std::string& text) : Tag("p", text) 
	{

	}

	P(std::initializer_list<Tag> children) : Tag("p", children)
	{

	}
};

struct IMG : Tag
{
	explicit IMG(const std::string& url) : Tag("img", "")
	{
		attributes.emplace_back("src", url);
	}
};
