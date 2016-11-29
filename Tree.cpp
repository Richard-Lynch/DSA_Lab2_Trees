#include "Tree.hpp"

bool Tree::insert(char data){   //public insert method
    printf("inserting '%c' ", data);//output for debugging, can be removed

    if((data < 65 ) || (data > 90 && data < 97) || (data > 122)){   //if the data is not a ascii letter char
        printf("failed to insert '%c', char not allowed\n", data);  //do not insert and leave function
        return false;
    }
    bool inserted = insert(data, root);//otherwise call the private insert function, starting at the trees root
    if(inserted == true){   //if the char was inserted
        nodes++;            //increment the number of nodes
    }
    if(!inserted){                                                              //if the char wasnt inserted
        printf("failed to insert '%c', data already stored in tree\n", data);   //then it was already stored
    }
    else{
        printf("\n");   //prints an end line, to make the debugging output more readable
    }
    return inserted;    //returns the bool inserted or not, to allow debugging if required; not used
}

bool Tree::insert(char data, Tree_Node* Root){  //private insert method, called by the public insert, and by itself recursivly
    bool inserted = true;       //default to true

    if(Root == NULL){           //if the tree is empty
        root = new Tree_Node(NULL, data);               //create a new Tree_Node to be the root and insert the data
    }
    else if(Root->data > data){ //if data is less than node data add to left
        if(Root->left == NULL){                         //if the left child doesnt exist
            Root->left = new Tree_Node(Root, data);     //create and add left node
        }
        else{                                           //or if there is a left child
            inserted = insert(data, Root->left);        //insert into the sub tree on the left, by calling recursivly to the left child
        }
    }
    else if(Root->data < data){ //if data is less than node data add to right
        if(Root->right == NULL){                        //if the right child doesnt exist
            Root->right = new Tree_Node(Root, data);    //create and add right node
        } 
        else{                                           //or if there is a right child
            inserted = insert(data, Root->right);       //insert into the sub tree on the right, by calling recursivly to the right child
        }
    }
    else{                       //otherwise the value is the same and has already been added
        inserted = false;;
    }
    return inserted;            //return the result of inserting
}

Tree_Node* Tree::search(char data){ //public search method
    return search(data, root);      //calls private search method using root of tree
}

Tree_Node* Tree::search(char data, Tree_Node* Root){    //private search method
    Tree_Node* location = NULL; //set the location of the found node to null

    if(Root->data > data){                      //if the data is less than the node data
        location = search(data, Root->left);    //search the subtree on the left, by calling recursivly to the left child
    }
    else if(Root->data < data){                 //if the data is greater than the node data
        location = search(data, Root->right);   //search the subtree on the right, by calling recursivly to the right child
    }
    else{                                       //if the data is equal to the node data
        location = Root;                        //the node has been found
    }
    return location;    //return the location of the found node
}

void Tree::print_sorted(){  //public print method
    printf("Printing the sorted tree:\n");
    print_sorted(root); //calls the privcate print method
    printf("Finished Printing the sorted tree\n\n");
}

void Tree::print_sorted(Tree_Node* Root){   //private print method
    if(Root->left != NULL){         //if there is a subtree on the left
        print_sorted(Root->left);   //print the left subtree
    }

    printf("'%c'\n", Root->data);//print the current node

    if(Root->right != NULL){//if there is a subtree on the right
        print_sorted(Root->right);//print the right subtree
    }
}

void Tree::_delete(Tree_Node* Root){    //private delete method, called by the destructor
    if(root != NULL){   //if the tree isnt empty
        if(Root->left != NULL){     //if there is a subtree on the left
            _delete(Root->left);    //delete the left subtree, by calling _delete to the left child
        }

        if(Root->right != NULL){    //if there is a subtree on the right
            _delete(Root->right);   //delete the right subtree, by calling _delete to the right child
        }
    }

    delete Root;                    //delete the current Node
}

void Tree::balance(){   //public balance method
    printf("Tree is being balance.\n"); //used for debugging   
    char temp[nodes];                   //create a temporary array to store a sorted list of all nodes; this adds N auxilary space complexity
    sort_tree(root, temp);              //store each node in the tree into temp in a sorted order, by calling private sort_tree method
    _delete(root);                      //delete the current tree, by calling the private _delete function
    root = NULL;                        //set root to null as there is no longer is a tree
    nodes = 0;                          //set number of nodes to 0 as there are no nodes in an empty tree
    insert_sorted(temp, 0, index-1);    //create a new balanced tree for the sorted array, by calling private insert_sorted method
    index = 0;                          //reset the index value, used by sort tree and insert_sorted
    printf("Finished Balancing the tree.\n\n");
}

void Tree::sort_tree(Tree_Node* Root, char array[]){    //private sort_tree function, creates sorted array from unbalance tree
    if(Root->left != NULL){             //if there is a subtree on the left
        sort_tree(Root->left, array);   //add all the data in the left subtree, which will be less than the current node, by calling sort_tree recusivly to the left child
    }

    array[index] = Root->data;          //add the current node data to the array
    index++;

    if(Root->right != NULL){            //if there is a subtree on the right
        sort_tree(Root->right, array);  //add all the data in the right subtree, which will be greater than the current node, by calling sort_tree recusivly to the right child
    }
}

void Tree::insert_sorted(char array[], int first, int last){    //will create a balance tree from a sorted array
    if(first < last){       //ensure no "crossover"
        int pivot = int((last + first)/2);      //"pivot" is the median value of the current array to be sorted
        insert(array[pivot]);                   //so it is inserted first
        insert_sorted (array, first, pivot-1);  //all values less than the pivot are then inserted recursivly using the private insert_sorted method
        insert_sorted (array, pivot+1, last);   //all value greater than the pivot are then inserted recursivly using the private insert_sorted method
    }
    else if(first == last){     //if first == last, the array currently being added only contains a single item
        insert(array[first]);   //which needs to be added
    }
}


Tree::Tree(){   //constructor for empty tree
    root = NULL;    //initialises root
    index = 0;      //sets initial index to 0
    nodes = 0;      //sets the number of nodes to 0
}

Tree::Tree(char chars[]){   //constructor for a tree from a list of chars
    root = NULL;    //initialises root
    index = 0;      //sets initial index to 0
    nodes = 0;      //sets the number of nodes to 0

    printf("Calculating the size of the array\n");
    int size_of_array = 0;  //the size of the array being added
    while(chars[size_of_array]){    //while the char being tested isnt null
        size_of_array++;            //test the next char
    }
    printf("Finished calculating the size of the array\n\n");
    
    printf("Sorting the array\n");
    BUBBLESORT(chars, 0, size_of_array);    //sort the input array for insertion using the BUBBLESORT method
    printf("Finished sorting the array\n\n");

    insert_sorted(chars, 0, size_of_array); //insert using the private insert_sorted method

}

void Tree::BUBBLESORT(char* Array, int first, int last){ //private sort function, pulled from last lab
    bool sorted = false;//start with the list unsorted
    while(sorted == false){//while the list is still unsorted
        sorted = true;//set to true temporarily
        for(int i = first; i<last; i++){//for each value in the array
            if(Array[i+1] < Array[i]){//if the next value is less than the current value, 
                std::swap(Array[i+1], Array[i]);//swap these values,
                sorted = false;//and set sorted back to false as we've found an item in the list which is unsorted
            }
        }
    }
}

Tree::~Tree(){//detructor
    printf("Deleting Tree\n");  //calls the private _delete method on the root
    _delete(root);              //to delete the tree with no memort leaks
    printf("Finished Deleting Tree\n");
}