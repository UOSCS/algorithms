#include <iostream>
#include <cstring>

using namespace std;

bool visited[100][100];
int N, mat[100][100];
int di[4] = {-1, 0, 1, 0}, dj[4] = {0, 1, 0, -1};

void dfs(int i, int j)
{
    visited[i][j] = true;

    for(int k = 0; k < 4; k++)
    {
        int new_i = i + di[k], new_j = j + dj[k];

        if((new_i >= 0 && new_i < N && new_j >= 0 && new_j < N) &&
           !visited[new_i][new_j])
            dfs(new_i, new_j);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);

    cin >> N;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> mat[i][j];

    int height = 0, ans = 0;

    while(true)
    {
        memset(visited, false, sizeof(visited));

        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                if(mat[i][j] <= height)
                    visited[i][j] = true;

        int cnt = 0;

        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                if(!visited[i][j])
                {
                    cnt++;
                    dfs(i, j);
                }

        if(!cnt)
            break;

        ans = max(ans, cnt);
        height++;
    }

    cout << ans;

    return 0;
}