#include "TTTGame.hpp"

TTTGame::TTTGame(std::string& p1_name, std::string& p2_name)
{
    players_[0] = new Player(p1_name);
    players_[1] = new Player(p2_name);
}

TTTGame::~TTTGame()
{
    delete players_[0];
    delete players_[1];
}

const std::string& TTTGame::getPlayerName(int id) const
{
    return players_[id]->getName();
}

bool TTTGame::checkWinner(int id)
{
    std::vector<int*> pieces = players_[id]->getPieces();
    
    if (pieces.size()<MAX_PIECES)
        return false; // there're still pieces to be placed

    // check horizontally
    if(pieces[0][0]==pieces[1][0] && pieces[1][0]==pieces[2][0]) 
        return true;
    
    // check vertically
    if(pieces[0][1]==pieces[1][1] && pieces[1][1]==pieces[2][1]) 
        return true;

    // check main diagonal
    if(pieces[0][0]==pieces[0][1] && pieces[1][0]==pieces[1][1] && pieces[2][0]==pieces[2][1])
        return true;

    // check secondary diagonal
    for(int i=0; i<MAX_PIECES; i++)
        if((pieces[i][0] + pieces[i][1])!=2)
            return false;

    return true;

}

bool TTTGame::checkCellFree(int row, int col)
{
    for(int i=0; i<2; i++) {
        std::vector<int*> v = players_[i]->getPieces();
        for(int p=0; p<v.size(); p++) 
            if(v[p][0]==row && v[p][1]==col)
                return false;
    }

    return true;
}

bool TTTGame::checkCanMove(int id)
{
    return (players_[id]->getPieces().size()<MAX_PIECES);
}

bool TTTGame::removePiece(int id, int row, int col)
{
    return players_[id]->removePiece(row, col);
}

void TTTGame::placePiece(int id, int row, int col)
{
    players_[id]->addPiece(row, col);
}

std::ostream& operator<<(std::ostream& os, TTTGame& b)
{
    os << "\nPlayer 1: " << b.players_[0]->getName() << " [" << TTTGame::chP1 << "]" << std::endl;
    os << "Player 2: " << b.players_[1]->getName() << " [" << TTTGame::chP2 << "]" << std::endl;

    // create board
    int board[3][3];
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            board[i][j] = ' ';

    // place player1 pieces
    std::vector<int*> v = b.players_[0]->getPieces();
    for(int i=0; i<v.size(); i++)
        board[v[i][0]][v[i][1]] = TTTGame::chP1;

    // place player2 pieces
    v = b.players_[1]->getPieces();
    for(int i=0; i<v.size(); i++)
        board[v[i][0]][v[i][1]] = TTTGame::chP2;
   
    // print board
    os << "\nBoard:\n";

    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            os << " " << (char)board[i][j] << " ";
            if(j<2)
                os << "|";
        }
        os << std::endl;
        if(i<2)
            os << "--- --- ---" << std::endl;
    }
    os << std::endl;

    return os;
}
