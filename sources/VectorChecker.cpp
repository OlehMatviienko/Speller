#include <string>
#include<sstream>
#include <algorithm>


#include "VectorChecker.h"



void VectorChecker::find(std::string input) {
    input = transform(input);
    std::stringstream ss(input);
    std::string s;
    while (ss >> s) {
        AmountOfWords++;
        if (!std::binary_search(vectorV.begin(), vectorV.end(), s))
        {
            badwords++;
        }

    }
}
void VectorChecker::add(std::vector<std::string> input)
{
    vectorV = input;
};
