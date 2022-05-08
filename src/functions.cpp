#include <include/Functions.h>
#include <graphics.h>
#include <easyx.h>
#include <iostream>

void initAll()
{

}

void showGraphics()
{
    for (int i = 0; i <= bottom; i++)
    {
        for (int j = 0; j <= right; j++)
        {
            if ((i == x) && (j == y))
                std::cout<<"o";                                                //打印小球
            else if ((i == 0) || (i == bottom) || (j == 0) || (j == right)) //打印边界
                std::cout<<"#";
            else
                std::cout<<" ";
        }
        std::cout<<std::endl;
    }
}

void moveBall()
{
    x = x + speed_x;
    y = y + speed_y;
    if ((x == top) || (x == bottom))
        speed_x = -speed_x;
    if ((y == left) || (y == right))
        speed_y = -speed_y;
}

void soundStackWall()
{
    if (x == top || x == bottom || y == left || y == right)
        std::cout << "\a"; //遇边界提示声音
}
