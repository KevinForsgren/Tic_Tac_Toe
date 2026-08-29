#include <iostream>
#include "header/terminal.h"
#include "header/tic_tac_toe.h"
#include <string>
#include <print>

int main()
{
    // creates a new terminal window
    TerminalControl::new_window();
    TerminalControl::hide_cursor();
    Tic_Tac_Toe board;

    while (true)
    {
        TerminalControl::clear_terminal();
        TerminalControl::move_cursor(2,1);
        board.printBoard();

        /*int grid;

        std::cout << "Enter the cell no to move in That cell";
        std::print("Player {}: ", board.currentPlayer);
        std::cin >> grid;*/


        int row;
        int col;
        std::print("Enter row you want to move in: ");
        std::cin >> row;
        std::print("Enter col you want to move in: ");
        std::cin >> col;


        if (board.Table[row][col] == 'X' || board.Table[row][col] == '0')
        {
        }

        // plays the move and switch the current player
        if (board.currentPlayer == 1)
        {
            board.Table[row][col] = 'X';
            board.currentPlayer = 2;
        }
        else
        {
            board.Table[row][col] = 'O';
            board.currentPlayer = 1;
        }

        // implement check winner below
        if (board.check_winner())
        {
            break;
        }

        // checks if draw happen
        if (board.check_draw())
        {
            std::cout << "Game is Draw no one wins\n";
            break;
        }
    }

    std::string garbage;
    std::cout << "Press any key to exit: ";
    std::cin >> garbage;
    TerminalControl::main_window();

    return 0;
}
