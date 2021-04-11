#include <stdio.h>

int stair_num_cache[100][10], N;

int stair_num(int depth, int digit)
{
    if(depth == N - 1)
        return 1;
    else
    {
        if(!stair_num_cache[depth][digit])
        {
            int tmp1 = 0, tmp2 = 0;
            if(digit)
                tmp1 = stair_num(depth + 1, digit - 1) % 1000000000;
            if(digit < 9)
                tmp2 = stair_num(depth + 1, digit + 1) % 1000000000;
            stair_num_cache[depth][digit] += tmp1 + tmp2;
        }
        return stair_num_cache[depth][digit];
    }
}

int stair_num_start()
{
    int sum = 0;

    for(int i = 1; i < 10; i++, sum %= 1000000000)
        sum += stair_num(0, i) % 1000000000;

    return sum;
}

int main(void)
{
    scanf("%d", &N);

    printf("%d\n", stair_num_start());

    return 0;
}