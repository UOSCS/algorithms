#include <iostream>

using namespace std;

int N, mat[20][20], answer = 400;

void calc()
{
    int tot_sum = 0;

    for(int j = 0; j < N; j++)
    {
        int col_sum = 0;
        for(int i = 0; i < N; i++)
            col_sum += mat[i][j];
        if(col_sum > N >> 1)
            tot_sum += N - col_sum;
        else
            tot_sum += col_sum;
    }
    answer = min(answer, tot_sum);
}

void dfs(int depth)
{
    if(depth == N)
    {
        calc();
        return;
    }
    dfs(depth + 1);
    for(int j = 0; j < N; j++)
        if(mat[depth][j]) mat[depth][j] = 0;
        else mat[depth][j] = 1;
    dfs(depth + 1);
}

int main(void)
{
    ios::sync_with_stdio(0);

    cin >> N;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
        {
            char tmp;
            cin >> tmp;
            if(tmp == 'T') mat[i][j] = 1;
        }

    dfs(0);

    cout << answer;

    return 0;
}