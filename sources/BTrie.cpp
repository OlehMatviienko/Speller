#include <algorithm>
#include <string>
#include <sstream>


#include "../headers/BTrie.h"


BTrie::BTrie() {
    root = new bnode();
}
short int BTrie::hash(const char letter){
    // assign the last position to the apostrophe
    if (letter == '\'')
    {
        return 26;
    }

    // ignore case by converting the given letter to lowercase
    return tolower(letter) - 97;
}

void BTrie::add(std::string input) {
    bnode* node = root;
    for (int i = 0; i < input.size(); i++)
    {
        char a = input[i];
        short int key = hash(a);
        if (node->children[key] == 0)
        {
            node->children[key] = new bnode();
        }
        node = node->children[key];

    }
    node->is_word = true;
}

void BTrie::find(std::string input) {
    input = transform(input);
    std::stringstream ss(input);
    std::string s;
    while (ss >> s) {
        AmountOfWords++;
        bnode* node = root;
        bool breaked = false;
        for (int i = 0; i < s.size(); i++)
        {
            char a = s[i];
            short int key = hash(a);
            if (node->children[key] == 0)
            {
                badwords++;
                breaked = true;
                break;
            }
            node = node->children[key];

        }
        if (!breaked && node->is_word == false)
        {
            badwords++;
        }
    }
}
