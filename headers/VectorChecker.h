#pragma once
#include <vector>

#include "Checker.h"


class VectorChecker : public Checker{
public:
    void find(std::string input) override;
    void add(std::vector<std::string> input) override;

private:
    std::vector<std::string> vectorV;
};