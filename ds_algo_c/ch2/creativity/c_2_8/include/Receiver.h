#ifndef _RECEIVER_H_
#define _RECEIVER_H_

#include"Server.h"

class Receiver
{
public:
    void set_connection(Server* server);
    void receive();

private:
    Server* server_;
};

#endif