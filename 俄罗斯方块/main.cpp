#include <iostream>
#include <thread>
#include "Terminal.h"
#include <chrono>
using namespace std::chrono_literals; // 时间
#include "utils.h"
#include "draw.h"

void init()
{
    
    tc::hide_cursor();
        
}
void loop()
{
    int i = 1;

    while (1)
    {
        tc::clean_screen();
        dw::window(1, 1, 9, 6, "Hold");
        dw::window(1, 10, 12, 22, "Tetriz");
        dw::window(7, 1, 9, 16, "Status");
        dw::window(19, 22, 8, 4, "Info");
        dw::window(1, 22, 8, 18, "Next");
        tc::move_to(10, 4);
        std::cout << "FPS:" << ut::fps();

        tc::move_to(i++%20, 10);
        tc::set_back_color(15);
        std::cout << "  ";
        tc::reset_color();
        std::cout << std::flush;
        std::this_thread::sleep_for(100ms);
    }
}
void exit()
{
    tc::show_cursor();
    tc::reset_color();
}
int main()
{
    init();
    loop();
    exit();
    return 0;
}