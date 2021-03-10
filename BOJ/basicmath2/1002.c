#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    int T, **arr;

    scanf("%d", &T);

    arr = (int **)malloc(sizeof(int *) * T);
    for(int i = 0; i < T; i++)
        arr[i] = malloc(sizeof(int) * 6);

    for(int i = 0; i < T; i++)
        for(int j = 0; j < 6; j++)
            scanf("%d", arr[i] + j);

    for(int i = 0; i < T; i++)
    {
        double distance = sqrt(pow(arr[i][0] - arr[i][3], 2) + pow(arr[i][1] - arr[i][4], 2));
        double sum_of_r = arr[i][2] + arr[i][5];

        if(!distance)
            if(arr[i][2] == arr[i][5])
                printf("-1");
            else
                printf("0");
        else
            if(distance == sum_of_r)
                printf("1");
            else if(distance > sum_of_r)
                printf("0");
            else 
                if(distance == abs(arr[i][2] - arr[i][5]))
                    printf("1");
                else if(distance < abs(arr[i][2] - arr[i][5]))
                    printf("0");
                else
                    printf("2");
        printf("\n");
    }

    return 0;
}