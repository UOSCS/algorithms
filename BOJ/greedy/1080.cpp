#include <iostream>

using namespace std;

int N, M;
char A[50][50], B[50][50];
bool is_different[50][50] = {false};

void change(int n, int m)
{
    for(int i = n; i < n + 3; i++)
    {
        if(i >= N)
            break;
        for(int j = m; j < m + 3; j++)
        {
            if(A[i][j] == '1')
                A[i][j] = '0';
            else
                A[i][j] = '1';
            if(A[i][j] == B[i][j])
                is_different[i][j] = false;
            else
                is_different[i][j] = true;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);

    int result = 0;

    cin >> N >> M;
    for(int n = 0; n < N; n++)
        for(int m = 0; m < M; m++)
            cin >> A[n][m];

    for(int n = 0; n < N; n++)
        for(int m = 0; m < M; m++)
        {
            cin >> B[n][m];
            if(A[n][m] != B[n][m])
                is_different[n][m] = true;
        }

    for(int i = 0; i < N; i++)
        for(int j = 0; j < M - 2; j++)
            if(is_different[i][j])
            {
                result++;
                change(i, j);
            }

    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            if(is_different[i][j])
            {
                cout << -1;
                return 0;
            }

    cout << result;

    return 0;
}