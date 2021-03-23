#include <stdio.h>
#include <stdlib.h>

int candle(int [], int, int);
void build_list(int [], int);
int run_simulation(int [], int, int);

int main(void)
{
    int *A, n, k;

    printf("Enter 'n' and 'k' in order: ");
    scanf("%d %d", &n, &k);

    A = malloc(sizeof(int) * n);

    printf("The position of the last candle: %d\n", candle(A, n, k));

    return 0;
}

int candle(int A[], int n, int k)
{
    build_list(A, n);
    return run_simulation(A, n, k);
}

void build_list(int A[], int n)
{
    for(int i = 0; i < n; i++)
        A[i] = i + 1;
}

int run_simulation(int A[], int n, int k)
{
    int r = 0, N = n;

    while(n > 1)
    {
        int i = 0;
        while(i < k)
        {
            r = (r + 1) % N;
            if(A[r])
                i++;
        }
        A[r] = 0;
        n--;
        while(!A[r])
            r = (r + 1) % N;
    }
    return A[r];
}