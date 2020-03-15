#include <algorithm>
#include <string>
#include <sstream>


#include "../headers/BTrie.h"



short int BTrie::hash(const char letter){
    // assign the last position to the apostrophe
    if (letter == '\'')
    {
        return 26;
    }

    // ignore case by converting the given letter to lowercase
    return tolower(letter) - 97;
}

void BTrie::add(std::vector<std::string> input) {
    for(int i=0;i<input.size();i++) {
        bnode *node = root;
        std::string temp=input[i];
        for (int k = 0; k < temp.size(); k++) {
            char c = temp[k];
            short int key = hash(c);
            if (node->children[key] == 0)
            {
                node->children[key] = new bnode();
            }
            node = node->children[key];

        }
        node->is_word = true;
    }
}

void BTrie::find(std::string input) {
    input = transform(input);
    std::stringstream ss(input);
    std::string s;
    while (ss >> s) {
        AmountOfWords++;
        bnode* node = root;
        bool breaked = false;
        for (char a : s)
        {
            short int key = hash(a);
            if (node->children[key] == nullptr)
            {
                badwords++;
                breaked = true;
                break;
            }
            node = node->children[key];

        }
        if (!breaked && !node->is_word)
        {
            badwords++;
        }
    }
}
