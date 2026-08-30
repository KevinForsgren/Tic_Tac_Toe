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

    std::string Winner;

    while (true)
    {
        TerminalControl::clear_terminal();
        TerminalControl::move_cursor(2,1);
        board.printBoard();

        int grid;

        std::cout << "\nEnter the cell no to move in That cell\n";
        std::print("Player {}: ", board.currentPlayer);
        std::cin >> grid;
        std::cout << std::endl;


        for (const auto& [id, row, col] : board.cells)
        {
            if (id == grid)
            {
                // check if player already moved here
                if (board.Table[row][col] == 'X' || board.Table[row][col] == 'O')
                {
                    break;
                }

                if (board.currentPlayer == 1)
                {
                    board.Table[row][col] = 'X';
                    board.currentPlayer = 2;
                    break;
                }

                board.Table[row][col] = 'O';
                board.currentPlayer = 1;
                break;
            }


        }

        // implement check winner below
        // if anything except \0 then this block will execute
        if (board.check_winner())
        {
            Winner = board.check_winner();
            break;
        }

        // checks if draw happen
        if (board.check_draw())
        {
            Winner = "Draw";
            break;
        }

    }

    TerminalControl::main_window();
    TerminalControl::show_cursor();
    if (Winner == "Draw")
    {
        std::cout << TerminalControl::tc_color(0, 255, 0) << "Draw || No one wins " << Winner << TerminalControl::tc_color(255, 255, 255) << std::endl;
    }
    else
    {
        std::cout << TerminalControl::tc_color(0, 255, 0) << "Winner is " << Winner << TerminalControl::tc_color(255, 255, 255) << std::endl;
    }

    return 0;
}
