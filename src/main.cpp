#include <cstdio>
#include <cstdlib>
#include <Functions.h>





int main()
{
    while (1)
    {



        if (x == top || x == bottom || y == left || y == right)
            printf("\a"); //遇边界提示声音
        x = x + speed_x;
        y = y + speed_y;


        // 输出小球前的空行
        for (i = 0; i <= bottom; i++)
        {
            for (j = 0; j <= right; j++)
            {
                if ((i == x) && (j == y))
                    printf("o"); //打印小球
                else if ((i == 0) || (i == bottom) || (j == 0) || (j == right)) //打印边界
                    printf("#");
                else
                    printf(" ");
            }
            printf("\n");
        }

        if ((x == top) || (x == bottom))
            speed_x = -speed_x;
        if ((y == left) || (y == right))
            speed_y = -speed_y;

    }
    return 0;
}
