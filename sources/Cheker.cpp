#include <algorithm>
#include <cxxabi.h>

#include "../headers/Cheker.h"

std::string Cheker::transform(std::string input)
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

const std::string Cheker::getNameClass() {
    return abi::__cxa_demangle(typeid(*this).name(),0,0,0);
}


