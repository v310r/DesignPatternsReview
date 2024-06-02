#pragma once

#include <sstream>


struct Expression
{
    virtual void print(std::ostringstream& oss) = 0;
};

struct DoubleExpression : Expression
{
   double value;

   virtual void print(std::ostringstream& oss)
   {
       oss << value;
   }

   explicit DoubleExpression(const double value)
        : value{ value } 
    {
       
    }
};

struct AdditionExpression : Expression
{
    Expression * left, * right;
  
    AdditionExpression(Expression* const left, Expression* const right)
        : left{ left }, right{ right }
    {

    }

    ~AdditionExpression()
    {
        delete left;
        delete right;
    }

    virtual void print(std::ostringstream& oss) override
    {
        oss << "(";
        left->print(oss);
        oss << "+";
        right->print(oss);
        oss << ")";
    }
};