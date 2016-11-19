#include "Tree_Node.hpp"

bool Tree_Node::isLeaf(){
    if(left == NULL && right == NULL){
        return true;
    }
    else{
        return false;
    }
}

bool Tree_Node::isRoot(){
    if(parent == NULL){
        return true;
    }
    else{
        return false;
    }
}

Tree_Node::Tree_Node(){
    parent = NULL;
    left = NULL;
    right = NULL;
    data = '\0';
}

Tree_Node::Tree_Node(Tree_Node* Parent, char Data){
    parent = Parent;
    data = Data;
    left = NULL;
    right = NULL;
}

Tree_Node::~Tree_Node(){

}