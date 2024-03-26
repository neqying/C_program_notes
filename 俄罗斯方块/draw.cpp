#include "draw.h"
#include <iostream>
#include "Terminal.h"
#include"utils.h"
namespace dw
{
    
    void window(int top, int left, int width, int height, std::string title)
    {
        for (int r = 0; r < height; r++)
        {
            tc::move_to(top + r, ut::b2c(left));
            for (int c = 0; c < width; c++)

            {
                if (r == 0) // 第一行
                {
                    if (c == 0) // 第一列
                    {
                        std::cout << " ┌";
                    }
                    else if (c == width - 1) // 最后一列
                    {
                        std::cout << "┐";
                    }
                    else
                    {
                        std::cout << "——";
                    }
                }
                else if (r == height - 1) // 最后一行
                {
                    if (c == 0) // 第一列
                    {
                        std::cout << " └";
                    }
                    else if (c == width - 1) // 最后一列
                    {
                        std::cout << "┘";
                    }
                    else
                    {
                        std::cout << "——";
                    }
                }
                else
                {
                    if (c == 0) // 第一列
                    {
                        std::cout << " │";
                    }
                    else if (c == width - 1)
                    {
                        std::cout << "│";
                    }
                    else
                    {
                        std::cout << "  ";
                    }
                }
            }
            // title
            tc::move_to(top, ut::b2c(left) + (width * 2 - title.length()) / 2);
            std::cout << title;
        }
    }
}
