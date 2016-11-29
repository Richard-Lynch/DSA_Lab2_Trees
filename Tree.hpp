#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include "Tree_Node.hpp"

class Tree{
public:
bool insert(char data);//inserts a single character into the tree(requirement 1)
void print_sorted();//prints the entire tree as a sorted list(requirement 2)
Tree_Node* search(char data);//returns a pointer to the node containing the char(requirement 3)
~Tree();//the destructor for the tree, which will delete the entire tree without memory leaks(requirement 4)
Tree(char chars[]);//constructor for a tree given an array of unsorted chars(requirement 5)

void balance();//if the current tree is unbalanced this method will balance the tree
bool is_balanced();//returns true if the tree is balanced
Tree();//constructor for an empty tree

private:
Tree_Node* root;//the pointer to the root node, this is managed by the class

int nodes;//the number of nodes in the tree, managed by the class
int index;//the current index for the balance function, managed by the class
int left;//number of nodes in left subtree
int right;//number of nodes in right subtree
int left_depth;//depth of left subtree
int right_depth;//depth of right subtree
int depth;//tempory value for depth of tree

bool insert(char data, Tree_Node* Root);//inserts a node recursivly, called by the public insert function
void print_sorted(Tree_Node* Root);//prints the listed in a sorted manner recursivly, called by the public print function
Tree_Node* search(char data, Tree_Node* Root);//searches the branch for the char recursivly, called by the public search function
void _delete(Tree_Node* Root);//deletes the branch recursivly, called by the destructor

void sort_tree(Tree_Node* Root, char array[]);//creates a sorted char array from an unsorted tree, called by the public balance function
void insert_sorted(char array[], int first, int last);//inserts the sorted char array such that the tree will be balanced, called by the public balance function

void BUBBLESORT(char* Array, int first, int last);//(pulled from last lab), called by the constructor when given an unsorted array of chars
};