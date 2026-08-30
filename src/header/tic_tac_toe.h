//
// Created by kevin on 8/28/26.
//

#ifndef TERMINAL_GAME_TIC_TAC_TOE_H
#define TERMINAL_GAME_TIC_TAC_TOE_H

#include <string>
struct Cell
{
    int id;
    int row;
    int col;
};

class Tic_Tac_Toe
{

public:

    Cell cells[9] = {
        {.id = 1, .row = 0, .col = 0,},
        {.id = 2, .row = 0, .col = 1},
        {.id = 3, .row = 0, .col = 2},
        {.id = 4, .row = 1, .col = 0},
        {.id = 5, .row = 1, .col = 1},
        {.id = 6, .row = 1, .col = 2},
        {.id = 7, .row = 2, .col = 0},
        {.id = 8, .row = 2, .col = 1},
        {.id = 9, .row = 2, .col = 2}
    };

    static constexpr int Row = 3;
    char Table[Row][Row] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'},
    };

    int currentPlayer = 1;
    std::string Winner;

    Tic_Tac_Toe();
    void printBoard() const;
    [[nodiscard]] char check_winner() const;
    [[nodiscard]] bool check_draw() const;

};

#endif //TERMINAL_GAME_TIC_TAC_TOE_H
