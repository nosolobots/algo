#include<iostream>

#include"Receiver.h"

using namespace std;

void Receiver::set_connection(Server* server)
{
    server_ = server;
}

void Receiver::receive()
{
    server_->check();

    if (server_->available())
    {
        const char *data = server_->data();
        cout << "Receiving <-- " << data << endl;

        // drop packet
        delete data;
        data = nullptr;

        server_->reception_confirmed();
    }
}