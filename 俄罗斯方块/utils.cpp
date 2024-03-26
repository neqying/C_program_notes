#include "utils.h"
#include "define.h"
namespace ut
{
    int fps()
    {
        static auto start = std::chrono::steady_clock::now(); // 稳定计时器
        auto end = start;
        static int frame_count = 0;
        static int fps = 0;

        end = std::chrono::steady_clock::now();
        frame_count++;
        if (end - start > 1s)
        {
            fps = frame_count;
            frame_count = 0;
            start = end;
        }
        return fps;
    }

    int b2c(int b)
    {
        return 2 * b - 1;
    }
}
