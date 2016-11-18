#include "Tree_Node.hpp"

Tree_Node::Tree_Node(){
    parent = left = right = NULL;
    data = NULL;
}

Tree_Node::Tree_Node(Tree_Node* Parent, char Data){
    parent = Parent;
    left = right = NULL;
    data = NULL;
}

Tree_Node::Tree_Node(Tree_Node* Parent, char Data){
    parent = Parent;
    left = right = NULL;
    data = Data;
}

Tree_Node::~Tree_Node(){

}