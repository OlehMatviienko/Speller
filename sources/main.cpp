#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <memory>
#include <random>
#include <algorithm>
#include <typeinfo>

#include "../headers/HashTable.h"
#include "../headers/BTrie.h"
#include "../headers/vectorCheker.h"
#include "../headers/BTSCheker.h"

template <typename input>
void LoadDictionary(input const &a);

template <typename input>
void CheckTexts(input const &a);



int main() {
    std::vector<std::shared_ptr<Cheker>> Chekers;
    Chekers.push_back(std::make_shared<MyHashTable>());
    Chekers.push_back(std::make_shared<BTrie>());
    Chekers.push_back(std::make_shared<vectorCheker>());
    Chekers.push_back(std::make_shared<BTS>());

    for(const auto& a: Chekers){
        LoadDictionary(a);
        CheckTexts(a);
    }


}

template <typename input>
void LoadDictionary(input const &a){
    std::string s = "";
    std::ifstream file("../texts/Dictionary.txt");
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