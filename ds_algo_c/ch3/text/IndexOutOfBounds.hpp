/*
 * IndexOutOfBounds.hpp
 * Class for generated index out of bounds exceptions
 * */

#ifndef IndexOutOfBounds_hpp
#define IndexOutOfBounds_hpp

#include "RuntimeException.hpp"
#include <string>

class IndexOutOfBounds: public RuntimeException {
public:
    IndexOutOfBounds(const std::string& e)
        :RuntimeException(e)
        {}
};

#endif
