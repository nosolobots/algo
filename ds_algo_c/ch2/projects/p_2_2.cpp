/*
Write a C++ program that “makes change.” Your program should input
two numbers, one that is a monetary amount charged and the other that is
a monetary amount given. It should return the number of each kind of bill
and coin to give back as change for the difference between the amounts
given and charged. The values assigned to the bills and coins can be based
on the monetary system of any government. Try to design your program
so that it returns the fewest number of bills and coins as possible.
*/

#include<iostream>
#include<map>

using namespace std;

int how_many(map<double, int>& units, int amount, int value)
{
    if (value>amount) return amount;

    int num_units = amount/value;
    units.insert({value/100, num_units});

    return amount - num_units*value;
}

int main()
{
    double charged;
    double given;

    cout << "Amount charged: ";
    cin >> charged;
    cout << "Amount given: ";
    cin >> given;

    if(given<charged)
    {
        cout << "The amount given is not sufficient" << endl;
    }
    else if(given==charged)
    {
        cout << "There's nothing to return" << endl;
    }
    else
    {
        int ret_amount = given*100.0 - charged*100.0;
        cout << "Amount returned: " << ret_amount/100.0 << endl;
        
        map<double, int> ret_units;
        double values[] {500.0, 200.0, 100, 50, 20, 10, 5, 2, 1, 0.5, 0.2, 0.1, 0.05, 0.02, 0.01};

        for(double val: values)
        {
            ret_amount = how_many(ret_units, ret_amount, val*100.0);
            if(ret_amount == 0) break;
        }

        for(auto it=ret_units.rbegin(); it!=ret_units.rend(); it++)
        {
            cout << it->first << " -> " << it->second << endl;
        }
    }
    
    return EXIT_SUCCESS;
}