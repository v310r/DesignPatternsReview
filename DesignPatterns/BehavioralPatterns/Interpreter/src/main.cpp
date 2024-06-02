
#include <iostream>

#include "Lexing.hpp"


int main()
{
    std::string input{ "(13-4)-(12+1)" };
    auto tokens = lex(input);
    auto parsed = parse(tokens);
    std::cout << input << " = " << parsed->eval() << std::endl;
    // prints "(13-4)-(12+1) = -4"
}

