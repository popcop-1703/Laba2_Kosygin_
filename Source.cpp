#include <iostream>
#include "graphics.h"
#pragma comment(lib,"graphics.lib")
int main()
{
    char pathtodriver[] = "";
    int driver, mode;
    driver = DETECT; /* автоопределение */
    mode = 0;
    initgraph(&driver, &mode, pathtodriver);

    int x0 = 100, y0 = 100, size = 200;
    int x1 = x0 + size, y1 = y0;
    int x2 = x1, y2 = y1 + size;
    int x3 = x2 - size, y3 = y2;

    // –исуем контур квадрата
    line(x0, y0, x1, y1);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x0, y0);

    // «аполн€ем квадрат заданными лини€ми
    line((x0+x1)/2, (y0+y1)/2, x3, (y0+y2)/2);
    line((x0 + x1) / 2, (y0 + y1) / 2, x2, y2);
    line((x0 + x1) / 2, (y0 + y1) / 2, (x3+x2)/2, (y3+y2)/2);
    line((x0 + x1) / 2, (y0 + y1) / 2, (x3+x2)/3, y3);
    getch();
    closegraph();
    return 0;
}