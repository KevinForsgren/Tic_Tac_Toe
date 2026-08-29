#ifndef SOMETHING_TERMINAL_H
#define SOMETHING_TERMINAL_H
#include <string>



class TerminalControl
{
    public:
        static void move_cursor(int, int);
        static void new_window();
        static void main_window();
        static void clear_terminal();
        static void hide_cursor();
        static void show_cursor();
        static std::string tc_color(int, int, int);
        static std::string tc_background(int, int, int);
        static void get_terminal_size(int* row, int* col);
};


#endif //SOMETHING_TERMINAL_H
