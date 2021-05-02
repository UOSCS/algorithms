#include <iostream>
#include <cstring>

using namespace std;

int N, M, arr[500][500], dp_cache[500][500];
int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};

int dfs(int row, int col)
{
    if(row < 0 || row >= N || col < 0 || col >= M)
        return 0;
    if(dp_cache[row][col] != -1)
        return dp_cache[row][col];
    if(!row && !col)
        return 1;

    dp_cache[row][col] = 0;
    for(int i = 0, next_row, next_col; i < 4; i++)
    {
        next_row = row + dr[i]; next_col = col + dc[i];
        if(arr[next_row][next_col] > arr[row][col])
            dp_cache[row][col] += dfs(next_row, next_col);
    }
    return dp_cache[row][col];
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> arr[i][j];

    memset(dp_cache, -1, sizeof(dp_cache));
    cout << dfs(N - 1, M - 1) << '\n';

    return 0;
}