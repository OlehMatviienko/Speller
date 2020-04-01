#pragma once
#include <string>
#include <memory>
#include "Checker.h"

struct node //node of BinTree
{
    std::string data;
    std::shared_ptr<node> left;
    std::shared_ptr<node> right;
};

class BTS : public Checker {
public:
    void add(std::vector<std::string> input) override;
    void find(std::string input) override;

    std::shared_ptr<node> root;
    std::shared_ptr<node> CreateNode(std::string data);
};