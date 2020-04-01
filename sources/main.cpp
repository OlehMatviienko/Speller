#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <memory>

#include "HashTableChecker.h"
#include "TrieChecker.h"
#include "VectorChecker.h"
#include "BinTreeChecker.h"

template <typename input>
void LoadDictionary(input const &a);

template <typename input>
void CheckTexts(input const &a);



int main() {
    std::vector<std::shared_ptr<Checker>> Chekers;
    Chekers.push_back(std::make_shared<MyHashTable>());
    Chekers.push_back(std::make_shared<TrieChecker>());
    Chekers.push_back(std::make_shared<VectorChecker>());
    Chekers.push_back(std::make_shared<BTS>());

    for(const auto& a: Chekers){
        LoadDictionary(a);
        CheckTexts(a);
    }


}

template <typename input>
void LoadDictionary(input const &a){
    std::string s = "";
    std::ifstream file("../include/texts/Dictionary.txt");
    std::vector<std::string> DictionaryVector;
    auto start = std::chrono::high_resolution_clock::now();
    while (getline(file, s)) {
        DictionaryVector.push_back(s);

    }
    a->add(DictionaryVector);
    auto stop = std::chrono::high_resolution_clock::now();
    a->LoadTime = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();
    file.close();
}

template <typename input>
void CheckTexts(input const &a) {
    std::ifstream text;
    std::string s = "";
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < a->texts.size(); i++) {
        text.open(a->texts[i]);
        while (getline(text, s))
        {
            a->find(s);
        }
        text.close();
    }
    auto stop = std::chrono::high_resolution_clock::now();
    a->CheckTime = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();
    std::cout << a->getNameClass()<< " " << a->LoadTime << " " << a->CheckTime<< " " << a->AmountOfWords << " "<< a->badwords << std::endl;
}