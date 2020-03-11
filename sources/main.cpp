#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <memory>


#include "../headers/HashTable.h"
#include "../headers/BTrie.h"
#include "../headers/vectorCheker.h"

void LoadDictionary(MyHashTable& Table, std::shared_ptr<BTrie>BCheker, vectorCheker& VCheker);
void CheckTexts(MyHashTable& Table, std::shared_ptr<BTrie>BCheker, vectorCheker& VCheker);


int main() {
    MyHashTable HashTableCheker;
    auto BCheker = std::make_shared<BTrie>();
    vectorCheker VCheker;
    LoadDictionary(HashTableCheker, BCheker, VCheker);
    CheckTexts(HashTableCheker, BCheker, VCheker);
}


void LoadDictionary(MyHashTable &Table, std::shared_ptr<BTrie>BCheker,vectorCheker &VCheker){
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
        BCheker->add(s);
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

}

void CheckTexts(MyHashTable& Table, std::shared_ptr<BTrie>BCheker, vectorCheker& VCheker) {
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
    for (int i = 0; i < BCheker->texts.size(); i++) {
        text.open(BCheker->texts[i]);
        while (getline(text, s))
        {
            BCheker->find(s);
        }
        text.close();
    }
    stop = std::chrono::high_resolution_clock::now();
    std::cout << "alice check BTrie is " << std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count() << std::endl;
    std::cout << "badwords = " << BCheker->badwords << std::endl;
    std::cout << "Amount of words = " << BCheker->AmountOfWords << std::endl;

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
}