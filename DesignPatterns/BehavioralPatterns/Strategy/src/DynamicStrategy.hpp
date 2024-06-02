#pragma once

#include <sstream>
#include <vector>
#include <string>


enum class OutputFormat
{
    Markdown,
    Html
};

struct ListStrategy
{
    virtual void Start(std::ostringstream& oss)
    {

    }

    virtual void End(std::ostringstream& oss)
    {

    }

    virtual void AddListItem(std::ostringstream& oss, const std::string& item)
    {

    }
};

struct HtmlListStrategy : ListStrategy
{
    virtual void Start(std::ostringstream& oss) override
    {
        oss << "<ul>\n";
    }

    virtual void End(std::ostringstream& oss) override
    {
        oss << "</ul>\n";
    }

    virtual void AddListItem(std::ostringstream& oss, const std::string& item) override
    {
        oss << "<li>" << item << "</li>\n";
    }
};

struct MarkdownListStrategy : ListStrategy
{
    virtual void AddListItem(std::ostringstream& oss, const std::string& item) override
    {
        oss << " * " << item << "\n";
    }
};

struct TextProcessor
{
    void AppendList(const std::vector<std::string>& items)
    {
        m_ListStrategy->Start(oss);
        for (auto& item : items)
        {
            m_ListStrategy->AddListItem(oss, item);
        }

        m_ListStrategy->End(oss);
    }

    void SetOutputFormat(OutputFormat of)
    {
        switch (of)
        {
            case OutputFormat::Html:
            {
                m_ListStrategy = std::make_unique<HtmlListStrategy>();
                break;
            }
            case OutputFormat::Markdown:
            {
                m_ListStrategy = std::make_unique<MarkdownListStrategy>();
                break;
            }
        }
    }

    std::string Str() const
    {
        return oss.str();
    }

    void Clear()
    {
        oss.str("");
        oss.clear();
    }

private:
    std::ostringstream oss;
    std::unique_ptr<ListStrategy> m_ListStrategy;
};