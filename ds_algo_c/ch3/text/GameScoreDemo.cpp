/*
 * GameScoresDemo.cpp
 * */

#include <cstdlib>
#include <exception>
#include <iostream>
#include "GameEntry.hpp"
#include "IndexOutOfBounds.hpp"
#include "Scores.hpp"

int main(int argc, char** argv)
{
    Scores table(5);

    GameEntry g1("GAL", 32459);
    GameEntry g2("Pepe", 25000);

    std::cout << "g1--> " << g1 << std::endl;
    table.add(g2);
    table.add(g1);
    table.add(GameEntry("Manu", 28500));
    table.add(GameEntry("Lolo", 38000));
    table.add(GameEntry("John", 15000));
    table.add(GameEntry("Genji", 29200));

    std::cout << table << std::endl;

    std::cout << "Removing index 1..." << std::endl;
    GameEntry gr = table.remove(1);
    std::cout << gr << std::endl;

    std::cout << table << std::endl;

    std::cout << "Removing index 999..." << std::endl;
    try {
        gr = table.remove(999);
        std::cout << gr << std::endl;
    }
    //catch(IndexOutOfBounds& e) {
    catch(std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return EXIT_SUCCESS;
}
