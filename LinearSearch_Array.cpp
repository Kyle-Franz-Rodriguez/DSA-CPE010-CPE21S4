#include <iostream>

int linearSearch(int arr[], int size, int target)
{
    for(int i=0; i<size; i++)
    {
        if(arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}

int main() 
{
    int arr[] = {5,3,8,4,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    int target;
    
    std::cout << "Enter a number to search: ";
    std::cin >> target;
    
    unsigned int result = linearSearch(arr,size,target);
    if(result == -1)
    {
        std::cout<<"Element not found"<<std::endl;
    }
    else
    {
        std::cout<<"Element found at index: "<<result<<std::endl;
    }
    return 0;
}