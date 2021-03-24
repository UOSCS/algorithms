#include <stdio.h>

typedef long long ll;

int main(void)
{
    int N, prices[100000], road_distances[100000];
    ll result = 0;

    scanf("%d", &N);
    for(int i = 0; i < N - 1; i++)
        scanf("%d", road_distances + i);
    for(int i = 0; i < N; i++)
        scanf("%d", prices + i);
    
    for(int i = 0, j; i < N - 1; i = j)
    {
        ll sum = road_distances[i];
        for(j = i + 1; (j < N - 1) && (prices[i] <= prices[j]); j++)
            sum += road_distances[j];
        result += sum * prices[i];
    }
    printf("%lld\n", result);

    return 0;
}