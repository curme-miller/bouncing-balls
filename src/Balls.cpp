#include <cstdlib>
#include <include/Functions.h>
#include <windows.h>

extern ProjectBall Ball;
extern ProjectBall earthBall;
extern ProjectBall glassyBall;
extern ProjectImage Images;
int main()
{
    initAll();
    soundPlay("timi");
    while (1)
    {
        moveBall();
        showBall(Ball.xAxis, Ball.yAxis, &Ball);
        showBall(earthBall.xAxis, earthBall.yAxis, &earthBall);
        showBall(glassyBall.xAxis,glassyBall.yAxis,&glassyBall);
        FlushBatchDraw();
        Sleep(5);
        putimage(0, 0, &Images.background);
        showWall();

    }
    return 0;
}
