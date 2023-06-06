#include <iostream>
#include <vector>
#include <cmath>

#include "graphics.h"
#pragma comment(lib,"graphics.lib")
using namespace std;
const double M_PI = 3.14159265358979323846;

void bezier(const vector<int>& x, const vector<int>& y)
{
    int n = x.size() - 1;
    float t, b;
    int px = x[0], py = y[0];
    for (t = 0; t <= 1; t += 0.001) { // Приращение параметра
        b = 0;
        for (int i = 0; i <= n; i++) {
            b += pow((1 - t), n - i) * pow(t, i) * x[i] * pow((1 - t), n - i) * pow(t, i) * y[i];
        }
        putpixel(px, py, RED);
        px = b * cos(t * 2 * M_PI) + x[0];
        py = b * sin(t * 2 * M_PI) + y[0];
    }
}

int main()
{

    char pathtodriver[] = "";
    int driver, mode;
    driver = DETECT; /* автоопределение */
    mode = 0;
    initgraph(&driver, &mode, pathtodriver);

    // рисуем квадрат
    int x[] = { 100, 150, 200, 200, 200, 150, 100, 100 };
    int y[] = { 100, 100, 100, 150, 200, 200, 200, 150 };
    int n = 8;

    // Чертим исходный квадрат
    for (int i = 0; i < n - 1; i++)
        line(x[i], y[i], x[i + 1], y[i + 1]);
    line(x[n - 1], y[n - 1], x[0], y[0]);

    // Определяем новые точки для кривой Би-сплайна
    int new_x[] = { 120, 130, 170, 180 };
    int new_y[] = { 120, 190, 190, 120 };
    int new_n = 4;

    // Чертим кривую Би-сплайна
    setcolor(RED);
    for (int i = 0; i < new_n - 3; i++)
        bezier(new_x + i, new_y + i);
    
    getch();
    closegraph();
    return 0;
}