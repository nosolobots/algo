/*
 * TicTacToe (human to human)
 * ver: 0.1
 * */

#include <cstdlib>
#include <iostream>
#include <string>
#include "TTTGame.hpp"

std::string get_player_name(int who)
{
    std::string name;
    std::cout << "Player " << who << " name: ";
    std::cin >> name;
    
    return name;
}

void remove_piece(TTTGame& ttt, int pl)
{
    int r, c;

    do {
        std::cout << "Pick a piece to remove (row, col): ";
        std::cin >> r >> c;
    } while(!ttt.removePiece(pl, r, c));        
}

void next_move(TTTGame& ttt, int pl)
{
    std::cout << "\nPlayer " << ttt.getPlayerName(pl) << " moves...\n";

    if(!ttt.checkCanMove(pl)) {
        remove_piece(ttt, pl);
    }

    int r, c;
    do {
        std::cout << "Select position to move (row, col): ";
        std::cin >> r >> c;
    } while(r<0 || r>2 || c <0 || c>2 || !ttt.checkCellFree(r, c));

    ttt.placePiece(pl, r, c);
}

bool check_win(TTTGame& ttt, int pl)
{
    return ttt.checkWinner(pl);
}

int main()
{
    bool winner = false;
    int cur_pl = 0;

    // Create game
    std::string name1 = get_player_name(1);
    std::string name2 = get_player_name(2);
    TTTGame ttt(name1, name2);

    // main loop
    while(!winner) {
        // display board
        std::cout << ttt;

        // process the next player move
        next_move(ttt, cur_pl);

        // check if it was a winner move
        winner = check_win(ttt, cur_pl);

        // switch player
        cur_pl ^= 1;
    }

    std::cout << "Player " << ttt.getPlayerName(cur_pl^1) << " wins!!" << std::endl;

    return EXIT_SUCCESS;
}

