#ifndef _SENDER_H_
#define _SENDER_H_

class Sender
{
public:
    Sender();
    ~Sender();
    bool available() const;
    const char *data();
    void reception_confirmed();
    void send();

private:
    char *data_;
    bool sended_;
};

#endif
