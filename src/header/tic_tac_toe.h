//
// Created by kevin on 8/28/26.
//

#ifndef TERMINAL_GAME_TIC_TAC_TOE_H
#define TERMINAL_GAME_TIC_TAC_TOE_H

#include <string>

class Tic_Tac_Toe
{
public:
    static constexpr int Row = 3;

    char Table[Row][Row] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'},
    };

    int currentPlayer = 1;

    Tic_Tac_Toe();
    void printBoard() const;
    [[nodiscard]] bool check_winner() const;
    [[nodiscard]] bool check_draw() const;

};

#endif //TERMINAL_GAME_TIC_TAC_TOE_H
