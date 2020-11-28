/*
 * TicTacToe
 *
 * class: TTTGame
 * */

#ifndef TTTGame_hpp
#define TTTGame_hpp

#include <iostream>
#include <string>
#include <vector>
#include "Player.hpp"

class TTTGame
{
public:
    TTTGame(std::string& p1_name, std::string& p2_name);
    ~TTTGame();
    bool checkWinner(int id);
    bool checkCellFree(int row, int col);
    bool checkCanMove(int id);
    bool removePiece(int id, int row, int col);
    void placePiece(int id, int row, int col);
    const std::string& getPlayerName(int id) const;

    friend std::ostream& operator<<(std::ostream& os, TTTGame& b);

private:
    static constexpr int MAX_PIECES = 3;
    static constexpr char chP1 = 'X';
    static constexpr char chP2 = 'O';

    Player* players_[2];
};

#endif 
