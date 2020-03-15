#pragma once
#include <string>
#include <array>
#include <vector>
class Cheker {
public:
    virtual void add(std::vector<std::string> input)=0;
    virtual void find(std::string input)=0 ;
    const std::string getNameClass();
    static std::string transform(std::string input);
    std::array<std::string,5> texts = {"../texts/alice.txt","../texts/dracula.txt","../texts/holmes.txt","../texts/sherlock.txt","../texts/tolstoy.txt" };
    int badwords=0;
    int AmountOfWords=0;
    int LoadTime=0;
    int CheckTime=0;
};

//