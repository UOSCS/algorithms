#include <iostream>

using namespace std;

int R, C, ans;
int dr[4] = {-1, 0, 1, 0}, dc[4] = {0, 1, 0, -1};
char mat[20][20];
bool visited[20][20], alpha[26];

void dfs(int depth, int r, int c)
{
    int alphabet = mat[r][c] - 'A';

    ans = max(depth, ans);
    alpha[alphabet] = true;
    visited[r][c] = true;
    for(int i = 0; i < 4; i++)
    {
        int new_r = r + dr[i], new_c = c + dc[i];
        if((new_r >= 0 && new_r < R && new_c >= 0 && new_c < C) &&
           !visited[new_r][new_c] && !alpha[mat[new_r][new_c] - 'A'])
            dfs(depth + 1, new_r, new_c);
    }
    alpha[alphabet] = false;
    visited[r][c] = false;
}

int main(void)
{
    ios::sync_with_stdio(0);

    cin >> R >> C;
    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++)
            cin >> mat[i][j];

    dfs(1, 0, 0);

    cout << ans;

    return 0;
}