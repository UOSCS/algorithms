#include <iostream>

using namespace std;

int N, M, dp_cache[1001][1001];
char arr[1001][1001];

int dp()
{
    int ret = 0;

    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
            if(arr[i][j] == '1')
            {
                dp_cache[i][j] = min(min(dp_cache[i - 1][j], dp_cache[i][j - 1]), dp_cache[i - 1][j - 1]) + 1;
                ret = max(ret, dp_cache[i][j]);
            }

    return ret * ret;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
            cin >> arr[i][j];

    cout << dp() << '\n';

    return 0;
}