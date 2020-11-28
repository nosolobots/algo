/*
 * TicTacToe
 *
 * class: Player
 * ver: 0.1
 * */

#ifndef Player_hpp
#define Player_hpp

#include <iostream>
#include <string>
#include <vector>

class Player
{
public:
    Player(std::string& name);
    ~Player();
    bool removePiece(int row, int col);
    void addPiece(int row, int col);
    const std::string& getName() const;
    const std::vector<int*>& getPieces() const;
    friend std::ostream& operator<<(std::ostream& os, Player& p);

private:
    std::string name_;  
    std::vector<int*> pieces_;
};

#endif 
