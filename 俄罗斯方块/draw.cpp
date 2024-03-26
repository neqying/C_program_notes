#include "draw.h"
#include <iostream>
#include "Terminal.h"
namespace dw
{
    inline int block2col(int b)
    {
        return 2 * b - 1;
    }
    void window(int top, int left, int width, int height, std::string title)
    {
        for (int r = 0; r < height; r++)
        {
            tc::move_to(top + r, block2col(left));
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
            tc::move_to(top, block2col(left) + (width * 2 - title.length()) / 2);
            std::cout << title;
        }
    }
}
