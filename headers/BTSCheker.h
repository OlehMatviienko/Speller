
#include <string>
#include "Cheker.h"

struct node
{
    std::string data;
    node* left;
    node* right;
};

class BTS : public Cheker {
public:

    BTS() :  root(NULL) {badwords=0;};

    void add(std::vector<std::string> input) override;

    void find(std::string input) override;

private:
    node *root;

    node *CreateNode(std::string data);
};