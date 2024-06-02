#pragma once

#include <sstream>


template <typename Visitable>
struct Visitor
{
    virtual void visit(Visitable& obj) = 0;
};

struct VisitorBase // marker interface
{
    virtual ~VisitorBase() = default;
};

struct Expression4
{
    virtual ~Expression4() = default;

    virtual void accept(VisitorBase& obj)
    {
        using EV = Visitor<Expression4>;
        if (auto ev = dynamic_cast<EV*>(&obj))
        {
            ev->visit(*this);
        }
    }
};

struct DoubleExpression4 : Expression4
{
    double value;

    explicit DoubleExpression4(const double value)
        : value{ value }
    {

    }

    virtual void accept(VisitorBase& obj) override
    {
        using EV = Visitor<DoubleExpression4>;
        if (auto ev = dynamic_cast<EV*>(&obj))
        {
            ev->visit(*this);
        }
    }
};

struct AdditionExpression4 : Expression4
{
    Expression4* left, * right;

    AdditionExpression4(Expression4* const left, Expression4* const right)
        : left{ left }, right{ right }
    {

    }

    ~AdditionExpression4()
    {
        delete left;
        delete right;
    }

    virtual void accept(VisitorBase& obj) override
    {
        using EV = Visitor<AdditionExpression4>;
        if (auto ev = dynamic_cast<EV*>(&obj))
        {
            ev->visit(*this);
        }
    }
};

struct ExpressionPrinter4 : VisitorBase, Visitor<DoubleExpression4>, Visitor<AdditionExpression4>
{
    virtual void visit(DoubleExpression4& obj) override;

    virtual void visit(AdditionExpression4& obj) override;

    std::string str() const
    {
        return oss.str();
    }

private:
    std::ostringstream oss;
};