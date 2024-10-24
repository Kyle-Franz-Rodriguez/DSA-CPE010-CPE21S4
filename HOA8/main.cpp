#include <iostream>
#include <cstdlib>
#include <time.h>
#include "shellsort.h"
#include "mergesort.h"
#include "quicksort.h"

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
    
	//Shell sort
    shellsort(sortingset, max_size);

	//Merge sort
    mergesort(sortingset, max_size);
    showmerge(sortingset, max_size);
    
    //Quick sort
    quicksort(sortingset, 0, max_size - 1);
    showquick(sortingset, max_size);
    
    return 0;
}
