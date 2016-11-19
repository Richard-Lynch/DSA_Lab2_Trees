#include "Tree.hpp"

bool Tree::insert(char data){
    printf("inserting '%c' ", data);
    bool inserted = insert(data, root);
    if(inserted == true){
        nodes++;
    }
    if(!inserted){
        printf("failed to insert '%c'\n", data);
    }
    else{
        printf("\n");
    }
    return inserted;
}

bool Tree::insert(char data, Tree_Node* Root){
    bool inserted = true;

    if(Root == NULL){//if the tree is empty
        root = new Tree_Node(NULL, data);
    }
    else if(Root->data > data){//if data is less than node data add to left
        if(Root->left == NULL){//if the left node is empty
            Root->left = new Tree_Node(Root, data);//create and add left node
        }
        else{//if there is a left subtree
            inserted = insert(data, Root->left);//insert into the subtree on the left
        }
    }
    else if(Root->data < data){//if data is less than node data add to right
        if(Root->right == NULL){//if the right node is empty
            Root->right = new Tree_Node(Root, data);//create and add right node
        } 
        else{//if there is a right subtree
            inserted = insert(data, Root->right);//insert into the subtree on the right
        }
    }
    else{//otherwise the value is the same and has already been added
        inserted = false;;
    }
    return inserted;
}

Tree_Node* Tree::search(char data){
    return search(data, root);
}

Tree_Node* Tree::search(char data, Tree_Node* Root){
    Tree_Node* location = NULL;

    if(Root->data > data){//if the data is less than the node data
        location = search(data, Root->left);//search the subtree on the left
    }
    else if(Root->data < data){//if the data is greater than the node data
        location = search(data, Root->right);//search the subtree on the right
    }
    else{//if the data is equal to the node data
        location = Root;//the node has been found
    }
    return location;
}

void Tree::print_sorted(){
    printf("Printing the sorted tree:\n");
    print_sorted(root);
    printf("Finished Printing the sorted tree\n\n");
}

void Tree::print_sorted(Tree_Node* Root){
    if(Root->left != NULL){//if there is a subtree on the left
        print_sorted(Root->left);//print the left subtree
    }

    printf("'%c'\n", Root->data);//print the current node

    if(Root->right != NULL){//if there is a subtree on the right
        print_sorted(Root->right);//print the right subtree
    }
}

void Tree::_delete(Tree_Node* Root){
    if(root != NULL){
        if(Root->left != NULL){//if there is a subtree on the left
            delete(Root->left);//delete the left subtree
        }

        if(Root->right != NULL){//if there is a subtree on the right
            delete(Root->right);//delete the right subtree
        }
    }

    delete Root;//delete the current Node
}

void Tree::balance(){
    printf("Tree is being balance.\n");
    char temp[nodes];
    sort_tree(root, temp);
    _delete(root);
    root = NULL;
    nodes = 0;
    insert_sorted(temp, 0, index-1);
    index = 0;
    printf("Finished Balancing the tree.\n\n");
}

void Tree::sort_tree(Tree_Node* Root, char array[]){
    if(Root->left != NULL){//if there is a subtree on the left
        sort_tree(Root->left, array);//add all the data in the left subtree
    }

    array[index] = Root->data;//add the current node data to the array
    index++;

    if(Root->right != NULL){//if there is a subtree on the right
        sort_tree(Root->right, array);//add all the data in the right subtree
    }
}

void Tree::insert_sorted(char array[], int first, int last){
    if(first < last){
        int pivot = int((last + first)/2);
        insert(array[pivot]);
        insert_sorted (array, first, pivot-1);
        insert_sorted (array, pivot+1, last);
    }
    else if(first == last){
        insert(array[first]);
    }
}

Tree_Node* Tree::left_most(Tree_Node* Root){
    Tree_Node* location = NULL;

    if(Root->left != NULL){//if there is a subtree on the left
        location = left_most(Root->left);//search the subtree on the left
    }
    else if(Root->right != NULL){//if there is a subtree on the right
        location = left_most(Root->right);//search the subtree on the right
    }
    else{//if there are no more subtrees
        location = Root;//the node has been found
    }
    return location;
}

Tree_Node* right_most(Tree_Node* Root){
    Tree_Node* location = NULL;
    if(Root->right != NULL){//if there is a subtree on the right
        location = right_most(Root->right);//search the subtree on the right
    }
    else if(Root->left != NULL){//if there is a subtree on the left
        location = right_most(Root->left);//search the subtree on the left
    }
    else{//if there are no more subtrees
        location = Root;//the node has been found
    }
    return location;
}

Tree::Tree(){
    root = NULL;
    index = 0;
    nodes = 0;

}

Tree::~Tree(){
    _delete(root);
}