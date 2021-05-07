#include <iostream>

using namespace std;

int N, M, arr[1000][1000], is_visited[1000][1000], dp_cache[1000][1000][3];
int dn[3] = {0, 0, 1}, dm[3] = {-1, 1, 0};

int dp(int n, int m, int direction)
{
    if(dp_cache[n][m][direction] <= 100000000)
        return dp_cache[n][m][direction];

    int max_value = -100000000;

    is_visited[n][m] = 1;
    for(int i = 0; i < 3; i++)
    {
        int new_n = n + dn[i], new_m = m + dm[i];
        if((new_n >= 0 && new_n < N && new_m >= 0 && new_m < M) && 
           !is_visited[new_n][new_m])
            max_value = max(max_value, dp(new_n, new_m, i));
    }
    is_visited[n][m] = 0;

    return dp_cache[n][m][direction] = max_value + arr[n][m];
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> arr[i][j];

    fill(**dp_cache, **dp_cache + 3000000, 100000001);
    dp_cache[N - 1][M - 1][0] = dp_cache[N - 1][M - 1][1] = dp_cache[N - 1][M - 1][2] = arr[N - 1][M - 1];

    cout << dp(0, 0, 1) << '\n';

    return 0;
}