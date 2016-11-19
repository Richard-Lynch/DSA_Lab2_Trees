#include <stdio.h>

#include "Tree.hpp"

int main(){
    Tree test_tree;

    char test_array[] = "the quick brown fox jumps over the lazy dog";

    printf("Starting instering '%s'\n\n", test_array);
    int i = 0;
    while(test_array[i] != '\0'){
        printf("inserting '%c' ", test_array[i]);
        bool inserted = test_tree.insert(test_array[i]);
        if(!inserted){
            printf("failed to insert '%c'\n", test_array[i]);
        }
        else{
            printf("\n");
        }
        
        i++;
    }
    printf("Finished instering '%s'\n\n", test_array);

    test_tree.print_sorted();

    test_tree.balance();

    test_tree.print_sorted();



    return 0;
}