#include<iostream>
#include<thread>
#include"Terminal.h"
#include<chrono>
using namespace std::chrono_literals; //时间
#include"utils.h"


void init()
{
    tc::hide_cursor();
}
void loop()
{
    int i=1;

    while(1)
    {
        
        tc::clean_screen();
        tc::move_to(1,1);
        std::cout<<"FPS:"<<ut::fps();
        
        tc::move_to(i++,10);
        tc::set_back_color(15);
        std::cout<<"  ";
        tc::reset_color();
        std::cout<<std::flush;
        std::this_thread::sleep_for(500ms);    
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