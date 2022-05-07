#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <graphics.h>
#include <easyx.h>





int main()
{
    int i, j;
    int x = 0;
    int y = 5;

    int speed_x = 1;
    int speed_y = 1;
    int left = 0;
    int right = 20;
    int top = 0;
    int bottom = 10;

    while (1)
    {
        Sleep(10);
        if (x == top || x == bottom || y == left || y == right)
            printf("\a"); //遇边界提示声音
        x = x + speed_x;
        y = y + speed_y;

        system("cls"); // 清屏函数
        // 输出小球前的空行
        for (i = 0; i <= bottom; i++)
        {
            for (j = 0; j <= right; j++)
            {
                if ((i == x) && (j == y))
                {
                    printf("o"); //打印小球
                }
                else if ((i == 0) || (i == bottom) || (j == 0) || (j == right)) //打印边界
                {
                    printf("#");
                }
                else
                    printf(" ");
            }
            printf("\n");
        }

        if ((x == top) || (x == bottom))
            speed_x = -speed_x;
        if ((y == left) || (y == right))
            speed_y = -speed_y;
        system("color 1f");
    }
    return 0;
}
