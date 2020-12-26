/*
 * Word Puzzle
 *
 * The input consists of a two-dimensional array of letters and a list of words.
 * The object is to find the words in the puzzle. These words may be horizontal,
 * vertical, or diagonal in any direction. As an example, the puzzle shown
 * contains the words this, two, fat, and that.
 *
 *      1 2 3 4
 *    1 t h i s
 *    2 w a t s
 *    3 o a h g
 *    4 f g d t
 *
 * The word "this" begins at row 1, column 1, or (1,1), and extends to (1,4);
 * "two" goes from (1,1) to (3,1); "fat" goes from (4,1) to (2,3); and "that"
 * goes from (4,4) to (1,1).
 *
 * Input
 * It begins with two numbers, indicating the size (rows, cols) of the array
 * Then, the array of letters, one line per row
 * Finally, the list of words, one per line
 *
 * Output
 * For each word in the list, the program must indicate, in the same order, the
 * position of the first and last letters of the word
 *
 * Example
 *
 *      Input   Output
 *
 *      4 4     this (1,1) -> (1,4)
 *      this    two (1,1) -> (3,1)
 *      wats    fat (4,1) -> (2,3)
 *      oahg    that (4,4) -> (1,1)
 *      fgdt
 *      this
 *      two
 *      fat
 *      that
 * */

#include <cstdlib>
#include <iostream>
#include <string>

#include "Matrix.hpp"

struct Coord {
    int r;
    int c;
};

enum class Dir { UP, DOWN, LEFT, RIGHT, DIAG_RD, DIAG_RU, DIAG_LD, DIAG_LU };

bool checkDir(Matrix<char>& m, std::string w, Coord& first, Coord& last,
              Dir d) {
    bool in_word = true;

    Coord next;
    next.r = first.r;
    next.c = first.c;

    for (int i = 1; i < w.length() && in_word; i++) {
        switch (d) {
            case Dir::UP:
                --next.r;
                break;
            case Dir::DOWN:
                ++next.r;
                break;
            case Dir::LEFT:
                --next.c;
                break;
            case Dir::RIGHT:
                ++next.c;
                break;
            case Dir::DIAG_RD:
                ++next.c;
                ++next.r;
                break;
            case Dir::DIAG_RU:
                ++next.c;
                --next.r;
                break;
            case Dir::DIAG_LD:
                --next.c;
                ++next.r;
                break;
            case Dir::DIAG_LU:
                --next.c;
                --next.r;
                break;
        }
        if (next.c < 0 || next.c > m.cols() - 1 || next.r < 0 ||
            next.r > m.rows() - 1 || m[next.r][next.c] != w[i])
            in_word = false;
    }

    if (in_word) {
        last.r = next.r;
        last.c = next.c;
    }

    return in_word;
}

void findWord(Matrix<char>& m, std::string w, Coord& first, Coord& last) {
    std::vector<Coord> first_alt;  // alternative positions for first char
    char ch = w[0];
    for (int i = 0; i < m.rows(); i++)
        for (int j = 0; j < m.cols(); j++) {
            if (m[i][j] == ch) first_alt.push_back({i, j});
        }

    // try every initial position
    bool founded = false;
    for (auto p : first_alt) {
        first.r = p.r;
        first.c = p.c;
        if (checkDir(m, w, first, last, Dir::UP))
            break;
        else if (checkDir(m, w, first, last, Dir::DOWN))
            break;
        else if (checkDir(m, w, first, last, Dir::RIGHT))
            break;
        else if (checkDir(m, w, first, last, Dir::LEFT))
            break;
        else if (checkDir(m, w, first, last, Dir::DIAG_LD))
            break;
        else if (checkDir(m, w, first, last, Dir::DIAG_LU))
            break;
        else if (checkDir(m, w, first, last, Dir::DIAG_RD))
            break;
        else if (checkDir(m, w, first, last, Dir::DIAG_RU))
            break;
    }
}

int main() {
    int r, c;

    // create matrix
    std::cin >> r >> c;
    Matrix<char> m(r, c);

    // load matrix
    char ch;
    std::cin.get(ch);  // skip endl
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) std::cin.get(m[i][j]);
        std::cin.get(ch);  // skip endl
    }

    // process words
    std::string w;
    Coord first, last;
    while (std::cin >> w) {
        findWord(m, w, first, last);
        std::cout << w << " (" << first.r + 1 << "," << first.c + 1;
        std::cout << ") -> (" << last.r + 1 << "," << last.c + 1 << ")\n";
    }

    return EXIT_SUCCESS;
}
