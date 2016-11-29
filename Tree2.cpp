// // #include "Tree.hpp"


// // bool Tree::insert(char data){
// //     Tree_Node* curr = root;
// //     Tree_Node* prev = NULL;
// //     bool inserted = false;

// //     while(!inserted){
// //         if(curr == NULL){
// //             curr = new Tree_Node(prev, data);
// //             inserted = true;
// //         }
// //         else{
// //             if(curr->data > data){
// //                 prev = curr;
// //                 curr = left;
// //             }
// //             else{
// //                 prev = curr;
// //                 curr = right;
// //             } 
// //         }
// //     }
// //     return inserted;
// // }

// // Tree_Node* Tree::search(char data){
// //     Tree_Node* curr = root;

// //     while(curr){
// //         if(curr->data == data)
// //         {
// //             return curr;
// //         }
// //         else if(curr->data > data){
// //             curr = left;
// //         }
// //         else{
// //             curr = right;
// //         } 
// //     }
// //     return curr;
// // }

// // void Tree::print_sorted(){
// //     Tree_Node* curr = left_most();
// //     Tree_Node* prev = curr->parent;

// //     printf("Smallest\n%c\n", curr->data)

// //     while(curr != root){
// //         if(curr->left != NULL){
// //             printf("%c\n", curr->left->data);
// //         }
// //         if(curr->right != NULL){
// //              printf("%c\n", curr->right->data);
// //         }
        

// //         else{
// //             if(curr->data > data){
// //                 prev = curr;
// //                 curr = left;
// //             }
// //             else{
// //                 prev = curr;
// //                 curr = right;
// //             } 
// //         }
// //     }
// //     return inserted;

// // }

// // void Tree::_delete(){


// // }

// // Tree_Node* TREE::left_most(){
// //     Tree_Node* curr = root;
// //     Tree_Node* prev = NULL;
// //     bool found = false;

// //     while(!found){
// //         if(curr->left != NULL){
// //             prev = curr;
// //             curr = left;
// //         }
// //         else if(curr->right != NULL){
// //             prev = curr;
// //             curr = right;
// //         }
// //         else{
// //             found = true;
// //         }
// //     }
// //     return curr;
// // }
// // Tree_Node* right_most(){
// //     Tree_Node* curr = root;
// //     Tree_Node* prev = NULL;
// //     bool found = false;

// //     while(!found){
// //         if(curr->right != NULL){
// //             prev = curr;
// //             curr = right;
// //         }
// //         else if(curr->left != NULL){
// //             prev = curr;
// //             curr = left;
// //         }
// //         else{
// //             found = true;
// //         }
// //     }
// //     return curr;
// // }

// // Tree::Tree(){
// //     root = new Tree_Node;


// // }

// // Tree::~Tree(){
// //     _delete();
// // }

// Tree_Node* Tree::left_most(Tree_Node* Root){
//     Tree_Node* location = NULL;

//     if(Root->left != NULL){//if there is a subtree on the left
//         location = left_most(Root->left);//search the subtree on the left
//     }
//     else if(Root->right != NULL){//if there is a subtree on the right
//         location = left_most(Root->right);//search the subtree on the right
//     }
//     else{//if there are no more subtrees
//         location = Root;//the node has been found
//     }
//     return location;
// }

// Tree_Node* right_most(Tree_Node* Root){
//     Tree_Node* location = NULL;
//     if(Root->right != NULL){//if there is a subtree on the right
//         location = right_most(Root->right);//search the subtree on the right
//     }
//     else if(Root->left != NULL){//if there is a subtree on the left
//         location = right_most(Root->left);//search the subtree on the left
//     }
//     else{//if there are no more subtrees
//         location = Root;//the node has been found
//     }
//     return location;
// }