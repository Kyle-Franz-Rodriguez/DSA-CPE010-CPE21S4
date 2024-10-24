#include <iostream>


void merge(int ar[], int arr1[], int arr2[], int n1, int n2) {

    int p1 = 0;
    int p2 = 0;
    int p3 = 0;
    while (p1 < n1 && p2 < n2) {
        if (arr1[p1] < arr2[p2]) {
            ar[p3]=arr1[p1];
            p3++;
            p1++;
        }
        else {
            ar[p3]=arr2[p2];
            p3++;
            p2++;
        }
    }
    while (p1 < n1) {
        ar[p3]=arr1[p1];
        p3++;
        p1++;
    }
    while (p2 < n2) {
        ar[p3]=arr2[p2];
        p3++;
        p2++;
    }
}

void mergesort(int arr[], const int size) {

    if (size <= 1) 
	    return;

    if (size % 2 == 0) {
        int arr1[size/2];
        int arr2[size/2];
        int k=0;
        int l=0;

        for (int i=0;i<size;i++) {
            if (i<(size/2)) {
                arr1[k++]=arr[i];
            }
            else {
                arr2[l++]=arr[i];
            }
        }

        mergesort(arr1,size/2);
        mergesort(arr2,size/2);

        for (int i=0;i<size;i++)
        {
        arr[i]=0;
        }

        merge(arr, arr1, arr2,size/2,size/2);
    }

    if (size%2!=0)
    {
        int arr1[(size-1)/2];
        int arr2[(size+1)/2];
        int k=0;
        int l=0;
        for (int i=0;i<size;i++)
        {
            if (i<((size-1)/2))
            {
                arr1[k++]=arr[i];
            }

            else
            {
                arr2[l++]=arr[i];
            }
        }

        mergesort(arr1,(size-1)/2);
        mergesort(arr2,(size+1)/2);

        for (int i=0;i<size;i++)
        {
            arr[i]=0;
        }

        merge(arr, arr1, arr2,(size-1)/2,(size+1)/2 );
    }
}

void showmerge(int arr[], const int size) {
	//Print the array
        std::cout << "Merge Sorted" << std::endl << "[ ";
        for (int i = 0; i < size; i++) {
            std::cout << arr[i] << ' ';
        }
        std::cout << "]" << std::endl << std::endl;    
}


