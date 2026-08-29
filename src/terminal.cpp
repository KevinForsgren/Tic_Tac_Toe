#include "header/terminal.h"
#include <iostream>
#include <string>

#if defined(_WIN32)
#define WIN32_LEAN_AND_CLEAN
#define VC_EXTRALEAN
#include <Windows.h>
#elif defined(__linux__)
#include <sys/ioctl.h>
#include <unistd.h>
#endif

/**
 * return a ansi color code with the provided RGB values
 * @param R
 * @param G
 * @param B
 * @return
 */
std::string TerminalControl::tc_color(int const R, int const G, int const B)
{
    return "\033[38;2;" + std::to_string(R) + ";" + std::to_string(G) + ";" + std::to_string(B) + "m";
}

/**
 * return a ansi background color code with the provided RGB values
 * @param R
 * @param G
 * @param B
 * @return
 */
std::string TerminalControl::tc_background(const int R, const int G, const int B)
{
    return "\033[48;2;" + std::to_string(R) + ";" + std::to_string(G) + ";" + std::to_string(B) + "m";
}

void TerminalControl::get_terminal_size(int* row, int* col)
{
    #if defined(_WIN32)
        CONSOLE_SCREEN_BUFFER_INFO csbi;

        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        *row = (int)(csbi.srWindow.Right - csbi.srWindow.Left + 1);
        *col = (int)(csbi.srWindow.Bottom - csbi.srWindow.Top + 1);

    #elif defined(__linux__)
        winsize w{};

        ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
        *row = static_cast<int>(w.ws_row);
        *col = static_cast<int>(w.ws_col);

    #endif // windows/linux
}

/**
 * move cursor to the specific location in the terminal
 * @param X x-axis
 * @param Y y-axis
 * @return void
 */
void TerminalControl::move_cursor(const int X, const int Y)
{
    std::cout << "\033[" << X << ';' << Y << 'H';
}


/**
 * create a new terminal window
 * @return void
 */
void TerminalControl::new_window()
{
    std::cout << "\033[?1049h";
}


/**
 * return to the main terminal window
 * @return void
 */
void TerminalControl::main_window()
{
    std::cout << "\033[?1049l";
}

/**
 * clear current content of the terminal
 * @return void
 */
void TerminalControl::clear_terminal()
{
    std::cout << "\033[2J";
}

/**
 * hide the cursor
 * @return void
 */
void TerminalControl::hide_cursor()
{
    std::cout << "\033[?25l";
}

/**
 * show the cursor
 * @return void
 */
void TerminalControl::show_cursor()
{
    std::cout << "\033[?25h";
}
