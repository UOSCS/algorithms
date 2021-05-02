#include <stdio.h>

int w_cache[101][101][101];
int bias = 50;

int w(int a, int b, int c)
{
    if(a <= 0 || b <= 0 || c <= 0)
        return 1;
    else if(a > 20 || b > 20 || c > 20)
    {
        if(!w_cache[a + bias][b + bias][c + bias])
            w_cache[a + bias][b + bias][c + bias] = w(20, 20, 20);
        return w_cache[a + bias][b + bias][c + bias];
    }
    else if(a < b && b < c)
    {
        if(!w_cache[a + bias][b + bias][c + bias - 1])
            w_cache[a + bias][b + bias][c + bias - 1] = w(a, b, c - 1);
        if(!w_cache[a + bias][b + bias - 1][c + bias - 1])
            w_cache[a + bias][b + bias - 1][c + bias - 1] = w(a, b - 1, c - 1);
        if(!w_cache[a + bias][b + bias - 1][c + bias])
            w_cache[a + bias][b + bias - 1][c + bias] = w(a, b - 1, c);
        return w_cache[a + bias][b + bias][c + bias - 1] + w_cache[a + bias][b + bias - 1][c + bias - 1] - w_cache[a + bias][b + bias - 1][c + bias];
    }
    else
    {
        if(!w_cache[a + bias - 1][b + bias][c + bias])
            w_cache[a + bias - 1][b + bias][c + bias] = w(a - 1, b, c);
        if(!w_cache[a + bias - 1][b + bias - 1][c + bias])
            w_cache[a + bias - 1][b + bias - 1][c + bias] = w(a - 1, b - 1, c);
        if(!w_cache[a + bias - 1][b + bias][c + bias - 1])
            w_cache[a + bias - 1][b + bias][c + bias - 1] = w(a - 1, b, c - 1);
        if(!w_cache[a + bias - 1][b + bias - 1][c + bias - 1])
            w_cache[a + bias - 1][b + bias - 1][c + bias - 1] = w(a - 1, b - 1, c - 1);
        return w_cache[a + bias - 1][b + bias][c + bias] + w_cache[a + bias - 1][b + bias - 1][c + bias] + w_cache[a + bias - 1][b + bias][c + bias - 1] - w_cache[a + bias - 1][b + bias - 1][c + bias - 1];
    }
}

int main(void)
{
    for(int a, b, c; scanf("%d %d %d", &a, &b, &c); )
        if(a == -1 && b == -1 && c == -1)
            break;
        else
            printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));

    return 0;
}