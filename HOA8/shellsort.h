#include <iostream>

template <typename T>
void shellsort(T arr[], const int size) {
    for (int i = size/2; i > 0; i /= 2) {
        for (int interval = i; interval < size; interval += 1) {
            int temp = arr[interval];
            int interval2;            
            for (interval2 = interval; interval2 >= i && arr[interval2 - i] > temp; interval2 -= i) {
                arr[interval2] = arr[interval2 - i];
            }
            arr[interval2] = temp;
        }
    }
    //Print the array
    std::cout << "Shell Sorted" << std::endl << "[ ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << ' ';
    }
    std::cout << "]" << std::endl << std::endl;
}