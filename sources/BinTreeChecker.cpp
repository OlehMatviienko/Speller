
#include <sstream>
#include <algorithm>
#include <random>
#include <utility>

#include "BinTreeChecker.h"


std::shared_ptr<node> BTS::CreateNode(std::string data) {
    std::shared_ptr<node> newnode(new node);
    newnode->data = data;
    newnode->left = nullptr;
    newnode->right = nullptr;
    return newnode;
}

void BTS::add(std::vector<std::string> input) {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(input.begin(), input.end(), g);
    for(const auto& data : input) {
       std::shared_ptr<node> temp(CreateNode(data));
        std::shared_ptr<node> t;
        t = root;

        if (root == nullptr)
            root = temp;
        else {
            while (t != nullptr) {
                if (t->data.compare(data) > 0) {
                    if (t->right == nullptr) {
                        t->right = temp;
                        break;
                    }
                    t = t->right;
                } else if (t->data.compare(data) <= 0) {
                    if (t->left == nullptr) {
                        t->left = temp;
                        break;
                    }
                    t = t->left;
                }
            }
        }
    }
};

void BTS::find(std::string input) {
    input = transform(input);
    std::stringstream ss(input);
    std::string s;
    std::shared_ptr<node> temp ;
    while (ss >> s) {
        AmountOfWords++;
        temp = root;
        bool found= false;
            while (temp != nullptr)
            {
                if (temp->data == s)
                {
                    found=true;
                    break;
                }
                else if (temp->data.compare(s) < 0)
                    temp = temp->left;
                else
                    temp = temp->right;
            }
            if(!found) {
            badwords++;
            }
    }


}