/*
Write a set of C++ classes that can simulate an Internet application, where
one party, Alice, is periodically creating a set of packets that she wants to
send to Bob. The Internet process is continually checking if Alice has any
packets to send, and if so, it delivers them to Bob’s computer, and Bob is
periodically checking if his computer has a packet from Alice, and, if so,
he reads and deletes it.
*/

#include<iostream>

#include"Sender.h"
#include"Server.h"
#include"Receiver.h"

using namespace std;

int main()
{
    Sender alice;
    Server server(alice);
    Receiver bob;

    bob.set_connection(&server);

    cout << "How many packages atempts: ";

    int count;
    cin >> count;

    while(count-->0)
    {
        alice.send();
        bob.receive();
    }

    return EXIT_SUCCESS;
}