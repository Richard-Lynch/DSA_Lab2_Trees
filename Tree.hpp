#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include "Tree_Node.hpp"

// struct Tree_Node{
//     char data;
//     Tree_Node* parent;
//     Tree_Node* left, right;
// };

class Tree{
public:
Tree_Node* root;

int nodes;
int index;

bool insert(char data);
void print_sorted();
Tree_Node* search(char data);

void balance();
Tree();
~Tree();

private:
bool insert(char data, Tree_Node* Root);
void print_sorted(Tree_Node* Root);
Tree_Node* search(char data, Tree_Node* Root);
void _delete(Tree_Node* Root);

void sort_tree(Tree_Node* Root, char array[]);
void insert_sorted(char array[], int first, int last);

Tree_Node* left_most(Tree_Node* Root);
Tree_Node* right_most(Tree_Node* Root);
};