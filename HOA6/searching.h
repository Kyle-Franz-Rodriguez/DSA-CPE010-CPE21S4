#include <iostream>
#include "nodes.h"

//Linear search for arrays
template <typename T>
int linearSearch(int arr[], int size, T target)
{
    for(int i=0; i<size; i++)
    {
        if(arr[i] == target)
        {
            std::cout << "Target found at index: " << i;
			return i;
        }
    }
    std::cout << "Target not found";
	return -1;
}

//Linear search for linked lists
template <typename U>
int linearLS(Node<U> head, U target){
	int index = 0;
	Node<U> *current = head;
	while(current != nullptr) {
		if(current->data == target) {
			std::cout <<"Target found at index: " << index;
			return index;
		}
		current = current->next;
		index += 1;
	}
	std::cout <<"Target not found";
	return -1;
}
