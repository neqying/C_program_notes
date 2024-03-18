#include "Terminal.h"
#include<iostream>
#define CSI "\033["
void tc::move_to(int row, int col)
{
    //move to cursor=/033[row;colH
    std::cout<<CSI<<row<<";"<<col<<"H";
}

void tc::set_fore_color(int id)
{
    //set foreground_color=/033[38;5;idm
    std::cout<<CSI<<"38;5;"<<id<<"m";
}

void tc::set_back_color(int id)
{
    //set background_color=/033[48;5idm
    std::cout<<CSI<<"48;5;"<<id<<"m";
}

void tc::clean_screen()
{
    std::cout<<CSI<<"2J";
}

void tc::reset_color()
{
    std::cout<<CSI<<"0m";
}

void tc::hide_cursor()
{
    std::cout<<CSI<<"?25l";
}

void tc::show_cursor()
{
    std::cout<<CSI<<"?25h";
}
