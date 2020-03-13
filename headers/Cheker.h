#pragma once
#include <string>
#include <array>

class Cheker {
public:
    virtual void add(std::string input)=0;
    virtual void find(std::string input)=0;
    std::string transform(std::string input);
    std::array<std::string,5> texts = {"../texts/alice.txt","../texts/dracula.txt","../texts/holmes.txt","../texts/sherlock.txt","../texts/tolstoy.txt" };
    int badwords=0;
    int AmountOfWords=0;
};

//