#include <iostream>
#include <easyx.h>
#include <graphics.h>
#include <include/Functions.h>
#include <mmsystem.h>

ProjectImage Images;
ProjectBall Ball(X_START_PLACE, Y_START_PLACE, X_START_SPEED, Y_START_SPEED);
ProjectBall earthBall(X_START_PLACE_EARTH, Y_START_PLACE_EARTH, X_START_SPEED, Y_START_SPEED);
ProjectBall glassyBall(X_START_PLACE_GLASSY, Y_START_PLACE_GLASSY, -X_START_SPEED, -Y_START_SPEED);

void showWall()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 18; j++)
        {
            if (i == 0 || i == 9)
                putimage(30 * j, 30 * i, &Images.wall);
            else
            {
                putimage(0, 30 * i, &Images.wall);
                putimage(510, 30 * i, &Images.wall);
            }
        }
    }
}

void showBall(int xBallAxis, int yBallAxis, ProjectBall *ball)
{
    xBallAxis -= 15;
    yBallAxis -= 15;
    putimage(xBallAxis, yBallAxis, &ball->BlackWhite, SRCAND);
    putimage(xBallAxis, yBallAxis, &ball->ballBlack, SRCPAINT);
}

void initAll()
{
    initgraph(540, 300);
    BeginBatchDraw();
    loadimage(&Images.background, TEXT("../images/BackGround.png"), 540, 300);
    loadimage(&Images.start, TEXT("../images/318.png"), 540, 300);
    loadimage(&Images.wall, TEXT("../images/Wall.png"), 30, 30);
    loadimage(&Ball.ballBlack, TEXT("../images/BallBlack.png"), 30, 30);
    loadimage(&Ball.BlackWhite, TEXT("../images/BlackWhite.png"), 30, 30);
    loadimage(&earthBall.ballBlack, TEXT("../images/EarthBlack.png"), 30, 30);
    loadimage(&earthBall.BlackWhite, TEXT("../images/EarthBlackWhite.png"), 30, 30);
    loadimage(&glassyBall.ballBlack, TEXT("../images/glassyBlack.png"), 30, 30);
    loadimage(&glassyBall.BlackWhite, TEXT("../images/glassyBlackWhite.png"), 30, 30);
    putimage(0, 0, &Images.background);
    showWall();
    showBall(Ball.xAxis, Ball.yAxis, &Ball);
    showBall(earthBall.xAxis, earthBall.yAxis, &earthBall);
    showBall(glassyBall.xAxis, glassyBall.yAxis, &glassyBall);
    putimage(0, 0, &Images.start);
    FlushBatchDraw();
}

void showGraphics()
{
}

void moveBall()
{
    bool isPlay = false;
    Ball.xAxis += Ball.xSpeed;
    Ball.yAxis += Ball.ySpeed;
    earthBall.xAxis += earthBall.xSpeed;
    earthBall.yAxis += earthBall.ySpeed;
    glassyBall.xAxis += glassyBall.xSpeed;
    glassyBall.yAxis += glassyBall.ySpeed;

    if (Ball.xAxis - 15 == LEFT_WALL || Ball.xAxis + 15 == RIGHT_WALL)
    {
        Ball.xSpeed = -Ball.xSpeed;
        isPlay=true;
    }
    if (Ball.yAxis - 15 == TOP_WALL || Ball.yAxis + 15 == BUTTOM_WALL)
    {
        Ball.ySpeed = -Ball.ySpeed;
        isPlay=true;
    }

    if (earthBall.xAxis - 15 == LEFT_WALL || earthBall.xAxis + 15 == RIGHT_WALL)
    {
        earthBall.xSpeed = -earthBall.xSpeed;
        isPlay=true;
    }

    if (earthBall.yAxis - 15 == TOP_WALL || earthBall.yAxis + 15 == BUTTOM_WALL)
    {
        earthBall.ySpeed = -earthBall.ySpeed;
        isPlay=true;
    }

    if (glassyBall.xAxis - 15 == LEFT_WALL || glassyBall.xAxis + 15 == RIGHT_WALL)
    {
        glassyBall.xSpeed = -glassyBall.xSpeed;
        isPlay=true;
    }

    if (glassyBall.yAxis - 15 == TOP_WALL || glassyBall.yAxis + 15 == BUTTOM_WALL)
    {
        glassyBall.ySpeed = -glassyBall.ySpeed;
        isPlay=true;
    }
    if (isPlay)
    {
        soundPlay("stack");
        isPlay = false;
    }
}

void soundPlay(std::string str)
{
    if (str == "timi")
    {
        mciSendString(TEXT("open ../music/timi.mp3 alias timi"), 0, 0, 0);
        mciSendString(TEXT("play timi"), 0, 0, 0);
        Sleep(1 * 1000);
        mciSendString(TEXT("close timi"), 0, 0, 0);
    }
    // else if (str == "stack")
    // {
        
    //     mciSendString(TEXT("play rain"), 0, 0, 0);
    //     Sleep(0.75 * 1000);
    //     mciSendString(TEXT("close rain"), 0, 0, 0);
    // }
}

ProjectBall::ProjectBall(int xais, int yaxis, int xspeed, int yspeed)
{
    this->xAxis = xais;
    this->yAxis = yaxis;
    this->xSpeed = xspeed;
    this->ySpeed = yspeed;
}
ProjectBall::~ProjectBall()
{
}
ProjectImage::~ProjectImage()
{
}