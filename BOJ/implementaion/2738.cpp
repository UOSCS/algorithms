#include <iostream>

using namespace std;

void input(int N, int M, int arr[][100])
{
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> arr[i][j];
}

void calc(int N, int M, int A[][100], int B[][100])
{
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            A[i][j] += B[i][j];
}

void print_matrix(int N, int M, int arr[][100])
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
            cout << arr[i][j] << ' ';
        cout << '\n';
    }
}

int main(void)
{
    ios::sync_with_stdio(0);

    int N, M;
    int A[100][100], B[100][100];

    cin >> N >> M;

    input(N, M, A), input(N, M, B);

    calc(N, M, A, B);

    print_matrix(N, M, A);

    return 0;
}