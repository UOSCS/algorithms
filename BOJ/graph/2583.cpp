#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int M, N, cnt;
int di[4] = {-1, 0, 1, 0}, dj[4] = {0, 1, 0, -1};
bool mat[100][100];

void dfs(int i, int j)
{
    mat[i][j] = true;
    cnt++;

    for(int k = 0; k < 4; k++)
    {
        int new_i = i + di[k], new_j = j + dj[k];

        if((new_i < M && new_i >= 0 && new_j < N && new_j >= 0) &&
           !mat[new_i][new_j])
            dfs(new_i, new_j);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);

    int K, ans = 0;
    vector<int> v;

    cin >> M >> N >> K;
    for(int i = 0; i < K; i++)
    {
        int x1, y1, x2, y2;

        cin >> x1 >> y1 >> x2 >> y2;

        for(int y = y1; y < y2; y++)
            for(int x = x1; x < x2; x++)
                mat[y][x] = true;
    }

    for(int i = 0; i < M; i++)
        for(int j = 0; j < N; j++)
            if(!mat[i][j])
            {
                ans++;
                cnt = 0;
                dfs(i, j);
                v.push_back(cnt);
            }
    sort(v.begin(), v.end());

    cout << ans << '\n';
    for(int i : v)
        cout << i << ' ';

    return 0;
}