#pragma once
#include <vector>

#include "Cheker.h"


class vectorCheker : public Cheker{
public:
    std::vector<std::string> vectorV;
    void find(std::string input) override;
    void add(std::vector<std::string> input) override;
};