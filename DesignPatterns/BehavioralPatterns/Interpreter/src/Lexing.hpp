#pragma once

#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <sstream>


// The process of "parsing" turns a sequence of "tokens" into meaningful,
// typically object - oriented, structures

struct Element
{
    virtual int eval() const = 0;
};


struct Integer : public Element
{
    explicit Integer(int value)
        : value(value)
    {

    }

    virtual int eval() const override
    {
        return value;
    }

    int value;
};

struct BinaryOperation : public Element
{
    enum EType
    {
        addition,
        subtraction
    };

    virtual int eval() const override
    {
        if (type == addition)
        {
            return lhs->eval() + rhs->eval();
        }

        return lhs->eval() - rhs->eval();
    }

    EType type;

    std::shared_ptr<Element> lhs, rhs;
};


struct Token
{
    enum EType
    {
        integer,
        plus, 
        minus,
        lparen,
        rparen
    };

    explicit Token(EType type, const std::string& text)
        : type(type), text(text)
    {

    }

    friend std::ostream& operator<<(std::ostream& os, const Token& obj)
    {
        return os << " " << obj.text << " ";
    }

    EType type;

    std::string text;
};

std::vector<Token> lex(const std::string& input)
{
    std::vector<Token> result;
    for (int i = 0; i < input.size(); ++i)
    {
        switch (input[i])
        {
            case '+':
            {
                result.emplace_back(Token{Token::plus, "+"});
                break;
            }
            case '-':
            {
                result.emplace_back(Token{ Token::minus, "-" });
                break;
            }
            case '(':
            {
                result.push_back(Token{ Token::lparen, "(" });
                break;
            }
            case ')':
            {
                result.emplace_back(Token{ Token::rparen, ")" });
                break;
            }
            default:
            {
                std::ostringstream buffer;
                buffer << input[i];
                for (int j = i + 1; j < input.size(); ++j)
                {
                    if (std::isdigit(input[j]))
                    {
                        buffer << input[j];
                        ++i;
                    }
                    else
                    {
                        result.emplace_back(Token{ Token::integer, buffer.str() });
                        break;
                    }
                }
            }
        }
    }

    return result;
}

std::shared_ptr<Element> parse(const std::vector<Token>& tokens)
{
    auto result = std::make_unique<BinaryOperation>();
    bool bHaveLhs = false;
    for (size_t i = 0; i < tokens.size(); ++i)
    {
        const Token& token = tokens[i];
        switch (token.type)
        {
            // process each of the tokens in turn
            case Token::integer:
            {
                int value = std::atoi(token.text.data());
                auto integer = std::make_shared<Integer>(value);
                if (!bHaveLhs)
                {
                    result->lhs = integer;
                    bHaveLhs = true;
                }
                else
                {
                    result->rhs = integer;
                }
                break;
            }
            case Token::plus:
            {
                result->type = BinaryOperation::addition;
                break;
            }
            case Token::minus:
            {
                result->type = BinaryOperation::subtraction;
                break;
            }
            case Token::lparen:
            {
                int j = i;
                for (; j < tokens.size(); ++j)
                {
                    if (tokens[j].type == Token::rparen)
                    {
                        break;
                    }
                }

                std::vector<Token> subexpression(&tokens[i + 1], &tokens[j]);
                std::shared_ptr<Element> element = parse(subexpression);
                if (!bHaveLhs)
                {
                    result->lhs = element;
                    bHaveLhs = true;
                }
                else
                {
                    result->rhs = element;
                }

                i = j;
            }
        }
    }

    return result;
}
