/*
 * Scores.cpp
 * Class for satoring high game scores
 * */

#include "Scores.hpp"
#include "GameEntry.hpp"
//#include "IndexOutOfBounds.hpp"
#include <stdexcept>

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
    // get the ordered position for the new element
    int p=0;
    for(; p<numEntries_ && entries_[p].getScore()>=e.getScore(); p++);

    // if did not reach the end, insert the element
    if(p<maxEntries_) {
        // make room for the new entry if nedeed
        for(int i=numEntries_-1; i>=p; i--) 
            if((i+1)<maxEntries_)
                entries_[i+1]=entries_[i];
        // insert the new entry
        entries_[p] = e;
        if(numEntries_<maxEntries_)
            numEntries_++;
    }
}

GameEntry Scores::remove(int i)
{
    if(i<0 || i>=numEntries_)
        //throw IndexOutOfBounds("Invalid index");
        throw std::runtime_error("Invalid index");

    // get element
    GameEntry e = entries_[i];

    // move elements
    for(int p=i; p<numEntries_-1; p++)
        entries_[p] = entries_[p+1];

    // update entries count
    --numEntries_;

    return e;
}

std::ostream& operator<<(std::ostream& os, Scores& s)
{
    os << "{";
    for(int i=0; i<s.numEntries_; i++) 
        os << s.entries_[i];
    os << "}";
    return os;
}

