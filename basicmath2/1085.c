#include <stdio.h>

int main(void)
{
    int min;
    int x, y, w, h;
    int W, H;

    scanf("%d %d %d %d", &x, &y, &w, &h);

    min = (W = (((w - x) > x) ? x : (w - x))) > (H = (((h - y) > y) ? y : (h - y))) ? H : W;

    printf("%d\n", min);

    return 0;
}