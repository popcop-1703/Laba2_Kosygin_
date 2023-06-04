#include <iostream>
#include <graphics.h> 

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x0 = 100, y0 = 100, size = 200;
    int x1 = x0 + size, y1 = y0;
    int x2 = x1, y2 = y1 + size;
    int x3 = x2 - size, y3 = y2;

    // Рисуем контур квадрата
    line(x0, y0, x1, y1);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x0, y0);

    // Заполняем квадрат заданными линиями
    for (int i = x0; i <= x2; i += 10) {
        line(i, y0, x2, y2 - (x2 - i));
        line(i, y1, x3, y3 + (x2 - i));
    }

    getch();
    closegraph();
    return 0;
}