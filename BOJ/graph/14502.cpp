#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, arr[8][8], tmp_arr[8][8], cnt, tmp_cnt, ans;
int dn[4]= {-1, 1, 0, 0}, dm[4] = {0, 0, -1, 1};

void dfs(int n, int m)
{
    for(int i = 0; i < 4; i++)
    {
        int new_n = n + dn[i], new_m = m + dm[i];
        if((new_n >= 0 && new_n < N && new_m >= 0 && new_m < M) &&
           !tmp_arr[new_n][new_m])
        {
            tmp_cnt--;
            tmp_arr[new_n][new_m] = 2;
            dfs(new_n, new_m);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);

    vector<pair<int, int>> safe, virus;

    cin >> N >> M;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
            if(!arr[i][j])
            {
                cnt++;
                safe.push_back({ i, j });
            }
            else if(arr[i][j] == 2)
                virus.push_back({ i, j });
        }

    for(int i = 0; i < safe.size() - 2; i++)
        for(int j = i + 1; j < safe.size() - 1; j++)
            for(int k = j + 1; k < safe.size(); k++)
            {
                copy(*arr, *arr + 64, *tmp_arr);
                tmp_cnt = cnt;
                tmp_arr[safe[i].first][safe[i].second] = 1;
                tmp_arr[safe[j].first][safe[j].second] = 1;
                tmp_arr[safe[k].first][safe[k].second] = 1;
                for(int l = 0; l < virus.size(); l++)
                    dfs(virus[l].first, virus[l].second);
                ans = max(ans, tmp_cnt);
            }

    cout << ans - 3;

    return 0;
}