#include "Collection.hpp"

#include <cstdlib>
#include <exception>
#include <iostream>

int main() {
    Collection<std::string> c{4};

    try {
        c.insert("En");
        c.insert("un");
        c.insert("lugar");
        c.insert("de");
        c.insert("La");
        c.insert("Mancha");
    }
    catch(std::exception& e) {
        std::cout<< e.what() << std::endl;
    }
   
    auto c2{c};
    auto c3 = c;
    Collection<std::string> c4;
    c4 = c;

    std::cout << "c remove...\n";
    while(!c.isEmpty())
        std::cout << c.remove() << std::endl;

    std::cout << "c2 remove...\n";
    while(!c2.isEmpty())
        std::cout << c2.remove() << std::endl;

    std::cout << "c3 remove...\n";
    while(!c3.isEmpty())
        std::cout << c3.remove() << std::endl;

    auto c5 = std::move(c4);
    Collection<std::string> c6;
    c6 = std::move(c5);

    std::cout << "c4 remove...\n";
    while(!c4.isEmpty())
        std::cout << c4.remove() << std::endl;

    std::cout << "c5 remove...\n";
    while(!c5.isEmpty())
        std::cout << c5.remove() << std::endl;
   
    std::cout << "contains \"Mancha\"? " << c6.contains("Mancha") << std::endl;
    std::cout << "contains \"lugar\"? " << c6.contains("lugar") << std::endl;

    std::cout << "c6 remove...\n";
    while(!c6.isEmpty())
        std::cout << c6.remove() << std::endl;

    std::cout << "contains \"lugar\"? " << c6.contains("lugar") << std::endl;

    return EXIT_SUCCESS;
}
