/*
 * RuntimeException.hpp
 * Class for generic runtime exceptions
 * */

#ifndef RuntimeException_hpp
#define RuntimeException_hpp

#include <string>

class RuntimeException
{
public:
    RuntimeException(const std::string& e)
        :err_(e) {}
    std::string getMessage() { return err_; }
private:
    std::string err_;
};

#endif

