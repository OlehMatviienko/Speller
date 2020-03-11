

#include <sstream>

#include "../headers/HashTable.h"

void MyHashTable::add(std::string input) {
    int index = hash(input);
    HashTable[index].push_back(input);

}

MyHashTable::MyHashTable() {
    HashTable.resize(size);
}

unsigned long int MyHashTable::hash(std::string input) {
    //djb2 Algorithm
    unsigned long int hash;
    int c;

    hash = 5381;
    for (auto x : input)
    {
        c = x;
        hash = ((hash << 5) + hash) + c;
    }
    return (hash % this->size);
}

void MyHashTable::find(std::string input)
{
    input = transform(input);
    bool found = false;
    std::stringstream ss(input);
    std::string s;
    while (ss >> s) {
        AmountOfWords++;
        found = false;
        int k = hash(s);
        for (auto x : HashTable[k])
        {
            if (x.compare(s)==0){
                found = true;
                break;
            }
        }
        if (found == false) {
            badwords++;
        }
    }

}