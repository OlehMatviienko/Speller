#include <string>
#include<sstream>
#include <algorithm>


#include "../headers/vectorCheker.h"



void vectorCheker::find(std::string input) {
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
void vectorCheker::add(std::string input)
{
    vectorV.push_back(input);
};
