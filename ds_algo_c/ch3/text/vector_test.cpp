#include <vector>
#include <iostream>

void printv(std::vector<int>& v)
{
    std::cout << "{";
    for(int i=0; i<v.size(); i++)
        std::cout << v[i] << ", ";
    std::cout << "\b\b}" << std::endl;

}

int main()
{
    std::vector<int> v1(4);
    std::vector<int> v2(4, 199);

    printv(v1); // default elements initialization to {0}
    printv(v2); // elements initialization to {199}
}
