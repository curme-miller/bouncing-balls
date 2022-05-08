#include <cstdio>
#include <cstdlib>
#include <include/Functions.h>


int main()
{
    initAll();
    while (1)
    {
        showGraphics();
        moveBall();
        soundStackWall();
        Sleep(100);
        system("cls");
    }
    return 0;
}
