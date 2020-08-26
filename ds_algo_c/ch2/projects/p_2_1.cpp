/*
Write a C++ program that can take a positive integer greater than 2 as
input and write out the number of times one must repeatedly divide this
number by 2 before getting a value less than 2.
*/

#include<iostream>

using namespace std;

int main()
{
    int num, c=0;

    cout << "Write a positive integer: ";
    cin >> num;
    
    while(num>1) 
    {
        num >>= 1;
        ++c;
    }
    cout << "is divisible by 2 " << c << " times" << endl;
}