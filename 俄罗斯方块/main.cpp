#include <iostream>
#include <thread>
#include "Terminal.h"
#include <chrono>
using namespace std::chrono_literals; // 时间
#include "utils.h"
#include "draw.h"
#include<termios.h>

char command;
char getch()
{
    char c;
    struct termios old,cur;
    tcgetattr(0,&cur);
    old=cur;
    cfmakeraw(&cur);
    tcsetattr(0,0,&cur);
    c=getchar();
    tcsetattr(0,0,&old);
    return c;
}
void key_event()
{
    while(1)
    {
        command=getch();
        if(command=='q')
        {
            break;
        }
    }
}
void init()
{
    
    tc::hide_cursor();
    std::thread t(key_event);
    t.detach();
        
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

        tc::move_to(i++%20, 30);
        tc::set_back_color(15);
        std::cout << "  ";
        tc::reset_color();
        if(command=='q')
        {
            break;
        }
        std::cout << std::flush;
        std::this_thread::sleep_for(100ms);
    }
}
void exit()
{
    tc::show_cursor();
    tc::reset_color();
    tc::clean_screen();
    tc::move_to(1,1);
    tc::set_fore_color(9);
    std::cout<<"Bye!"<<std::endl;
}
int main()
{
    init();
    loop();
    exit();
    return 0;
}