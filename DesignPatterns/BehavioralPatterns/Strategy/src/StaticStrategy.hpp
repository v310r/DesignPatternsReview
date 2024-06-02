#pragma once

#include <sstream>
#include <vector>
#include <string>


template<typename LS>
struct TextProcessor2
{
    void AppendList(const std::vector<std::string>& items)
    {
        m_ListStrategy.Start(oss);
        for (auto& item : items)
        {
            m_ListStrategy.AddListItem(oss, item);
        }

        m_ListStrategy.End(oss);
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

    std::ostringstream oss;
    LS m_ListStrategy;
};