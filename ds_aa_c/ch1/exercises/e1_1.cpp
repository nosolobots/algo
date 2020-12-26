/*
 * Exercise 1.1
 *
 *  Write a program to solve the selection problem. Let k = N/2. Draw a table showing
 *  the running time of your program for various values of N.
 * */

#include <cstdlib>
#include <iostream>
#include <ctime>
#include<chrono>

#define NTESTS 10

void fillArray(int n, int* arr) {
    for(int i=0; i<n; i++)
        arr[i] = std::rand() % 10'000;   // [0, 10000)
}

// bubble sort desc
void sortArray(int n, int* arr) {
    int i=0, temp;
    bool swap = true;
    
    while(swap && i<n) {
        ++i;
        swap = false;
        for(int j=0; j<n-i; ++j) {
            if(arr[j]<arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swap = true;
            }
        }
    }    
}

int main() {
    int* arr;

    std::srand(std::time(nullptr));

    std::cout << "N\t\tN/2\t\tT\n"; 

    for(int i=1; i<NTESTS; i++) {
        int n = i*1000;
        arr = new int[n];

        fillArray(n, arr);

        auto start = std::chrono::system_clock::now();

        sortArray(n, arr);

        std::chrono::duration<double> elapsed_sec = std::chrono::system_clock::now() - start;

        std::cout << n << "\t\t" << arr[n/2] << "\t\t" << elapsed_sec.count() << "s\n"; 

        delete[] arr;
    }

    return EXIT_SUCCESS;
}
