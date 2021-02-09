#include <stdio.h>
#include <stdlib.h>

int calc_people(int k, int n)
{
    if(k == 0)
        return n;
    else if(n == 1)
        return 1;
    else
        return calc_people(k, n - 1) + calc_people(k - 1, n);
}

int main(void)
{
    int T, k, n;
    int *ans;

    scanf("%d", &T);
    ans = malloc(sizeof(int) * T);

    for(int i = 0; i < T; i++)
    {
        scanf("%d %d", &k, &n);

        ans[i] = calc_people(k, n);

        printf("%d\n", ans[i]);
    }
}