/*
 * Scores.hpp
 * Class for satoring high game scores
 * */

#ifndef Scores_hpp
#define Scores_hpp

#include <string>
#include <ostream>
#include "IndexOutOfBounds.hpp"
#include "GameEntry.hpp"

class Scores
{
public:
    Scores(int max=10);
    ~Scores();
    void add(const GameEntry& e);
    GameEntry remove(int i);
    friend std::ostream& operator<<(std::ostream& os, Scores& s);
private:
    int numEntries_;
    int maxEntries_;
    GameEntry* entries_;
};

#endif 

