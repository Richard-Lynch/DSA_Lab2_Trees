#include <stdio.h>
#include "Tree_Node.hpp"

struct Tree_Node{
    char data;
    Tree_Node* parent;
    Tree_Node* left, right;
};

class Tree{
public:
Tree_Node* root;

bool insert(char data);
Tree_Node* search(char data);
void print_sorted();
void _delete();

Tree_Node* left_most();
Tree_Node* right_most();


Tree();
~Tree();

private:


}