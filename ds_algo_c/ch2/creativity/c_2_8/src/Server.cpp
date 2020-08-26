#include<iostream>

#include"Server.h"

Server::Server(Sender &sender) : sender_(sender),
                         data_(nullptr),
                         received_(false) {}
void Server::check()
{
    if (sender_.available())
    {
        data_ = sender_.data();
        received_ = false;
    }
}

void Server::reception_confirmed()
{
    received_ = true;
    data_ = nullptr;
    sender_.reception_confirmed();
}

bool Server::available() const { return (data_ != nullptr); }

const char *Server::data() { return data_; }