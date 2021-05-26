#include <iostream>

using namespace std;

int p_sum[100001];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M;

    cin >> N >> M;
    for(int i = 1; i <= N; i++)
    {
        int tmp;
        cin >> tmp;
        p_sum[i] = p_sum[i - 1] + tmp;
    }
    for(int i = 0; i < M; i++)
    {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        cout << p_sum[tmp2] - p_sum[tmp1 - 1] << '\n';
    }

    return 0;
}