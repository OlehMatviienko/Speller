
#include <sstream>
#include <algorithm>
#include <random>

#include "../headers/BTSCheker.h"


node* BTS::CreateNode(std::string data) {
    node* newnode = new node;
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
        // Create node using data from argument list.
        node *temp = CreateNode(data);
        node *t = new node;
        t = root;

        // If root is null, assign it to the node created.
        if (root == nullptr)
            root = temp;
        else {
            // Find the position for the new node to be inserted.
            while (t != nullptr) {
                if (t->data.compare(data) > 0) {
                    if (t->right == nullptr) {
                        // If current node is NULL then insert the node.
                        t->right = temp;
                        break;
                    }
                    // Shift pointer to the left.
                    t = t->right;
                } else if (t->data.compare(data) <= 0) {
                    if (t->left == nullptr) {
                        // If current node is NULL then insert the node.
                        t->left = temp;
                        break;
                    }
                    // Shift pointer to the left.
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
    node* temp ;
    while (ss >> s) {
        AmountOfWords++;
        temp = root;
        bool found= false;
    // Run the loop untill temp points to a NULL pointer.
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