#ifndef _SERVER_H_
#define _SERVER_H_

#include"Sender.h"

class Server
{
public:
    Server(Sender &sender);
    bool available() const;
    const char *data();
    void check();
    void reception_confirmed();

private:
    Sender &sender_;
    const char *data_;
    bool received_;
};

#endif