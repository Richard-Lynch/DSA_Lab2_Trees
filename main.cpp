#include <stdio.h>

#include "Tree.hpp"

int main(){
    Tree test_tree;

    char test_array[] = "The {quick}, (brown) Fox jumps over the lazy-Dog!";

    printf("Starting instering '%s'\n\n", test_array);
    int i = 0;
    while(test_array[i] != '\0'){
        test_tree.insert(test_array[i]);        
        i++;
    }
    printf("Finished instering '%s'\n\n", test_array);

    test_tree.print_sorted();

    char search_char = 'q';

    printf("Searching for %c\n", search_char);
    Tree_Node* found_char = test_tree.search(search_char);
    printf("Character found by the search was: '%c'\n", found_char->data);

    test_tree.balance();

    test_tree.print_sorted();

    printf("Creating a balaced tree from char array\n");
    char second_test_array[] = "X Z C B A Y";
    Tree second_test_tree(second_test_array);
    printf("Finished creating a balaced tree from char array\n\n");

    second_test_tree.print_sorted();
    

    return 0;
}