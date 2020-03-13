
#include <sstream>

#include "../headers/BTSCheker.h"


node* BTS::CreateNode(std::string data) {
    node* newnode = new node;
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

void BTS::add(std::string data) {
    // Create node using data from argument list.
    node* temp = CreateNode(data);
    node* t = new node;
    t = root;

    // If root is null, assign it to the node created.
    if (root == NULL)
        root = temp;
    else
    {
        // Find the position for the new node to be inserted.
        while (t != NULL)
        {
            if (t->data.compare(data) > 0)
            {
                if (t->right == NULL)
                {
                    // If current node is NULL then insert the node.
                    t->right = temp;
                    break;
                }
                // Shift pointer to the left.
                t = t->right;
            }

            else if (t->data.compare(data) <= 0)
            {
                if (t->left == NULL)
                {
                    // If current node is NULL then insert the node.
                    t->left = temp;
                    break;
                }
                // Shift pointer to the left.
                t = t->left;
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