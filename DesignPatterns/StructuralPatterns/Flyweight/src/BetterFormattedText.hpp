#pragma once

#include <vector>
#include <xstring>
#include <locale>


class BetterFormattedText
{
public:
    BetterFormattedText(const std::string inString) : plainText(inString)
    {
        
    }

    struct TextRange
    {
        int start, end;
        bool capitalize;

        // other options, e.g. bold, italic, etc.

        bool covers(int position) const
        {
            return position >= start && position <= end;
        }
    };

    TextRange & get_range(int start, int end)
    {
        formatting.emplace_back(TextRange{ start, end });
        return *formatting.rbegin();
    }

friend std::ostream & operator<<(std::ostream & os, const BetterFormattedText& obj)
 {
    std::string s;

    for (size_t i = 0; i < obj.plainText.length(); i++)
    {
        auto c = obj.plainText[i];
        for (const auto& rng : obj.formatting)
        {
            if (rng.covers(i) && rng.capitalize)
            {
                c = std::toupper(c);
            }
            s += c;
        }
    }

    return os << s;
}

private:
    std::string plainText;

    std::vector<TextRange> formatting;
};
