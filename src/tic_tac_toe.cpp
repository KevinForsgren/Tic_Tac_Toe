//
// Created by kevin on 8/28/26.
//

#include "header/tic_tac_toe.h"
#include <iostream>
#include <print>

Tic_Tac_Toe::Tic_Tac_Toe()
= default;

void Tic_Tac_Toe::printBoard() const
{

    for (int row = 0; row < Row; row++){
        for (int col = 0; col < Row; col++){
            std::cout << " " << Table[row][col] << " ";

            // nothing just styling
            if (col == 0 || col == 1)
            {
                std::cout << "|";
            }
        }
        std::cout << std:: endl;

        // board styling
        if (row == 1 || row == 0)
        {
            std::print("-----------\n");
        }
    }
}

bool Tic_Tac_Toe::check_winner() const
{


    // checking for winner in every row
    for(const auto row : Table)
    {
        if (row[0] == row[1] && row[1] == row[2])
        {
            std::print("Winner is {}\n", row[0]);
            return true;
        }
    }

    // checking for winner in every col
    for(int col = 0; col < Row; col++)
    {
        if (Table[0][col] == Table[1][col] && Table[1][col] == Table[2][col])
        {
            std::print("Winner is {}\n", Table[0][col]);
            return true;
        }
    }

    // checking diagonally
    if (Table[0][0] == Table[1][1] && Table[1][1] == Table[2][2])
    {
        std::print("Winner is {}\n", Table[1][1]);
        return true;
    }

    // checking diagonally
    if (Table[0][2] == Table[1][1] && Table[1][1] == Table[2][0])
    {
        std::print("Winner is {}\n", Table[1][1]);
        return true;
    }

    return false;
}

bool Tic_Tac_Toe::check_draw() const
{

    for (const auto& row : Table)
    {
        for (const char cell : row)
        {
            if (cell != 'X' || cell != 'O')
            {
                return false;
            }
        }
    }
    return true; // All cells are filled with either X or O means draw
}
