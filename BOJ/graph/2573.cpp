#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, M, mat[300][300], tmp_mat[300][300], cnt;
int dn[4] = {-1, 0, 1, 0}, dm[4] = {0, 1, 0, -1};
bool visited[300][300];
vector<pair<int, int>> v;

void dfs(int n, int m)
{
    cnt++;
    visited[n][m] = true;
    for(int k = 0; k < 4; k++)
    {
        int new_n = n + dn[k], new_m = m + dm[k];
        
        if(mat[new_n][new_m] && !visited[new_n][new_m])
            dfs(new_n, new_m);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);

    cin >> N >> M;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
        {
            cin >> mat[i][j];
            if(mat[i][j])
                v.push_back({ i, j });
        }

    int ans = 0;
    while(true)
    {
        ans++;
        for(int i = 0; i < v.size(); i++)
        {
            int n = v[i].first, m = v[i].second, tmp_height;

            tmp_height = mat[n][m];
            for(int j = 0; j < 4; j++)
            {
                int new_n = n + dn[j], new_m = m + dm[j];

                if(!mat[new_n][new_m])
                    tmp_height--;
            }

            if(tmp_height < 0)
                tmp_height = 0;

            if(!tmp_height)
            {
                v.erase(v.begin() + i);
                i--;
            }

            tmp_mat[n][m] = tmp_height;
        }

        if(v.empty())
        {
            cout << 0;
            break;
        }

        copy(*tmp_mat, *tmp_mat + 90000, *mat);

        memset(visited, false, sizeof(visited));
        cnt = 0;
        dfs(v[0].first, v[0].second);

        if(cnt < v.size())
        {
            cout << ans;
            break;
        }
    }

    return 0;
}