/*
Write a C++ program that inputs a document and then outputs a bar-chart plot
of the frequencies of each alphabet character that appears in that document.
*/

#include<iostream>
#include<map>
#include<string>
#include<cctype>
#include<algorithm>
#include<iomanip>

using namespace std;

string get_input()
{
    cout << "Input text (blank line to finish):\n";

    string line, input;
    do {
        getline(cin, line);
        input += line;
    } while(line.size()!=0);

    return input;
}

string to_upper(string s)
{
    string s_toupper;
    for(auto it=s.begin(); it!=s.end(); it++) 
        s_toupper.push_back(toupper(*it));
    return s_toupper;
}

map<char, int> get_ocurrencies(string s)
{
    map<char, int> freq;

    // to upper case
    s = to_upper(s);    

    // keep only alpha chars
    string s_alpha;
    char c;
    for (auto it = s.begin(); it != s.end(); it++) 
        if ((c=*it) > 64 && c < 91)
            s_alpha.push_back(toupper(c));

    // sort string of alphas
    sort(s_alpha.begin(), s_alpha.end());

    // create map of frequencies
    auto it = s_alpha.begin();
    c = *it;    // get first char
    ++it;       // advance
    int n = 1;
    for(; it!=s_alpha.end(); ++it)
    {
        if(c==*it) ++n;
        else 
        {
            freq[c] = n;
            n = 1;
            c = *it;
        }
    }

    return freq;
}

void print_freq(map<char, int> freq)
{
    int m=0;    // total of ocurrencies
    for (auto it = freq.begin(); it != freq.end(); ++it)
        m += it->second;

    cout << "Frequencies:\n============\n";

    cout << setprecision(2) << fixed;
    
    for (auto it = freq.begin(); it != freq.end(); ++it)
    {
        cout << it->first << ": ";
        cout << "(n:" << it->second << "; f:" << (double)it->second / m << ") ";
        for(int i=0; i<it->second; ++i)
            cout << "#";
        cout << endl;
    }
}

int main()
{
    string input;
    map<char, int> freq;

    input = get_input();
    freq = get_ocurrencies(input);

    print_freq(freq);

    return EXIT_SUCCESS;
}
