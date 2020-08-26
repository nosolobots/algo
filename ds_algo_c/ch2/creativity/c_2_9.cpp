/*
Write a C++ program that can input any polynomial in standard algebraic
notation and outputs the first derivative of that polynomial.
*/

#include<iostream>
#include<string>
#include<map>
#include<cstdlib>
#include<cmath>
#include<iomanip>

using namespace std;

class Polynom
{
public:
    Polynom(const string& spoly);

    friend ostream& operator<<(ostream& os, const Polynom& p);

private:
    map<int, double> factors_;
    bool process_entry(const string& spoly);
};

Polynom::Polynom(const string &spoly)
{
    if(!process_entry(spoly))
        throw "process entry error";
}

ostream& operator<<(ostream &os, const Polynom &p)
{
    bool first = true;

    for(auto it = p.factors_.rbegin(); it!=p.factors_.rend(); it++)
    {
        double coef = it->second;
        
        if(first && coef<0) 
            cout << "-";
        else if(!first)
        {
            cout << ((coef < 0) ? " - " : " + ");
        }

        cout << fixed << setprecision(2) << fabs(coef);
        cout << "*X^" << it->first;

        first = false;
    }

    return os;
}

bool Polynom::process_entry(const string &spoly)
{
    int pos = 0, pinit;
    int len, exp;
    double coef;
    string term;

    while((pos = spoly.find('X', pos))!=string::npos)
    {
        // get factor exponent
        len = 0;
        pinit = pos + 2;
        while ((pinit + len) < spoly.size() && spoly[pinit + len] != ' ')
            ++len;
        exp = stoi(spoly.substr(pinit, len));

        // get factor coefficient
        len = 0;
        pinit = pos - 2;
        while ((pinit - len)>=0 && spoly[pinit - len + 1] != ' ')
            ++len;
        coef = stod(spoly.substr(pinit - len + 1, len));
        if ((pinit - len) > 0 && spoly[pinit - len]=='-')
            coef *= -1;

        factors_.insert({exp, coef});
        ++pos;
    }

    return (factors_.size()!=0);
}

int main()
{
    string poly;

    cout << "Enter polynom (ex: 4*X^3 + 2.5*X^1 - 11.3*X^0): ";
    getline(cin, poly);

    Polynom p(poly);
    cout << endl << p << endl;

    return EXIT_SUCCESS;
}

