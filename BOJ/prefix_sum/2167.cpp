#include <iostream>

using namespace std;

int p_sum[301][301];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M, K;

    cin >> N >> M;
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
        {
            int tmp;
            cin >> tmp;
            p_sum[i][j] = (j == 1 ? p_sum[i - 1][M] : p_sum[i][j - 1]) + tmp;
        }

    cin >> K;
    for(int a = 0; a < K; a++)
    {
        int i, j, x, y, sum = 0;
        cin >> i >> j >> x >> y;
        for(int b = i; b <= x; b++)
            sum += p_sum[b][y] - (j == 1 ? p_sum[b - 1][M] : p_sum[b][j - 1]);
        cout << sum << '\n';
    }

    return 0;
}