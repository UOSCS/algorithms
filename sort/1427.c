#include <stdio.h>
#include <string.h>

#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

void selection_sort(char *arr, int N)
{
    for(int i = 0, tmp; i < N - 1; i++)
    {
        int max = i;

        for(int j = i + 1; j < N; j++)
            if(arr[j] > arr[max])
                max = j;
        SWAP(arr[i], arr[max], tmp);
    }
}

int main(void)
{
    char arr[11];

    scanf("%10s", arr);

    selection_sort(arr, strlen(arr));

    for(int i = 0; i < strlen(arr); i++)
        printf("%c", arr[i]);

    return 0;
}