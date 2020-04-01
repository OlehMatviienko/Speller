#pragma once
#include <string>
#include <array>
#include <vector>
class Checker {
public:
    virtual void add(std::vector<std::string> input)=0; 
    virtual void find(std::string input)=0 ;
    const std::string getNameClass(); //getting the demangle Name of Class
    static std::string transform(std::string input); //transform inputed string. Delete all non-letters chars, except " ' "

    std::array<std::string,5> texts = {"../include/texts/alice.txt","../include/texts/dracula.txt","../include/texts/holmes.txt","../include/texts/sherlock.txt","../include/texts/tolstoy.txt" };
    int badwords=0; // counter of bad words
    int AmountOfWords=0; // counter of Amount of words
    int LoadTime=0; // Load Time
    int CheckTime=0; // Check Time
};
