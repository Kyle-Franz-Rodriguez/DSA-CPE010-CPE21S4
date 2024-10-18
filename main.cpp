#include <iostream>
#include <cstdlib> //For generating random integers
#include <time.h>
#include "bubblesort.h"
#include "selectionsort.h"
#include "insertionsort.h"

const int max_size = 100;

int main() {
	//to populate array with random values
	int dataset[max_size];
	int sortingset[max_size];
	srand(time(0));
	for (int i = 0; i < max_size; i++) {
	    dataset[i] = rand() % 101;
	    sortingset[i] = dataset[i];
	}
	//print the dataset
	std::cout << "Unsorted Array" << std::endl << "[ ";
	for(int i = 0; i < max_size; i++) {
	    std::cout << dataset[i] << ' ';
    }
    std::cout << "]" << std::endl <<std::endl;
    
	//Bubble sort
    bubbleSort(sortingset, max_size);
    
    //Selection sort
    selectionSort(sortingset, max_size);
    
    //Insertion sort
    insertionSort(sortingset, max_size);
    
    return 0;
}


