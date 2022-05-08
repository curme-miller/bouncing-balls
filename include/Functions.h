#ifndef BALL_FUNCTION_H_
#define BALL_FUNCTION_H_

#include <iostream>
#include <easyx.h>
#include <graphics.h>

#define X_START_PLACE 100
#define Y_START_PLACE 63
#define X_START_PLACE_EARTH 350
#define Y_START_PLACE_EARTH 120
#define X_START_PLACE_GLASSY 400
#define Y_START_PLACE_GLASSY 240

#define X_START_SPEED 1
#define Y_START_SPEED 1
#define TOP_WALL 30
#define BUTTOM_WALL 270
#define LEFT_WALL 30
#define RIGHT_WALL 510
class ProjectImage
{
public:
    IMAGE background;
    IMAGE wall;
    IMAGE start;
    ~ProjectImage();
}; //调用图片库

class ProjectBall
{
public:
    ProjectBall(int xais,int yaxis,int xspeed,int yspeed);
    int xAxis, yAxis;
    int xSpeed, ySpeed;
    IMAGE ballBlack;
    IMAGE BlackWhite;
    ~ProjectBall();
};

void showBall(int xBallAxis, int yBallAxis, ProjectBall *ball);
void showWall();
void initAll();
void showGraphics();
void moveBall();
void soundPlay(std::string str);

#endif