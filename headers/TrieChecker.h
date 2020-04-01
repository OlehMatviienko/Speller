#pragma once

#include <memory>
#include "Checker.h"
struct bnode
{
    bool is_word = false;
    struct std::shared_ptr<bnode> children[27]; // 26 letters of English alphabet + ' (apostrophe)
};

class TrieChecker : public Checker {
public:
    void add(std::vector<std::string> input) override;
    void find(std::string input) override;
    
    TrieChecker(): root(new bnode()){};
    static short int hash(const char letter);

private:
    std::shared_ptr<bnode> root;
};