#include "game.h"
namespace gm
{
    bool running;
    int row, col;
    void init()
    {
        running = true;
        row = 2;
        col = 15;
    }
    void rotate()
    {
        row--;
    }
    void left()
    {
        col--;
    }
    void right()
    {
        col++;
    }
    void down()
    {
        row++;
    }
    void quit()
    {
        running = false;
    }

}
