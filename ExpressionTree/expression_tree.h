
#pragma once

#include <string>

template<typename T>
class Expression
{
public:
    Expression();
    Expression(std::string&);

    void build_expression(std::string&);
    void simplify();

    virtual ~Expression()
    {
        delete result;
        delete left;
        delete right;
    }

private:
    T* result;
    Expression* left;
    Expression* right;
};
