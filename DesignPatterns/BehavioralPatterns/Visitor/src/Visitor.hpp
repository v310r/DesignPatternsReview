#pragma once

#include <sstream>


struct ExpressionVisitor;
struct Expression3;
struct DoubleExpression3;
struct AdditionExpression3;

struct Expression3
{
    virtual void accept(ExpressionVisitor* visitor) = 0;
};

struct ExpressionVisitor
{
    virtual void visit(DoubleExpression3* de) = 0;

    virtual void visit(AdditionExpression3* ae) = 0;
};

struct DoubleExpression3 : Expression3
{
    double value;

    explicit DoubleExpression3(const double value)
        : value{ value }
    {

    }

    virtual void accept(ExpressionVisitor* visitor) override
    {
        visitor->visit(this);
    }
};

struct AdditionExpression3 : Expression3
{
    Expression3* left, * right;

    AdditionExpression3(Expression3* const left, Expression3* const right)
        : left{ left }, right{ right }
    {

    }

    ~AdditionExpression3()
    {
        delete left;
        delete right;
    }

    virtual void accept(ExpressionVisitor* visitor) override
    {
        visitor->visit(this);
    }
};

struct ExpressionPrinter3 : ExpressionVisitor
{
    std::ostringstream oss;

    std::string str() const
    {
        return oss.str();
    }

    virtual void visit(DoubleExpression3* de) override
    {
        oss << de->value;
    }

    virtual void visit(AdditionExpression3* ae) override
    {
        oss << "(";

        ae->left->accept(this);

        oss << "+";
        ae->right->accept(this);

        oss << ")";
    }
};

struct ExpressionEvaluator : ExpressionVisitor
{
    double result;

    virtual void visit(DoubleExpression3* de) override
    {
        result = de->value;
    }

    virtual void visit(AdditionExpression3* ae) override
    {
        ae->left->accept(this);
        auto temp = result;
        ae->right->accept(this);
        result += temp;
    }
};
