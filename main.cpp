/*
Richard Lynch
12302202
3D5A Lab 3 - Trees

ASSUMPTIONS:
1. The tree is only to store ascii characters of upper and lower case letters
2. Upper case letters are to be sorted as higher than all lower case letters

NOTE:
1. There is a method supplied to balance an unbalanced tree, if the insert method has been used
2. There is are two constructors for a tree, one which will create an empty tree and one which will create a balanced tree from an unsorted array of chars

*/
#include <stdio.h>

#include "Tree.hpp"

int main(){
    Tree test_tree;

    char test_array[] = "The {quick}, (brown) Fox jumps over the lazy-Dog!";    //array contains non letter chars which should be ignored

    printf("Starting instering '%s'\n\n", test_array);
    int i = 0;
    while(test_array[i] != '\0'){           //while not at the end of the string
        test_tree.insert(test_array[i]);    //insert the current char in to the tree    
        i++;                                //increment to the next char
    }
    printf("Finished instering '%s'\n\n", test_array);

    printf("Checking if the tree is balanced\n");
    if(test_tree.is_balanced()){
        printf("The tree is balanced\n\n");
    }
    else{
        printf("The tree is NOT balanced\n\n");
    }

    test_tree.print_sorted();   //print the sorted tree

    char search_char = 'q';     //char to be searched for

    printf("Searching for %c\n", search_char);
    Tree_Node* found_char = test_tree.search(search_char);                  //search for the char
    printf("Character found by the search was: '%c'\n\n", found_char->data);  //print the searched char

    test_tree.balance();        //balance the current tree

    printf("Checking if the tree is balanced\n");
    if(test_tree.is_balanced()){
        printf("The tree is balanced\n\n");
    }
    else{
        printf("The tree is NOT balanced\n\n");
    }

    test_tree.print_sorted();   //print the balanced tree(should be as above)

    printf("Creating a balanced tree from char array\n");
    char second_test_array[] = "X Z C B A Y";   //test array supplied
    Tree second_test_tree(second_test_array);   //create new tree with the char array as an arugment for the constructor
    printf("Finished creating a balanced tree from char array\n\n");

    printf("Checking if the tree is balanced\n");
    if(test_tree.is_balanced()){
        printf("The tree is balanced\n\n");
    }
    else{
        printf("The tree is NOT balanced\n\n");
    }

    second_test_tree.print_sorted();            //print the second tree
    

    return 0;
}