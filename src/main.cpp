#include <iostream>
#include <string>
#include <print>
#include "header/terminal.h"

constexpr int Row = 3;

// anonymous namespace
namespace
{
     char Table[Row][Row] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'},
    };

    void printBoard();
    std::string checkWinner();
}


int main() {

    // starts with player 1
    int player = 1;

    std::cout << "Player 1 is 'X' and player 2 is 'O'\n";
    std::cout << "TIK TAC TOE:\n";

    while (true)
    {
        printBoard();

        int row;
        int col;
        std::print("Enter row you want to move in: ");
        std::cin >> row;
        std::print("Enter col you want to move in: ");
        std::cin >> col;

        if (Table[row][col] == 'X' || Table[row][col] == '0')
        {
            std::print("Invalid move try again\n");
            continue;
        }

        // plays the move and switch the current player
        if (player == 1)
        {
            Table[row][col] = 'X';
            player = 2;
        }
        else
        {
            Table[row][col] = 'O';
            player = 1;
        }

        if (std::string winner = checkWinner(); winner == "X" || winner == "O")
        {
            std::cout << TerminalControl::tc_color(0, 255, 0) << "Winner is " << winner << TerminalControl::tc_color(255, 255, 255) << std::endl;
            break;
        }
    }

    printBoard();
    std::cout << TerminalControl::tc_color(255, 0, 0) << "No Winner !! Draw !!" << TerminalControl::tc_color(255, 255, 255) << std::endl;
    return 0;
}

namespace
{
    void printBoard()
    {
        TerminalControl::clear_terminal();

        for (int row = 0; row < Row; row++){
            for (int col = 0; col < Row; col++){

                // checks for player and print with appropriate color
                if (Table[row][col] == 'X')
                {
                    std::cout << " " << TerminalControl::tc_color(255, 0, 0) << Table[row][col] << TerminalControl::tc_color(255, 255, 255)<<" ";
                }
                else if (Table[row][col] == 'O')
                {
                    std::cout << " " << TerminalControl::tc_color(0, 0, 255) << Table[row][col] << TerminalControl::tc_color(255, 255, 255)<<" ";
                }
                else
                {
                    std::cout << " " << Table[row][col] << " ";
                }

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
                std::print("-----------");
                std::cout << std:: endl;
            }
        }
    }

    std::string checkWinner()
    {

        // checking for winner in every row
        for(int row = 0; row < Row; row++)
        {
            if (Table[row][0] == Table[row][1] && Table[row][1] == Table[row][2])
            {
                return std::to_string(Table[row][0]);
            }
        }

        // checking for winner in every col
        for(int col = 0; col < Row; col++)
        {
            if (Table[0][col] == Table[1][col] && Table[1][col] == Table[2][col])
            {
                return std::to_string(Table[0][col]);
            }
        }

        // checking diagonally
        if (Table[0][0] == Table[1][1] && Table[1][1] == Table[2][2])
        {
            return std::to_string(Table[1][1]);
        }

        // checking diagonally
        if (Table[0][2] == Table[1][1] && Table[1][1] == Table[2][0])
        {
            return std::to_string(Table[1][1]);
        }

        return "No Winner";
    }
}
