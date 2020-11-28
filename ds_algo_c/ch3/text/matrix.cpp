/*
 * matrix creation
 * */

#include <cstdlib>
#include <iostream>
#include <ostream>
#include <vector>

#define N 3
#define M 5

int main()
{
    // Using arrays
    int** M1 = new int*[N]; // create rows
    for(int i=0; i<N; i++)
        M1[i] = new int[M]; // create cols

    std::cout << "M1:" << std::endl;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            std::cout << M1[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    // Delete arrays
    for(int i=0; i<N; i++) 
        delete[] M1[i];
    delete[] M1;

    // Using vectors
    std::vector< std::vector<int> > M2(N, std::vector<int>(M));

    std::cout << "M2:" << std::endl;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            std::cout << M2[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    return EXIT_SUCCESS;
}
