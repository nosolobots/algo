/*
 * Scores.cpp
 * Class for satoring high game scores
 * */

#include "Scores.hpp"

Scores::Scores(int max)
{
    maxEntries_ = max;
    numEntries_ = 0;
    entries_ = new GameEntry[maxEntries_];
}

Scores::~Scores()
{
    if(numEntries_)
        delete [] entries_;
}

void Scores::add(const GameEntry& e) 
{
    if(numEntries_ < maxEntries_)
        entries_[numEntries_++] = e;
}


