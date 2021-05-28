#include <iostream>
#include <cstring>

using namespace std;

int N, arr[16][16], dp[16][16][3];
int dxdy[3][2] = { { 0, 1 }, { 1, 0 }, { 1, 1 } };

int dfs(int x, int y, int state)
{
    if(dp[x][y][state] >= 0)
        return dp[x][y][state];
    if(x == N - 1 && y == N - 1)
        return 1;

    int ret = 0;

    for(int i = 0; i < 3; i++)
    {
        int next_x = x + dxdy[i][0], next_y = y + dxdy[i][1];
        if(next_x >= N || next_y >= N || arr[next_x][next_y])
            continue;
        if(i == 2 && (arr[x + 1][y] || arr[x][y + 1]))
            continue;
        if((!state && i == 1) || (state == 1 && !i))
            continue;
        ret += dfs(next_x, next_y, i);
    }

    return dp[x][y][state] = ret;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> arr[i][j];

    memset(dp, -1, sizeof(dp));
    cout << dfs(0, 1, 0);

    return 0;
}