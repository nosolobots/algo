#include <iostream>

int main()
{
    int arr[10];

    std::cout << "arr: {";
    for(int i=0; i<10; i++)
        std::cout << arr[i] << ", ";
    std::cout << "\b\b}" << std::endl;

    return 0;
}
