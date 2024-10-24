#include <iostream>
#include <cstdlib> //For generating random integers
#include <time.h>
#include "searching.h"
#include "nodes.h"


const int max_size = 50;

int main() {
	//to populate array with random values
	int dataset[max_size];
	srand(time(0));
	for (int i = 0; i < max_size; i++) {
	    dataset[i] = rand();
	}
	//print the dataset
	for(int i = 0; i < max_size; i++) {
	    std::cout << dataset[i] << ' ';
    }
    return 0;
}


