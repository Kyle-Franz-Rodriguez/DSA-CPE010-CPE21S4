#include <iostream>
#include <cstdlib> //For generating random integers
#include <time.h>
#include "bubblesort_vote.h"

void voteSearch(int arr[], int size) {
    int vote1=0; 
    int vote2=0;
    int vote3=0;
    int vote4=0; 
    int vote5=0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == 1) {
            vote1++;
        }
        if (arr[i] == 2) {
            vote2++;
        }
        if (arr[i] == 3) {
            vote3++;
        }
        if (arr[i] == 4) {
            vote4++;
        }
        if (arr[i] == 5) {
            vote5++;
        }
    }
    std::cout <<"Number of votes for Bo Dalton Capistrano: " << vote1 << std::endl;
    std::cout <<"Number of votes for Cornelius Raymon Agustín: " << vote2 << std::endl;
    std::cout <<"Number of votes for Deja Jayla Bañaga: " << vote3 << std::endl;
    std::cout <<"Number of votes for Lalla Brielle Yabut: " << vote4 << std::endl;
    std::cout <<"Number of votes for Franklin Relano Castro: " << vote5 << std::endl;
    
}
const int max_size = 100;

int main() {
	//to populate array with random values
	int dataset[max_size];
	int sortingset[max_size];
	srand(time(0));
	for (int i = 0; i < max_size; i++) {
	    dataset[i] = (rand() % 5) + 1;
	    sortingset[i] = dataset[i];
	}
	//print the dataset
	std::cout << "100 Unsorted Votes" << std::endl << "[ ";
	for(int i = 0; i < max_size; i++) {
	    std::cout << dataset[i] << ' ';
    }
    std::cout << "]" << std::endl <<std::endl;
    //print the sorted vote numbers
	//Bubble sort
    bubbleSort(sortingset, max_size);
    
    //Number of votes for each candidates
    voteSearch(sortingset, max_size);
    
    return 0;
}


