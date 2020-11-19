/*
 * GameEntry.hpp
 * Class representing a game entry
 * */

#include <string>

class GameEntry
{
public:
    GameEntry(const std::string& n="", int s=0);
    std::string getName() const;
    int getScore() const;

private:
    std::string name_;
    int score_;
};
