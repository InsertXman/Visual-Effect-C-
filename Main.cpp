#include <Windows.h>
#include <random>

HDC desk;
int x, y;

void effect(int sleep, int time) {
    for (int i = 0; i < time; i++) {
        PatBlt(desk, rand() % x, rand() % y, rand() % x, rand() % y, PATINVERT);
        Sleep(sleep);
    }
}

int main() {
    desk = GetDC(0);
    x = GetSystemMetrics(SM_CXSCREEN);
    y = GetSystemMetrics(SM_CYSCREEN);

    effect(100, 10);  // Example usage: sleep = 100ms, time = 10

    ReleaseDC(0, desk);
    return 0;
}
