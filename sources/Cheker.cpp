#include <algorithm>

#include "../headers/Cheker.h"

std::string Cheker::transform(std::string input)
{
    std::transform(input.begin(), input.end(), input.begin(), ::tolower);
    for (int i = 0; i < input.size(); i++)
    {
        char a = input[i];
        if (a <= 96 || a >= 122)
            if(a!= '\'')
                input[i] = ' ';
    }
    return input;
}
