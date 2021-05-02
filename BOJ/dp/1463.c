#include <stdio.h>

int make_one_cache[1000001];

int make_one(int n)
{
    if(n == 1)
        return 0;
    else
    {
        if(!make_one_cache[n])
        {
            int tmp1 = (1 << 20), tmp2 = (1 << 20), tmp3, tmp4;
            if(!(n % 3))
                tmp1 = make_one(n / 3);
            if(!(n % 2))
                tmp2 = make_one(n >> 1);
            tmp3 = make_one(n - 1);
            make_one_cache[n] = (tmp3 > (tmp4 = (tmp1 > tmp2 ? tmp2 : tmp1)) ? tmp4 : tmp3) + 1;
        }
        return make_one_cache[n];
    }
}

int main(void)
{
    int N;

    scanf("%d", &N);

    printf("%d\n", make_one(N));

    return 0;
}