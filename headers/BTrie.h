#pragma once
#include "Cheker.h"
struct bnode
{
    bool is_word = false;
    struct bnode* children[27];
};

class BTrie : public Cheker {
public:
    BTrie():  root(new bnode()){};
    static short int hash(const char letter);
    void add(std::vector<std::string> input) override;
    void find(std::string input) override;
    bnode* root;
};