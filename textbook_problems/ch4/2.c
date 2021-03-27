#include <stdio.h>
#include <stdlib.h>

int candle(int [], int, int);
void build_list(int [], int);
int run_simulation(int [], int, int);
void _remove(int [], int, int);

int main(void)
{
    int *A, n, k;

    printf("Enter 'n' and 'k' in order: ");
    scanf("%d %d", &n, &k);

    A = malloc(sizeof(int) * n);

    printf("The position of the last candle: %d\n", candle(A, n, k));

    free(A);

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
    for(int r = 0; n > 1; n--)
    {
        r = (r + k) % n;
        _remove(A, n, r);
    }
    return A[0];
}

void _remove(int A[], int n, int r)
{
    for(int i = r + 1; i < n; i++)
        A[i - 1] = A[i];
}