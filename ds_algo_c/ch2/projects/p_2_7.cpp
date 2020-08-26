/*
Write a C++ program that inputs a list of words separated by whitespace,
and outputs how many times each word appears in the list. You need not
worry about efficiency at this point, however, as this topic is something
that will be addressed later in this book.
*/

#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

int main()
{
    map<string, int> words;
    map<string, int>::iterator it;
    string input;

    cout << "Input text (ctrl-D to end): " << endl;
    
    while(cin>>input)
    {
        if((it=words.find(input))!=words.end())
            ++words[input];
        else
            words[input] = 1;
    }

    for(it=words.begin(); it!=words.end(); ++it)
    {
        cout << it->first << ": " << it->second << endl;
    }

    return EXIT_SUCCESS;
}
