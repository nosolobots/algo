/*
 * insertion sort implementation
 * */

#include <iostream>
#include <cstdlib>

void insertion_sort(char* arr, int n);

int main() 
{
    char test[] = {'C', 'A', 'G', 'H', 'Z', 'I'};
    int len = sizeof(test)/sizeof(char);
    
    for(int i=0; i<len; i++)
        std::cout << test[i] << " ";
    std::cout << std::endl;

    insertion_sort(test, len);

    for(int i=0; i<len; i++)
        std::cout << test[i] << " ";
    std::cout << std::endl;


    return EXIT_SUCCESS;
}

void insertion_sort(char* arr, int n)
{
    for(int i=1, j; i<n; i++) {
        char cur = arr[i];
        
        j = i-1;
        while(j>=0 && arr[j]>cur) {
            arr[j+1] = arr[j];
            --j;
        }

        arr[j+1] = cur;
    }
}

