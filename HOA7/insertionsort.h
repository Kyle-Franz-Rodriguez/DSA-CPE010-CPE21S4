#include <iostream>

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
	// Print the sorted array
    std::cout << "Insertion Sorted" << std::endl << "[ ";
    for (int i = 0; i < N; i++) {
        std::cout << arr[i] << ' ';
    }
    std::cout << "]" << std::endl << std::endl;
	//Step 4: EXIT
}
