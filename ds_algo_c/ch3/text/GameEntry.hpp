/*
 * GameEntry.hpp
 * Class representing a game entry
 * */

#ifndef GameEntry_hpp
#define GameEntry_hpp

#include <ostream>
#include <string>

class GameEntry
{
public:
    GameEntry(const std::string& n="", int s=0);
    std::string getName() const;
    int getScore() const;
    friend std::ostream& operator<<(std::ostream& os, const GameEntry& g);

private:
    std::string name_;
    int score_;
};

#endif
