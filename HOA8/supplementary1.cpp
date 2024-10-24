#include <iostream>
#include <cstdlib>
#include <time.h>

//NUMBER 1
void insertionSort(int arr[], int N) {
    for (int i = 1; i < N; i++) {
        int K = arr[i];
        int j = i - 1;
		while (j >= 0 && arr[j] > K) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = K;
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);

    return (i + 1);
}

//The pivot is exactly in the middle order here
//so I think it is possible to sort the lower and higher half of the array
//I will use insertion sort as my sorting algorithm
void quicksort_insertion(int arr[], int low, int high) {
    while (low < high) {
	    if (high-low + 1 < 10) {
	        insertionSort(arr, high+1);
	        break;
	    }
	    else {
		    int pivot = partition(arr, low, high);
			if (pivot-low<high-pivot) {
				quicksort_insertion(arr, low, pivot - 1); 
		        low = pivot + 1;
		    }
		    else {
		        quicksort_insertion(arr, pivot + 1, high);
		        high = pivot-1;
		    }
	    }
    }
}

void showquick(int arr[], const int size) {
	//Print the array
        std::cout << "Quick Sorted With Insertion Sort" << std::endl << "[ ";
        for (int i = 0; i < size; i++) {
            std::cout << arr[i] << ' ';
        }
        std::cout << "]" << std::endl << std::endl;    
}

int main() {
	
	const int max_size = 50;
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
    
    //Quick sort
    quicksort_insertion(sortingset, 0, max_size - 1);
    showquick(sortingset, max_size);
}
