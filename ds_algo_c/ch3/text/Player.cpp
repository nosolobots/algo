#include "Player.hpp"

Player::Player(std::string& name)
    : name_(name)
{}

Player::~Player()
{
    for(int i=0; i<pieces_.size(); i++)
        delete[] pieces_[i];
    pieces_.clear();
}

bool Player::removePiece(int row, int col) 
{
    // find piece
    int p;
    for(p=0; p<pieces_.size(); p++)
        if(pieces_[p][0]==row && pieces_[p][1]==col) 
            break;

    if(p<pieces_.size()) {
        delete[] pieces_[p];
        pieces_.erase(pieces_.begin() + p);

        return true;
    }

    return false;   // didn't find the piece
}

void Player::addPiece(int row, int col)
{
    int* p = new int[2];
    p[0] = row;
    p[1] = col;
    pieces_.push_back(p);
}

const std::string& Player::getName() const
{
    return name_;
}

const std::vector<int*>& Player::getPieces() const
{
    return pieces_;
}

std::ostream& operator<<(std::ostream& os, Player& p)
{
    os << "{player: \"" << p.name_ << "\",\n";
    os << " pieces: [";
    for(int i=0; i<p.pieces_.size(); i++) {
        os << "\n  [" << p.pieces_[i][0] << ", " << p.pieces_[i][1] << "]";
    }
    os << "]}\n";

    return os;
}
