#pragma once
#include<string>
#include <vector>
#include <list>
#include "Checker.h"
class MyHashTable : public Checker {
public:
    MyHashTable();

    void add(std::vector<std::string> input) override;
    void find(std::string input) override;

    std::vector<std::list<std::string>> HashTable;
    int size = 15000; // size of std::vector in HashTable
    unsigned int hash(std::string input); // dbj2 hash function
};