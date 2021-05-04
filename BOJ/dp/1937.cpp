#include <iostream>
#include <algorithm>

using namespace std;

int N, arr[500][500], dp_cache[500][500];
int dr[4] = {-1, 1, 0, 0}, dc[4] = {0, 0, -1, 1};

int dfs(int r, int c)
{
    int ret = 0;

    for(int i = 0; i < 4; i++)
    {
        int new_r = r + dr[i], new_c = c + dc[i];
        if((new_r >= 0 && new_r < N && new_c >= 0 && new_c < N) &&
           (arr[new_r][new_c] > arr[r][c]))
        {
            int tmp;
            if(dp_cache[new_r][new_c])
                tmp = dp_cache[new_r][new_c];
            else
                tmp = dfs(new_r, new_c);
            ret = max(ret, tmp);
        }
    }

    return dp_cache[r][c] = 1 + ret;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int K = 0;

    cin >> N;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> arr[i][j];

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            K = max(K, dfs(i, j));

    cout << K << '\n';

    return 0;
}