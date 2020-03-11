#pragma once
#include <vector>

#include "Cheker.h"


class vectorCheker : public Cheker{
public:
    std::vector<std::string> vectorV;
    void find(std::string input) override;
    void add(std::string input) override;
    int badwords = 0;
    int AmountOfWords = 0;
};