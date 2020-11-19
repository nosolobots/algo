/*
 * GameEntry.cpp
 * Class representing a game entry
 * */
#include "GameEntry.hpp"

GameEntry::GameEntry(const std::string& n, int s)
    :name_(n), score_(s) {}

int GameEntry::getScore() const { return score_; }

std::string GameEntry::getName() const { return name_; }
