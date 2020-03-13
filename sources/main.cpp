#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <memory>
#include <random>
#include <algorithm>

#include "../headers/HashTable.h"
#include "../headers/BTrie.h"
#include "../headers/vectorCheker.h"
#include "../headers/BTSCheker.h"

void LoadDictionary(MyHashTable &Table, std::shared_ptr<BTrie> BTCheker, vectorCheker &VCheker, BTS &BTSCheker);
void CheckTexts(MyHashTable &Table, std::shared_ptr<BTrie> BTCheker, vectorCheker &VCheker, BTS &BTSCheker);




int main() {
    MyHashTable HashTableCheker;
    auto BTCheker = std::make_shared<BTrie>();
    vectorCheker VCheker;
    BTS BTSCheker;
    LoadDictionary(HashTableCheker, BTCheker, VCheker,BTSCheker);
    CheckTexts(HashTableCheker, BTCheker, VCheker, BTSCheker);

}


void LoadDictionary(MyHashTable &Table, std::shared_ptr<BTrie>BTCheker,vectorCheker &VCheker,BTS &BTSCheker){
    std::string s = "";
    std::ifstream file("../texts/Dictionary.txt");

    auto start = std::chrono::high_resolution_clock::now();
    while (getline(file, s)) {
        Table.add(s);

    }
    auto stop = std::chrono::high_resolution_clock::now();
    std::cout << "hashTable load time is " << std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count() << std::endl;

    file.close();
    file.open("../texts/Dictionary.txt");
    start = std::chrono::high_resolution_clock::now();
    while (getline(file, s)) {
        BTCheker->add(s);
    }
    stop = std::chrono::high_resolution_clock::now();
    std::cout << "BTrie load time is " << std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count() << std::endl;
    start = std::chrono::high_resolution_clock::now();

    file.close();
    file.open("../texts/Dictionary.txt");
    while (getline(file, s)) {
        VCheker.add(s);
    }
    stop = std::chrono::high_resolution_clock::now();
    std::cout << "Vector load time is " << std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count() << std::endl;
    file.close();
    file.open("../texts/Dictionary.txt");
    std::vector<std::string> name;
    while (std::getline(file, s)) {
        name.push_back(s);
    }
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(name.begin(), name.end(), g);
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < name.size(); i++)
    {
        BTSCheker.add(name.at(i));
    }
    stop = std::chrono::high_resolution_clock::now();
}

void CheckTexts(MyHashTable &Table, std::shared_ptr<BTrie> BTCheker, vectorCheker &VCheker, BTS &BTSCheker) {
    std::ifstream text;
    std::string s = "";
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < Table.texts.size(); i++) {
        text.open(Table.texts[i]);
        while (getline(text, s))
        {
            Table.find(s);
        }
        text.close();
    }
    auto stop = std::chrono::high_resolution_clock::now();
    std::cout << "alice check HashTable is " << std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count() << std::endl;
    std::cout << "badwords = " << Table.badwords << std::endl;
    std::cout << "Amount of words = " << Table.AmountOfWords << std::endl;
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < BTCheker->texts.size(); i++) {
        text.open(BTCheker->texts[i]);
        while (getline(text, s))
        {
            BTCheker->find(s);
        }
        text.close();
    }
    stop = std::chrono::high_resolution_clock::now();
    std::cout << "alice check BTrie is " << std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count() << std::endl;
    std::cout << "badwords = " << BTCheker->badwords << std::endl;
    std::cout << "Amount of words = " << BTCheker->AmountOfWords << std::endl;

    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < VCheker.texts.size(); i++) {
        text.open(VCheker.texts[i]);
        while (getline(text, s))
        {
            VCheker.find(s);
        }
        text.close();
    }
    stop = std::chrono::high_resolution_clock::now();
    std::cout << "alice check Vector is " << std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count() << std::endl;
    std::cout << "badwords = " << VCheker.badwords << std::endl;
    std::cout << "Amount of words = " << VCheker.AmountOfWords << std::endl;
    start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < BTSCheker.texts.size(); i++) {
        text.open(BTSCheker.texts[i]);
        while (getline(text, s))
        {
            BTSCheker.find(s);
        }
        text.close();
    }
    stop = std::chrono::high_resolution_clock::now();
    std::cout << "alice check BTSCheker is " << std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count() << std::endl;
    std::cout << "badwords = " << BTSCheker.badwords << std::endl;
    std::cout << "Amount of words = " << BTSCheker.AmountOfWords << std::endl;
}