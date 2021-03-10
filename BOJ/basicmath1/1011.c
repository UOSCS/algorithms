#include <stdio.h>
#include <math.h>

int main(void)
{
    int T, x, y;

    scanf("%d", &T);

    for(int i = 0, tmp, distance, sqrt_of_distance; i < T; i++)
    {
        scanf("%d %d", &x, &y);
        distance = y - x;
        sqrt_of_distance = sqrt(distance);
        tmp = sqrt_of_distance * sqrt_of_distance;

        if(tmp == distance)
            printf("%d\n", 2 * sqrt_of_distance - 1);
        else if((tmp < distance) && (distance <= (tmp + sqrt_of_distance)))
            printf("%d\n", 2 * sqrt_of_distance);
        else
            printf("%d\n", 2 * sqrt_of_distance + 1);
    }

    return 0;
}