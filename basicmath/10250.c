#include <stdio.h>

int main(void)
{
    int T;

    scanf("%d", &T);
    int arr[T][3];

    for(int i = 0; i < T; i++)
        scanf("%d %d %d", arr[i], arr[i] + 1, arr[i] + 2);

    for(int i = 0, W = 0, H = 0; i < T; i++)
    {
        H = ((arr[i][2] % arr[i][0]) == 0) ? arr[i][0] : (arr[i][2] % arr[i][0]);
        W = (((float)arr[i][2] / arr[i][0]) == (arr[i][2] / arr[i][0])) ? (arr[i][2] / arr[i][0]) : (arr[i][2] / arr[i][0] + 1);
        printf("%d\n", H * 100 + W);
    }

    return 0;
}