#pragma once

#include <sstream>


struct Expression2
{
    virtual ~Expression2() = default;
};

struct DoubleExpression2 : Expression2
{
    double value;

    explicit DoubleExpression2(const double value)
        : value{ value }
    {

    }
};

struct AdditionExpression2 : Expression2
{
    Expression2* left, * right;

    AdditionExpression2(Expression2* const left, Expression2* const right)
        : left{ left }, right{ right }
    {

    }

    ~AdditionExpression2()
    {
        delete left;
        delete right;
    }
};

struct ExpressionPrinter
{
    void print(Expression2* e)
    {
        if (auto de = dynamic_cast<DoubleExpression2*>(e))
        {
            oss << de->value;
        }

        if (auto ae = dynamic_cast<AdditionExpression2*>(e))
        {
            oss << "(";
            print(ae->left);
            oss << "+";
            print(ae->right);
            oss << ")";
        }
    }

    std::string str() const
    {
        return oss.str();
    }

private:
    std::ostringstream oss;
};