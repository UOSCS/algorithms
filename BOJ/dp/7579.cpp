#include <iostream>

using namespace std;

int N, M, m[101], c[101], dp_cache[101][10001];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int result = 10000;

    cin >> N >> M;
    for(int i = 1; i <= N; i++)
        cin >> m[i];
    for(int i = 1; i <= N; i++)
        cin >> c[i];

    for(int i = 1; i <= N; i++)
        for(int j = 0; j <= N * 100; j++)
        {
            if(j >= c[i])
                dp_cache[i][j] = max(dp_cache[i - 1][j], dp_cache[i - 1][j - c[i]] + m[i]);
            else
                dp_cache[i][j] = dp_cache[i - 1][j];
            if(dp_cache[i][j] >= M)
                result = min(result, j);
        }
    cout << result << '\n';

    return 0;
}