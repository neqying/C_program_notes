#pragma once

namespace gm
{

    extern char getch();

    void key_event();
    void start_listener();
    void command_quit();
    void command_rotate();
    void command_left();
    void command_right();
    void command_down();
}