#include <stdio.h>

int main(void)
{
    int A, B, C;
    int arr[10] = {0};

    scanf("%d %d %d", &A, &B, &C);

    for(int multi = A * B * C; multi != 0; multi /= 10)
    {
        switch(multi % 10)
        {
            case 0:
                arr[0]++;
                break;
            case 1:
                arr[1]++;
                break;
            case 2:
                arr[2]++;
                break;
            case 3:
                arr[3]++;
                break;
            case 4:
                arr[4]++;
                break;
            case 5:
                arr[5]++;
                break;
            case 6:
                arr[6]++;
                break;
            case 7:
                arr[7]++;
                break;
            case 8:
                arr[8]++;
                break;
            case 9:
                arr[9]++;
                break;
        }
    }
    for(int i = 0; i < 10; i++)
        printf("%d\n", arr[i]);

    return 0;
}