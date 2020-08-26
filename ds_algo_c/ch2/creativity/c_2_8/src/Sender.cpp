#include<iostream>
#include<ctime>
#include<cstdlib>

#include"Sender.h"

using namespace std;

Sender::Sender() : data_(nullptr),
                   sended_(false)
{
    srand(time(0));
}

Sender::~Sender()
{
    delete data_;
}

bool Sender::available() const
{
    return sended_;
}

void Sender::send()
{
    if (!sended_)
    {
        if (rand() % 10 == 0)
        {
            // create new package
            int len = rand() % 11 + 5; // [5, 15]
            data_ = new char[len + 1];

            for (int i = 0; i < len; i++)
            {
                data_[i] = rand() % 26 + 65; // [65, 90]
            }
            data_[len] = '\0';

            cout << "Sending --> " << data_ << endl;

            sended_ = true;
        }
    }
}

void Sender::reception_confirmed()
{
    sended_ = false;
    data_ = nullptr;
}

const char *Sender::data() { return data_; }