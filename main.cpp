#include <stdio.h>

#include "Tree.hpp"

int main(){
    Tree test_tree;

    char test_array[] = "the quick brown fox jumps over the lazy dog";

    printf("Starting instering '%s'\n\n", test_array);
    int i = 0;
    while(test_array[i] != '\0'){
        test_tree.insert(test_array[i]);        
        i++;
    }
    printf("Finished instering '%s'\n\n", test_array);

    test_tree.print_sorted();

    test_tree.balance();

    test_tree.print_sorted();

    return 0;
}