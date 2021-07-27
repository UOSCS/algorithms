#include <iostream>
#include <cstring>

using namespace std;

int N;
int di[4] = {-1, 0, 1, 0}, dj[4] = {0, 1, 0, -1};
char mat[100][100];
bool visited[100][100];

void dfs(bool color_weak, int i, int j)
{
    visited[i][j] = true;
    for(int k = 0; k < 4; k++)
    {
        int new_i = i + di[k], new_j = j + dj[k];
        if(new_i < N && new_i >= 0 && new_j < N && new_j >= 0 && !visited[new_i][new_j])
        {
            if((color_weak && (mat[i][j] != 'B') && (mat[new_i][new_j] != 'B')) ||
               (mat[i][j] == mat[new_i][new_j]))
                dfs(color_weak, new_i, new_j);
        }
    }
}

int calc(bool color_weak)
{
    int ans = 0;

    memset(visited, false, sizeof(visited));

    for(int i = 0; i < N; i++)
        for(int j = 0; j< N; j++)
            if(!visited[i][j])
            {
                dfs(color_weak, i, j);
                ans++;
            }

    return ans;
}

int main(void)
{
    ios::sync_with_stdio(0);

    cin >> N;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> mat[i][j];

    cout << calc(false) << ' ';
    cout << calc(true) << '\n';

    return 0;
}