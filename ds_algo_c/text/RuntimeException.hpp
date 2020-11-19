/*
 * RuntimeException.hpp
 * Class for generic runtime exceptions
 * */

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

