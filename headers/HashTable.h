#pragma once
#include<string>
#include <vector>
#include <list>
#include "Cheker.h"
class MyHashTable : public Cheker {
public:
    MyHashTable();
    std::vector<std::list<std::string>> HashTable;
    int size = 15000;
    unsigned long int hash(std::string input);
    void add(std::string input) override;
    void find(std::string input) override;
    int badwords = 0;
    int AmountOfWords = 0;
};