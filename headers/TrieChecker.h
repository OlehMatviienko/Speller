#pragma once

#include <memory>
#include "Checker.h"
struct bnode
{
    bool is_word = false;
    struct std::shared_ptr<bnode> children[27];
};

class TrieChecker : public Checker {
public:
    TrieChecker(): root(new bnode()){};
    static short int hash(const char letter);
    void add(std::vector<std::string> input) override;
    void find(std::string input) override;
private:
    std::shared_ptr<bnode> root;
};