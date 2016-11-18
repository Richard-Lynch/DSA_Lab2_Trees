#include <stdio.h>

class Tree_Node{
public:
    char data;
    Tree_Node* parent;
    Tree_Node* left, right;

    Tree_Node();
    Tree_Node(Tree_Node* Parent, char Data);
    ~Tree_Node();
};
