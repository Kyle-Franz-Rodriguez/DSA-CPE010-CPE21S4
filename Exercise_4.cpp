/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
// Create a node
class Node {
    public:
    int value;
    Node* next;
};


int main() {
    Node* head;
    Node* one = NULL;
    Node* two = NULL;
    Node* three = NULL;
    
    //Allocate 3 nodes on the heap
    one = new Node();
    two = new Node();
    three = new Node();
    
    //Assign value values
    one ->value = 1;
    two ->value = 2;
    three ->value = 3;
    
    //Connect nodes
    one ->next = two;
    two ->next = three;
    three ->next = NULL;
    
    //Print the linked list value
    head = one;
    while (head != NULL) {
        std::cout << head ->value;
        head = head ->next;
    }
}