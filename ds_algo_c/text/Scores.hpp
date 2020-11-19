/*
 * Scores.hpp
 * Class for satoring high game scores
 * */

#include <string>
#include "IndexOutOfBounds.hpp"
#include "GameEntry.hpp"

class Scores
{
public:
    Scores(int max=10);
    ~Scores();
    void add(const GameEntry& e);
    GameEntry remove(int i)
        throw(IndexOutOfBounds);

private:
    int numEntries_;
    int maxEntries_;
    GameEntry* entries_;
};
