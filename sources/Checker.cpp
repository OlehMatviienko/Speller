#include <algorithm>
#include <cxxabi.h>

#include "Checker.h"

std::string Checker::transform(std::string input)
{
    std::transform(input.begin(), input.end(), input.begin(), ::tolower);
    for (char & i : input)
    {
        char a = i;
        if (a <= 96 || a >= 122)
            if(a!= '\'')
                i = ' ';
    }
    return input;
}

const std::string Checker::getNameClass() {
    return abi::__cxa_demangle(typeid(*this).name(),0,0,0);
}


