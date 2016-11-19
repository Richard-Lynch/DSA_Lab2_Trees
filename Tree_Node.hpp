#include <stdio.h>

class Tree_Node{
public:
    char data;
    Tree_Node* parent;
    Tree_Node* left; 
    Tree_Node* right;

    bool isLeaf();
    bool isRoot();

    Tree_Node();
    Tree_Node(Tree_Node* Parent);
    Tree_Node(Tree_Node* Parent, char Data);
    ~Tree_Node();
};
